
#ifndef SPParticles_h
#define SPParticles_h

#include "SPCommon.h"
#include "SPRand.h"
#include "SPNoise.h"


typedef struct SPParticleState {
	SPVec3 p;
	SPVec3 v;
	SPVec3 gravity;
	double lifeLeft;
	double scale;
	double randomValueA;
	double randomValueB;
	SPVec4 userData; //can be used by mods
	uint32_t particleTextureType;

} SPParticleState;

typedef struct SPParticleEmitterState {
	SPVec3 p;
	SPMat3 rot;
	double timeAccumulatorA;
	double timeAccumulatorB;
	SPVec4 userData; //can be used by mods
	uint32_t type;
	uint8_t counters[4];
} SPParticleEmitterState;


typedef struct SPParticleThreadState {
	void* particleManager;
	void (*addParticle)(void*,uint32_t,SPParticleState*);
	SPRand* spRand;
	SPNoise* spNoise;
} SPParticleThreadState;



typedef bool (* SPEmitterWasAddedFunc) (SPParticleThreadState* threadState,
	SPParticleEmitterState* emitterState);

MJ_EXPORT bool spEmitterWasAdded(SPParticleThreadState* threadState,
	SPParticleEmitterState* emitterState);

typedef void (* SPUpdateEmitterFunc) (SPParticleThreadState* threadState,
	SPParticleEmitterState* emitterState,
	double dt);

MJ_EXPORT void spUpdateEmitter(SPParticleThreadState* threadState,
	SPParticleEmitterState* emitterState,
	double dt);

typedef bool (* SPUpdateParticleFunc) (SPParticleThreadState* threadState, 
	SPParticleState* particleState, 
	uint32_t renderGroup,
	double dt, 
	SPVec3 origin, 
	float* renderBuffer);

MJ_EXPORT bool spUpdateParticle(SPParticleThreadState* threadState, 
	SPParticleState* particleState, 
	uint32_t renderGroup,
	double dt, 
	SPVec3 origin, 
	float* renderBuffer);

#endif