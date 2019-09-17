
#ifndef SPParticles_h
#define SPParticles_h

#include "SPCommon.h"
#include "SPRand.h"
#include "SPNoise.h"

enum SPRenderGroupVertexDescriptionType {
	SPRenderGroupVertexDescriptionType_float = 0,
	SPRenderGroupVertexDescriptionType_vec2,
	SPRenderGroupVertexDescriptionType_vec3,
	SPRenderGroupVertexDescriptionType_vec4,
};

typedef struct SPParticleRenderGroupInfo {
	char* shaderName;
	uint32_t localID;
	int vertexDescriptionTypeCount;
	int* vertexDescriptionTypes;
} SPParticleRenderGroupInfo;

typedef struct SPParticleEmitterTypeInfo {
	char* name;
	uint32_t localID;
} SPParticleEmitterTypeInfo;


typedef struct SPParticleEmitterState {
	SPVec3 p;
	SPMat3 rot;
	double timeAccumulatorA;
	double timeAccumulatorB;
	SPVec4 userData; //can be used by mods
	uint32_t globalType;
	uint8_t counters[4];
} SPParticleEmitterState;

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

typedef struct SPParticleThreadState {
	void* particleManager;
	void (*addParticle)(void*,SPParticleEmitterState*,uint32_t,SPParticleState*);
	SPRand* spRand;
	SPNoise* spNoise;
} SPParticleThreadState;

typedef int (* SPGetEmitterTypesCountFunc) ();
typedef SPParticleEmitterTypeInfo* (* SPGetEmitterTypesFunc) ();
typedef int (* SPGetRenderGroupTypesCountFunc) ();
typedef SPParticleRenderGroupInfo* (* SPGetRenderGroupTypesFunc) ();

typedef bool (* SPEmitterWasAddedFunc) (SPParticleThreadState* threadState,
	SPParticleEmitterState* emitterState,
	uint32_t localEmitterTypeID);

typedef void (* SPUpdateEmitterFunc) (SPParticleThreadState* threadState,
	SPParticleEmitterState* emitterState,
	uint32_t localEmitterTypeID,
	double dt);

typedef bool (* SPUpdateParticleFunc) (SPParticleThreadState* threadState, 
	SPParticleState* particleState, 
	uint32_t localRenderGroupTypeID,
	double dt, 
	SPVec3 origin, 
	float* renderBuffer);

MJ_EXPORT int spGetEmitterTypesCount();
MJ_EXPORT SPParticleEmitterTypeInfo* spGetEmitterTypes();
MJ_EXPORT int spGetRenderGroupTypesCount();
MJ_EXPORT SPParticleRenderGroupInfo* spGetRenderGroupTypes();

MJ_EXPORT bool spEmitterWasAdded(SPParticleThreadState* threadState,
	SPParticleEmitterState* emitterState,
	uint32_t localEmitterTypeID);


MJ_EXPORT void spUpdateEmitter(SPParticleThreadState* threadState,
	SPParticleEmitterState* emitterState,
	uint32_t localEmitterTypeID,
	double dt);

MJ_EXPORT bool spUpdateParticle(SPParticleThreadState* threadState, 
	SPParticleState* particleState, 
	uint32_t localRenderGroupTypeID,
	double dt, 
	SPVec3 origin, 
	float* renderBuffer);

#endif