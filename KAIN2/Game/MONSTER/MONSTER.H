#ifndef MONSTER_H
#define MONSTER_H

enum MonsterAnim : int 
{
	MONSTER_ANIM_HIT1 = 0,
	MONSTER_ANIM_HIT2 = 1,
	MONSTER_ANIM_WALK = 2,
	MONSTER_ANIM_RUN = 3,
	MONSTER_ANIM_GRABBED = 4,
	MONSTER_ANIM_STUNNED = 5,
	MONSTER_ANIM_JUMPFORWARD = 6,
	MONSTER_ANIM_JUMPBACK = 7,
	MONSTER_ANIM_JUMPLEFT = 8,
	MONSTER_ANIM_JUMPRIGHT = 9,
	MONSTER_ANIM_STANCE_HEALTHY = 10,
	MONSTER_ANIM_STANCE_VULNERABLE = 11,
	MONSTER_ANIM_STUNNED_RECOVERY = 12,
	MONSTER_ANIM_IMPALED = 13,
	MONSTER_ANIM_STRUGGLE = 14,
	MONSTER_ANIM_BREAKHOLD = 15,
	MONSTER_ANIM_THROWN = 16,
	MONSTER_ANIM_IMPACT = 17,
	MONSTER_ANIM_LANDONFEET = 18,
	MONSTER_ANIM_FALL = 19,
	MONSTER_ANIM_BREAKFALL = 20,
	MONSTER_ANIM_SPINLAND = 21,
	MONSTER_ANIM_IMPALEDEATH = 22,
	MONSTER_ANIM_GETUP = 23,
	MONSTER_ANIM_GENERALDEATH = 24,
	MONSTER_ANIM_MISSILEIMPALEDEATH = 25,
	MONSTER_ANIM_SURPRISED = 26,
	MONSTER_ANIM_AGONY = 27,
	MONSTER_ANIM_PUPATE = 28,
	MONSTER_ANIM_NOTICE = 29,
	MONSTER_ANIM_SOULSUCK = 30,
	MONSTER_ANIM_IMPALEHORZ = 31,
	MONSTER_ANIM_IMPALEVERT = 32,
	MONSTER_ANIM_SOULOUTGRND = 33,
	MONSTER_ANIM_SOULOUTHORZ = 34,
	MONSTER_ANIM_SOULOUTVERT = 35,
	MONSTER_ANIM_FALLOVER = 36,
	MONSTER_ANIM_EMBRACE = 37,
	MONSTER_ANIM_SHOVE = 38,
	MONSTER_ANIM_FLIPSWITCH = 39,
	MONSTER_ANIM_EVADELEFT = 40,
	MONSTER_ANIM_EVADERIGHT = 41,
	MONSTER_ANIM_ALARM = 42,
	MONSTER_ANIM_DEAF = 43,
	MONSTER_ANIM_BLIND = 44,
	MONSTER_ANIM_SUCKED = 45,
	MONSTER_NUM_ANIMS = 46,
};

enum MonsterState : int 
{
	MONSTER_STATE_BIRTH = 0,
	MONSTER_STATE_PURSUE = 1,
	MONSTER_STATE_IDLE = 2,
	MONSTER_STATE_MISSILEHIT = 3,
	MONSTER_STATE_FALL = 4,
	MONSTER_STATE_WANDER = 5,
	MONSTER_STATE_ATTACK = 6,
	MONSTER_STATE_IMPALEDEATH = 7,
	MONSTER_STATE_HIT = 8,
	MONSTER_STATE_STUNNED = 9,
	MONSTER_STATE_GRABBED = 10,
	MONSTER_STATE_THROWN = 11,
	MONSTER_STATE_IMPACT = 12,
	MONSTER_STATE_COMBAT = 13,
	MONSTER_STATE_BREAKHOLD = 14,
	MONSTER_STATE_LANDONFEET = 15,
	MONSTER_STATE_GENERALDEATH = 16,
	MONSTER_STATE_ENVIRONMENTDAMAGE = 17,
	MONSTER_STATE_LANDINWATER = 18,
	MONSTER_STATE_FLEE = 19,
	MONSTER_STATE_HIDE = 20,
	MONSTER_STATE_SURPRISEATTACK = 21,
	MONSTER_STATE_PARRY = 22,
	MONSTER_STATE_DEAD = 23,
	MONSTER_STATE_SURPRISED = 24,
	MONSTER_STATE_NOTICE = 25,
	MONSTER_STATE_PUPATE = 26,
	MONSTER_STATE_EMBRACE = 27,
	MONSTER_STATE_PROJECTILE = 28,
	MONSTER_STATE_TERRAINIMPALEDEATH = 29,
	MONSTER_STATE_PETRIFIED = 30,
	MONSTER_NUM_STATES = 31,
};

typedef void (*TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb)(struct _Instance*, int, int, int, void*);

struct _MonsterSenses 
{
	short sightArc; // size=0, offset=0
	short sightRadius; // size=0, offset=2
	short sightElevation; // size=0, offset=4
	short soundArc; // size=0, offset=6
	short soundRadius; // size=0, offset=8
	short soundElevation; // size=0, offset=10
	unsigned short scentRadius; // size=0, offset=12
	short alarmRadius; // size=0, offset=14
	unsigned short allyRadius; // size=0, offset=16
};

struct _MonsterCombatAttributes 
{
	short stunTime; // size=0, offset=0
	short damageTime; // size=0, offset=2
	short recovery; // size=0, offset=4
	short surpriseTime; // size=0, offset=6
	short grabTime; // size=0, offset=8
	short combatRange; // size=0, offset=10
	short surpriseRange; // size=0, offset=12
	short allyRange; // size=0, offset=14
	short enemyAttackRange; // size=0, offset=16
	short enemyRunAttackRange; // size=0, offset=18
	short preferredCombatRange; // size=0, offset=20
	short suckPower; // size=0, offset=22
	short suckRange; // size=0, offset=24
	short suckTime; // size=0, offset=26
	char hitPoints; // size=0, offset=28
	char numAttacks; // size=0, offset=29
	char missileAttack; // size=0, offset=30
	char ambushAttack; // size=0, offset=31
	char evadeProbability[12]; // size=12, offset=32
	char attackList[1]; // size=1, offset=44
};

struct _MonsterAllegiances 
{
	unsigned long enemies; // size=0, offset=0
	unsigned long allies; // size=0, offset=4
	unsigned long food; // size=0, offset=8
	unsigned long gods; // size=0, offset=12
};

struct _MonsterSubAttributes 
{
	char* animList; // size=0, offset=0
	struct _MonsterSenses* senses; // size=18, offset=4
	struct _MonsterCombatAttributes* combatAttributes; // size=46, offset=8
	struct _MonsterAllegiances* allegiances; // size=16, offset=12
	char* behaviorList; // size=0, offset=16
	short scale; // size=0, offset=20
	short fallDistance; // size=0, offset=22
	short defAmbushRange; // size=0, offset=24
	short fleeRange; // size=0, offset=26
	short speedPivotTurn; // size=0, offset=28
	short speedWalkTurn; // size=0, offset=30
	short speedRunTurn; // size=0, offset=32
	short speedFleeTurn; // size=0, offset=34
	short forgetTime; // size=0, offset=36
	unsigned char modelNum; // size=0, offset=38
	unsigned char physAbility; // size=0, offset=39
	unsigned char stunnable; // size=0, offset=40
	unsigned char grabable; // size=0, offset=41
	unsigned char numSections; // size=0, offset=42
	unsigned char sectionEnd[3]; // size=3, offset=43
	short defPlayerAttitude; // size=0, offset=46
	short defWanderRange; // size=0, offset=48
	short defGuardRange; // size=0, offset=50
	unsigned char defInitialBehavior; // size=0, offset=52
	unsigned char defTriggeredBehavior; // size=0, offset=53
	char defActiveBehavior; // size=0, offset=54
	unsigned char defSpectral; // size=0, offset=55
	unsigned char sunVuln; // size=0, offset=56
	unsigned char fireVuln; // size=0, offset=57
	unsigned char waterVuln; // size=0, offset=58
	unsigned char impaleVuln; // size=0, offset=59
	unsigned char soundVuln; // size=0, offset=60
	unsigned char weaponVuln; // size=0, offset=61
	unsigned char missileVuln; // size=0, offset=62
	unsigned char bruiseRed; // size=0, offset=63
	unsigned char bruiseGreen; // size=0, offset=64
	unsigned char bruiseBlue; // size=0, offset=65
	short minSpikeRange; // size=0, offset=66
	short maxSpikeRange; // size=0, offset=68
	short maxSpikeAngle; // size=0, offset=70
	short minSpikeHorzSpeed; // size=0, offset=72
	short maxSpikeHorzSpeed; // size=0, offset=74
	short maxSpikeVertSpeed; // size=0, offset=76
	short upOnGroundOffset; // size=0, offset=78
	short downOnGroundOffset; // size=0, offset=80
};

struct _MonsterAnim 
{
	unsigned short velocity; // size=0, offset=0
	unsigned short distance; // size=0, offset=2
	unsigned short playSpeed; // size=0, offset=4
	unsigned char interpFrames; // size=0, offset=6
	unsigned char startFrame; // size=0, offset=7
	unsigned char interpOut; // size=0, offset=8
	unsigned char alphaTable; // size=0, offset=9
	unsigned char alphaTableOut; // size=0, offset=10
	unsigned char controllingSection; // size=0, offset=11
	char index[3]; // size=3, offset=12
	char pad; // size=0, offset=15
};

struct _MonsterIdle 
{
	char anim; // size=0, offset=0
	char alertMod; // size=0, offset=1
	char probability; // size=0, offset=2
	char pad; // size=0, offset=3
};

struct _MonsterBehavior 
{
	char alertness; // size=0, offset=0
	char idleFreq; // size=0, offset=1
	char numIdles; // size=0, offset=2
	char idleList[5]; // size=5, offset=3
};

struct _MonsterAttackAttributes 
{
	short attackRange; // size=0, offset=0
	short attackHeight; // size=0, offset=2
	short knockBackDistance; // size=0, offset=4
	char knockBackDuration; // size=0, offset=6
	char damage; // size=0, offset=7
	char sphereSegment; // size=0, offset=8
	char sphereOnFrame; // size=0, offset=9
	char sphereOnAnim; // size=0, offset=10
	char sphereOffFrame; // size=0, offset=11
	char sphereOffAnim; // size=0, offset=12
	char turnFrames; // size=0, offset=13
	char numAnims; // size=0, offset=14
	char attackProbability[12]; // size=12, offset=15
	char animList[5]; // size=5, offset=27
};

struct _MonsterMissile 
{
	unsigned short speed; // size=0, offset=0
	unsigned short range; // size=0, offset=2
	unsigned char frame; // size=0, offset=4
	unsigned char anim; // size=0, offset=5
	unsigned char segment; // size=0, offset=6
	unsigned char damage; // size=0, offset=7
	unsigned char type; // size=0, offset=8
	unsigned char graphic; // size=0, offset=9
	char gravity; // size=0, offset=10
	char reload; // size=0, offset=11
	char fireChance; // size=0, offset=12
	unsigned char numAnims; // size=0, offset=13
	char animList[2]; // size=2, offset=14
};

struct _MonsterIR 
{
	struct _MonsterIR* next; // size=36, offset=0
	struct _Instance* instance; // size=668, offset=4
	long handle; // size=0, offset=8
	struct _SVector relativePosition; // size=8, offset=12
	short distance; // size=0, offset=20
	unsigned short mirFlags; // size=0, offset=22
	unsigned short mirConditions; // size=0, offset=24
	unsigned long forgetTimer; // size=0, offset=28
	unsigned long idleTime; // size=0, offset=32
};

struct _MonsterState 
{
	void (*entryFunction)(struct _Instance* instance); // size=0, offset=0
	void (*stateFunction)(struct _Instance* instance); // size=0, offset=4
};

struct _MonsterStateChoice 
{
	int state; // size=0, offset=0
	struct _MonsterState functions; // size=8, offset=4
};

struct _MonsterAttributes 
{
	unsigned long magicnum; // size=0, offset=0
	void* tunData; // size=0, offset=4
	char* auxAnimList; // size=0, offset=8
	char* ambientAnimList; // size=0, offset=12
	long whatAmI; // size=0, offset=16
	char numAuxAnims; // size=0, offset=20
	char numAmbientAnims; // size=0, offset=21
	unsigned char defaultAge; // size=0, offset=22
	char pupateObject; // size=0, offset=23
	unsigned char damageFXSegment; // size=0, offset=24
	unsigned char headSegment; // size=0, offset=25
	unsigned char neckSegment; // size=0, offset=26
	unsigned char leftShoulderSegment; // size=0, offset=27
	unsigned char rightShoulderSegment; // size=0, offset=28
	unsigned char waistSegment; // size=0, offset=29
	unsigned char leftKneeSegment; // size=0, offset=30
	unsigned char rightKneeSegment; // size=0, offset=31
	unsigned char leftFootSegment; // size=0, offset=32
	unsigned char rightFootSegment; // size=0, offset=33
	unsigned char spineSegment; // size=0, offset=34
	unsigned char leftWeaponSegment; // size=0, offset=35
	unsigned char rightWeaponSegment; // size=0, offset=36
	unsigned char grabSegment; // size=0, offset=37
	unsigned char bloodImpaleFrame; // size=0, offset=38
	unsigned char bloodConeFrame; // size=0, offset=39
	char numSubAttributes; // size=0, offset=40
	char numCombatAttributes; // size=0, offset=41
	char numAttackAttributes; // size=0, offset=42
	char numMissiles; // size=0, offset=43
	char numAnims; // size=0, offset=44
	char numIdles; // size=0, offset=45
	char numBehaviors; // size=0, offset=46
	char numShatters; // size=0, offset=47
	struct _MonsterSubAttributes** subAttributesList; // size=84, offset=48
	struct _MonsterCombatAttributes** combatAttributesList; // size=46, offset=52
	struct _MonsterAttackAttributes* attackAttributesList; // size=32, offset=56
	struct _MonsterMissile* missileList; // size=16, offset=60
	struct _MonsterAnim* animList; // size=16, offset=64
	struct _MonsterIdle* idleList; // size=4, offset=68
	struct _MonsterBehavior* behaviorList; // size=8, offset=72
	void* shatterList; // size=0, offset=76
};

struct _MONAPI_Regenerator 
{
	unsigned long regenTime; // size=0, offset=0
	short introUniqueID; // size=0, offset=4
	short streamUnitID; // size=0, offset=6
};

struct burntTuneType 
{
	int burntDist; // size=0, offset=0
	int fadeDelta; // size=0, offset=4
};

struct __Event 
{
	int ID; // size=0, offset=0
	int Data; // size=0, offset=4
};

struct __MessageQueue 
{
	int Head; // size=0, offset=0
	int Tail; // size=0, offset=4
	struct __Event Queue[16]; // size=128, offset=8
};

struct __State 
{
	void (*Process)(struct __CharacterState*, int, int); // size=0, offset=0
	struct __MessageQueue Event; // size=136, offset=4
	struct __MessageQueue Defer; // size=136, offset=140
	int Data1; // size=0, offset=276
	int Data2; // size=0, offset=280
};

struct _MonsterVars 
{
	unsigned long mvFlags; // size=0, offset=0
	unsigned long auxFlags; // size=0, offset=4
	struct __MessageQueue messageQueue; // size=136, offset=8
	struct _MonsterIR* monsterIRList; // size=0, offset=144
	struct _G2AnimInterpInfo_Type interpInfo[3]; // size=36, offset=148
	struct _MonsterAttackAttributes* attackType; // size=32, offset=184
	struct _MonsterAnim* anim; // size=16, offset=188
	void* messageData; // size=0, offset=192
	struct _MonsterIR* enemy; // size=0, offset=196
	struct _MonsterIR* leader; // size=0, offset=200
	struct _MonsterIR* ally; // size=0, offset=204
	struct _Instance* held; // size=668, offset=208
	long heldID; // size=0, offset=212
	long soulID; // size=0, offset=216
	void* effect; // size=0, offset=220
	unsigned long radarMap; // size=0, offset=224
	unsigned long radarCounter; // size=0, offset=228
	short radarDistance[16]; // size=32, offset=232
	unsigned long mode; // size=0, offset=264
	unsigned long damageTimer; // size=0, offset=268
	unsigned long stunTimer; // size=0, offset=272
	unsigned long generalTimer; // size=0, offset=276
	unsigned long generalTimer2; // size=0, offset=280
	unsigned long effectTimer; // size=0, offset=284
	struct _Position* lookAtPos; // size=6, offset=288
	struct _Position destination; // size=6, offset=292
	short speed; // size=0, offset=298
	struct _Position lastValidPos; // size=6, offset=300
	struct _Position lookAtPosData; // size=6, offset=306
	short fleeMarker; // size=0, offset=312
	short wanderRange; // size=0, offset=314
	short guardRange; // size=0, offset=316
	short ambushRange; // size=0, offset=318
	short ambushArc; // size=0, offset=320
	short ambushElevation; // size=0, offset=322
	short hitPoints; // size=0, offset=324
	short maxHitPoints; // size=0, offset=326
	short soulJuice; // size=0, offset=328
	short regenTime; // size=0, offset=330
	short mainColorVertex; // size=0, offset=332
	short lookAngleX; // size=0, offset=334
	short lookAngleZ; // size=0, offset=336
	unsigned short avoidMask; // size=0, offset=338
	unsigned short damageType; // size=0, offset=340
	char ambushMarker; // size=0, offset=342
	char ambushJumpType; // size=0, offset=343
	unsigned char causeOfDeath; // size=0, offset=344
	char previousMainState; // size=0, offset=345
	unsigned char behaviorState; // size=0, offset=346
	unsigned char initialBehavior; // size=0, offset=347
	unsigned char triggeredBehavior; // size=0, offset=348
	char activeBehavior; // size=0, offset=349
	unsigned char age; // size=0, offset=350
	char attackState; // size=0, offset=351
	unsigned char ambient; // size=0, offset=352
	char alertness; // size=0, offset=353
	char alertCount; // size=0, offset=354
	char senseIndex; // size=0, offset=355
	char lastSideMove; // size=0, offset=356
	char chance; // size=0, offset=357
	char pathSlotID; // size=0, offset=358
	struct _MonsterSubAttributes* subAttr; // size=84, offset=360
	struct _MonsterIR* freeIRs; // size=0, offset=364
	void* extraVars; // size=0, offset=368
	short validUnits[10]; // size=20, offset=372
	short patrolMarkers[12]; // size=24, offset=392
	short* currentMarker; // size=0, offset=416
	long terrainImpaleID; // size=0, offset=420
	short targetFade; // size=0, offset=424
	short fadeRate; // size=0, offset=426
};

struct evMonsterHitTerrainData 
{
	struct _TFace* tface; // size=12, offset=0
	struct _Normal normal; // size=8, offset=4
	short faceFlags; // size=0, offset=12
	short bspFlags; // size=0, offset=14
};

struct evMonsterHitObjectData 
{
	struct _Instance* instance; // size=668, offset=0
	int hitType; // size=0, offset=4
};

struct evMonsterThrownData 
{
	struct _Instance* sender; // size=668, offset=0
	struct _Rotation direction; // size=8, offset=4
	short power; // size=0, offset=12
};

struct _MonsterSaveInfo 
{
	long mvFlags; // size=0, offset=0
	long auxFlags; // size=0, offset=4
	short soulID; // size=0, offset=8
	short soulJuice; // size=0, offset=10
	unsigned int age : 3; // offset=12.0
	unsigned int state : 6; // offset=12.3
	unsigned int behaviorState : 5; // offset=13.1
	unsigned int anim : 6; // offset=13.6
	unsigned int animLooping : 1; // offset=14.4
	unsigned int causeOfDeath : 3; // offset=14.5
};

struct _MonsterFunctionTable 
{
	void (*initFunc)(struct _Instance* instance); // size=0, offset=0
	void (*cleanUpFunc)(struct _Instance* instance); // size=0, offset=4
	void (*damageEffectFunc)(struct _Instance* instance, struct evFXHitData* data); // size=0, offset=8
	unsigned long (*queryFunc)(struct _Instance* instance, unsigned long data); // size=0, offset=12
	void (*messageFunc)(struct _Instance* instance, unsigned long message, unsigned long data); // size=0, offset=16
	struct _MonsterStateChoice* stateFuncs; // size=12, offset=20
	char* versionID; // size=0, offset=24
	char* localVersionID; // size=0, offset=28
};

struct bloodyMessType {
	int closestvert; // size=0, offset=0
	int closestdist; // size=0, offset=4
	int closestseg; // size=0, offset=8
	int bloodiedAVert; // size=0, offset=12
	int bloodIntensity; // size=0, offset=16
};

struct burntMessType {
	int closestvert; // size=0, offset=0
	int closestdist; // size=0, offset=4
	int closestseg; // size=0, offset=8
	struct burntTuneType* burntTune; // size=8, offset=12
};

// base inclusion for functions
#include "MONAPI.H"
#include "MONLIB.H"
#include "MONMSG.H"
#include "MONSENSE.H"
#include "MONTABLE.H"

// monsters
#include "ALUKA.H"
#include "HUNTER.H"
#include "HUMAN.H"

#if defined(_LANGUAGE_C_PLUS_PLUS) || defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

extern void MON_DoCombatTimers(struct _Instance *instance); // 0x800871FC
extern void MON_ChangeHumanOpinion(struct _Instance *instance); // 0x800873E4
extern void MON_CutOut_Monster(struct _Instance *instance, int fade_amount, int startseg, int endseg); // 0x8008748C
extern void MON_DeadEntry(struct _Instance *instance); // 0x800876E0
extern void MON_Dead(struct _Instance *instance); // 0x800877D0
extern void MON_MissileHitEntry(struct _Instance *instance); // 0x80087F04
extern void MON_MissileHit(struct _Instance *instance); // 0x80087FD0
extern void MON_BirthEntry(struct _Instance *instance); // 0x800880B0
extern void MON_Birth(struct _Instance *instance); // 0x800880B8
extern void MON_ParryEntry(struct _Instance *instance); // 0x800880D8
extern void MON_Parry(struct _Instance *instance); // 0x80088128
extern void MON_LandOnFeetEntry(struct _Instance *instance); // 0x8008816C
extern void MON_LandOnFeet(struct _Instance *instance); // 0x80088230
extern void MON_LandInWaterEntry(struct _Instance *instance); // 0x800883BC
extern void MON_LandInWater(struct _Instance *instance); // 0x800883D0
extern void MON_BreakHoldEntry(struct _Instance *instance); // 0x800883F0
extern void MON_BreakHold(struct _Instance *instance); // 0x8008845C
extern void MON_ImpactEntry(struct _Instance *instance); // 0x80088638
extern void MON_Impact(struct _Instance *instance); // 0x8008871C
extern void MON_FallEntry(struct _Instance *instance); // 0x8008879C
extern void MON_Fall(struct _Instance *instance); // 0x8008885C
extern void MON_ThrownEntry(struct _Instance *instance); // 0x800889D8
extern void MON_Thrown(struct _Instance *instance); // 0x80088A74
extern void MON_ImpaleDeathEntry(struct _Instance *instance); // 0x80088BCC
extern void MON_ImpaleDeath(struct _Instance *instance); // 0x80088C4C
extern void MON_TerrainImpaleDeathEntry(struct _Instance *instance); // 0x80088E54
extern void MON_TerrainImpaleDeath(struct _Instance *instance); // 0x80088FA8
extern void MON_SurprisedEntry(struct _Instance *instance); // 0x80089190
extern void MON_Surprised(struct _Instance *instance); // 0x800891F0
extern void MON_StunnedEntry(struct _Instance *instance); // 0x800892B4
extern void MON_Stunned(struct _Instance *instance); // 0x80089464
extern void MON_GrabbedEntry(struct _Instance *instance); // 0x80089574
extern void MON_Grabbed(struct _Instance *instance); // 0x80089658
extern void MON_HitEntry(struct _Instance *instance); // 0x80089870
extern void MON_Hit(struct _Instance *instance); // 0x80089914
extern void MON_AttackEntry(struct _Instance *instance); // 0x800899FC
extern void MON_Attack(struct _Instance *instance); // 0x80089A70
extern void MON_CombatEntry(struct _Instance *instance); // 0x80089C50
extern void MON_Combat(struct _Instance *instance); // 0x80089C7C
extern void MON_ProjectileEntry(struct _Instance *instance); // 0x80089F64
extern void MON_Projectile(struct _Instance *instance); // 0x80089FBC
extern void MON_IdleEntry(struct _Instance *instance); // 0x8008A100
extern void MON_Idle(struct _Instance *instance); // 0x8008A1B8
extern void MON_FleeEntry(struct _Instance *instance); // 0x8008A3F4
extern void MON_Flee(struct _Instance *instance); // 0x8008A448
extern void MON_PursueEntry(struct _Instance *instance); // 0x8008A58C
extern void MON_Pursue(struct _Instance *instance); // 0x8008A61C
extern void MON_WanderEntry(struct _Instance *instance); // 0x8008AA54
extern void MON_Wander(struct _Instance *instance); // 0x8008AAFC
extern void MON_HideEntry(struct _Instance *instance); // 0x8008AD74
extern void MON_Hide(struct _Instance *instance); // 0x8008AD94
extern void MON_SurpriseAttackEntry(struct _Instance *instance); // 0x8008AF10
extern void MON_SurpriseAttack(struct _Instance *instance); // 0x8008AFA4
extern void MON_EnvironmentDamageEntry(struct _Instance *instance); // 0x8008AFC4
extern void MON_EnvironmentDamage(struct _Instance *instance); // 0x8008AFCC
extern void MON_MonsterGlow(struct _Instance *instance, long color, int glowtime, int glowin, int glowfade); // 0x8008AFD4
extern void MON_GeneralDeathEntry(struct _Instance *instance); // 0x8008B160
extern void MON_GeneralDeath(struct _Instance *instance); // 0x8008B3AC
extern void MON_NoticeEntry(struct _Instance *instance); // 0x8008B524
extern void MON_Notice(struct _Instance *instance); // 0x8008B5DC
extern void MON_PupateEntry(struct _Instance *instance); // 0x8008B67C
extern void MON_Pupate(struct _Instance *instance); // 0x8008B6DC
extern void MON_EmbraceEntry(struct _Instance *instance); // 0x8008BA1C
extern void MON_Embrace(struct _Instance *instance); // 0x8008BA7C
extern void MON_PetrifiedEntry(struct _Instance *instance); // 0x8008BBFC
extern void MON_Petrified(struct _Instance *instance); // 0x8008BC38
extern int MONSTER_CalcDamageIntensity(int hp, int maxHp); // 0x8008BD44
extern void MONSTER_ProcessClosestVerts(struct _Instance *instance, struct _SVector *location, TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb processVert_cb, void *cb_data); // 0x8008BD5C
extern void ProcessBloodyMess(struct _Instance *instance, int vertidx, int segidx, int dist, void *cb_data); // 0x8008BF24
extern void MONSTER_InitVertexColors(struct _Instance *instance, struct _Model *model); // 0x8008C030
extern int MONSTER_StartVertexBlood(struct _Instance *instance, struct _SVector *location, int amount); // 0x8008C098
extern void MONSTER_VertexBlood(struct _Instance *instance, int vert, int amount); // 0x8008C220
extern void ProcessBurntMess(struct _Instance *instance, int vertidx, int segidx, int dist, void *cb_data); // 0x8008C3EC
extern int MONSTER_StartVertexBurnt(struct _Instance *instance, struct _SVector *location, struct burntTuneType *burntTune); // 0x8008C498
extern void MONSTER_VertexBurnt(struct _Instance *instance, struct burntTuneType *burntTune); // 0x8008C618
extern void MON_DamageEffect(struct _Instance *instance, struct evFXHitData *data); // 0x8008C6C4
extern void MON_DefaultInit(struct _Instance *instance); // 0x8008CB28
extern void MON_CleanUp(struct _Instance *instance); // 0x8008CD74

#if defined(_LANGUAGE_C_PLUS_PLUS) || defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif
