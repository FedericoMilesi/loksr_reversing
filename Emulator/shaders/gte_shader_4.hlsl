#ifdef D3D9
	#define SV_TARGET COLOR0
	#define ARG_VPOS ,float2 coord : VPOS
	#define FRAG_COORD coord.xy
#else
	#define FRAG_COORD In.v_position.xy
	#define ARG_VPOS
#endif

struct VS_INPUT {
#ifdef D3D9
	float4 a_position : POSITION;
	float4 a_texcoord : TEXCOORD0;
	float4 a_color    : COLOR0;
#else
	int4 a_position   : POSITION;
	uint4 a_texcoord  : TEXCOORD0;
	float4 a_color    : COLOR0;
#endif	
};

struct VS_OUTPUT {
#ifdef D3D9
	float4 v_position  : POSITION;
#else
	float4 v_position  : SV_POSITION;
#endif
	float4 v_texcoord  : TEXCOORD0;
	float4 v_color     : TEXCOORD1;
	float4 v_page_clut : TEXCOORD2;
};

#ifdef VERTEX
	float4x4 Projection : register(c0);

	VS_OUTPUT main(VS_INPUT In) {
		VS_OUTPUT Out;
		Out.v_texcoord     = In.a_texcoord;
		Out.v_color        = In.a_color;
		Out.v_color.xyz   *= In.a_texcoord.z;
		Out.v_page_clut.x  = frac (In.a_position.z / 16.0) * 1024.0;
		Out.v_page_clut.y  = floor(In.a_position.z / 16.0) * 256.0;
		Out.v_page_clut.z  = frac (In.a_position.w / 64.0);
		Out.v_page_clut.w  = floor(In.a_position.w / 64.0) / 512.0;
		Out.v_position     = mul(Projection, float4(In.a_position.xy, 0.0, 1.0));
		return Out;
	}
#else
#ifdef D3D9
	SamplerState s_texture : register(s0);
#else
	SamplerState samplerState : register(s0);
	Texture2D s_texture : register(t0);
#endif

	float4 main(VS_OUTPUT In ARG_VPOS) : SV_TARGET {
		float2 uv = (In.v_texcoord.xy * float2(0.25, 1.0) + In.v_page_clut.xy) * float2(1.0 / 1024.0, 1.0 / 512.0);
#ifdef D3D9
		float2 comp = tex2D(s_texture, uv).ra;
#else
		float2 comp = s_texture.Sample(samplerState, uv).rg;
#endif
		uint index = int(frac(In.v_texcoord.x / 4.0 + 0.0001) * 4.0);

		float v = comp[index / 2] * (255.0 / 16.0);
		float f = floor(v);

		float2 c = float2( (v - f) * 16.0, f );

		float2 clut_pos = In.v_page_clut.zw;
		clut_pos.x += lerp(c[0], c[1], frac(float(index) / 2.0) * 2.0) / 1024.0;
#ifdef D3D9
		float2 clut_color = tex2D(s_texture, clut_pos).ra * 255.0;
#else
		float2 clut_color = s_texture.Sample(samplerState, clut_pos).rg * 255.0;
#endif
		float color_16 = clut_color.y * 256.0 + clut_color.x;
		clip(color_16 - 0.001);

		float4 color = frac(floor(color_16 / float4(1.0, 32.0, 1024.0, 32768.0)) / 32.0);

		color = color * In.v_color;
		float4x4 dither = float4x4(
			-4.0,  +0.0,  -3.0,  +1.0,
			+2.0,  -2.0,  +3.0,  -1.0,
			-3.0,  +1.0,  -4.0,  +0.0,
			+3.0,  -1.0,  +2.0,  -2.0) / 255.0;
		int2 dc = int2(frac(FRAG_COORD / 4.0) * 4.0);
		color.xyz += dither[dc.x][dc.y] * In.v_texcoord.w;

		return color;
	}
#endif
