#ifndef VRAM_H
#define VRAM_H

#include "MENU/MENUFACE.H"

struct Object;

struct VramBuffer 
{
	long flags; // size=0, offset=0
	short x; // size=0, offset=4
	short y; // size=0, offset=6
	short w; // size=0, offset=8
	short h; // size=0, offset=10
	short yOffset; // size=0, offset=12
	short lengthOfLeftOverData; // size=0, offset=14
	short* lineOverFlow; // size=0, offset=16
};

struct _BlockVramEntry 
{
#if defined(PSX_VERSION)
	struct _BlockVramEntry* next; // size=28, offset=0
	unsigned char type; // size=0, offset=4
	unsigned char flags; // size=0, offset=5
	short time; // size=0, offset=6
	long ID; // size=0, offset=8
	short x; // size=0, offset=12
	short y; // size=0, offset=14
	short w; // size=0, offset=16
	short h; // size=0, offset=18
	long area; // size=0, offset=20
	union
	{
		struct _StreamUnit* streamUnit; // size=64, offset=0
		struct _ObjectTracker* streamObject; // size=36, offset=0
		struct _ButtonTexture* button; // size=16, offset=0
	}
	udata; // size=4, offset=24
#else
	struct _BlockVramEntry* next; // size=28, offset=0
	unsigned char type; // size=0, offset=4
	unsigned char flags; // size=0, offset=5
	short time; // size=0, offset=6
	short newX; // size=0, offset=8
	short newY; // size=0, offset=10
	short x; // size=0, offset=12
	short y; // size=0, offset=14
	short w; // size=0, offset=16
	short h; // size=0, offset=18
	long area; // size=0, offset=20
	union 
	{
		struct _StreamUnit* streamUnit; // size=64, offset=0
		struct _ObjectTracker* streamObject; // size=36, offset=0
		struct _ButtonTexture* button; // size=16, offset=0
	} 
	udata; // size=4, offset=24, found in object files: debug.o, debug.o
#endif
};

struct VramSize 
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short w; // size=0, offset=4
	short h; // size=0, offset=6
};

extern long VRAM_NeedToUpdateMorph; // offset 0x800D1A70
extern short M_TrackClutUpdate; // offset 0x800D61B8
extern struct _BlockVramEntry* openVramBlocks; // offset 0x800D61E0
extern struct _BlockVramEntry* usedVramBlocks; // offset 0x800D61DC
extern struct _BlockVramEntry vramBlockList[90]; // offset 0x800D57E0
extern long numOfBlocksUsed; // offset 0x800D61BC

extern void VRAM_PrintVramBlock(struct _BlockVramEntry* vblock /*$a0*/);

extern void VRAM_PrintInfo();

extern void VRAM_InitVramBlockCache(); // 0x800728D0

extern void VRAM_EnableTerrainArea(); // 0x80072930

extern void VRAM_DisableTerrainArea(); // 0x80072960

extern int VRAM_ConcatanateMemory(struct _BlockVramEntry *curBlock); // 0x8007298C

extern void VRAM_GarbageCollect(); // 0x80072B74

extern int VRAM_InsertFreeBlock(struct _BlockVramEntry *block); // 0x80072BA8

extern void VRAM_DeleteFreeBlock(struct _BlockVramEntry *block); // 0x80072C38

extern void VRAM_InsertUsedBlock(struct _BlockVramEntry *block); // 0x80072CA0

extern void VRAM_DeleteUsedBlock(struct _BlockVramEntry *block); // 0x80072CD4

extern struct _BlockVramEntry * VRAM_GetOpenBlock(); // 0x80072D38

extern int VRAM_DeleteFreeVram(short x, short y, short w, short h); // 0x80072D6C

extern int VRAM_InsertFreeVram(short x, short y, short w, short h, short flags); // 0x80072E9C

extern struct _BlockVramEntry * VRAM_CheckVramSlot(short *x, short *y, short w, short h, int type, int startY); // 0x80073030

extern void VRAM_ClearVramBlock(struct _BlockVramEntry *block); // 0x8007342C

extern void AdjustVramCoordsObject(int oldx, int oldy, int newx, int newy, struct Object *object); // 0x80073460

extern struct _BlockVramEntry* VRAM_InsertionSort(struct _BlockVramEntry* rootNode, struct _BlockVramEntry* newBlock);

extern void VRAM_ClearVram(); // 0x80073704

extern void VRAM_RearrangeVramsLayer(long whichLayer);

extern void VRAM_TransferBufferToVram(void *dataPtr, long dataSize, short status, void *data1, void *data2); // 0x80073DC8

extern void VRAM_LoadReturn(void *dataPtr, void *data1, void *data2); // 0x80074040

extern long VRAM_GetObjectVramSpace(struct VramSize *vramSize, struct _ObjectTracker *objectTracker); // 0x80074060

extern void VRAM_InitMorphPalettes(); // 0x80074158

extern void VRAM_UpdateMorphPalettes(); // 0x80074160

extern void MORPH_ChangeAreaPalettes(long time); // 0x80074168


#endif
