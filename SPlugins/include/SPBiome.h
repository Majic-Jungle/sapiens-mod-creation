

#ifndef SPBiome_h
#define SPBiome_h

#include "SPCommon.h"
#include "SPNoise.h"
#include "SPRand.h"

#define BIOME_MAX_BIOME_TAG_COUNT 32

typedef struct SPBiomeThreadState {
	void* managerObject;

	uint16_t (*getBiomeTag)(void*,char*);
	uint16_t (*getTerrainTypeIndex)(void*,char*);

	SPRand* spRand;
	SPNoise* spNoise1;
	SPNoise* spNoise2;
} SPBiomeThreadState;

/*typedef int (* SPBiomeGetClimateFunc) (float temperatureSummer, 
	float temperatureWinter, 
	float rainfallSummer, 
	float rainfallWinter);

typedef int (* SPBiomeGetBiomeTypeFunc) (int climateType);

typedef int (* SPBiomeGetSurfaceTypeFunc) (SPNoise* noise, 
	SPBiomeType* biomeType,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	int vegetationState, 
	double altitude,
	float steepness,
	float riverDistance);*/

typedef void (* SPBiomeInitFunc) (SPBiomeThreadState* threadState);
typedef void (* SPBiomeGetTagsForPointFunc) (SPBiomeThreadState* threadState,
	uint16_t* tagsOut,
	int* tagCountOut,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	double altitude,
	float riverDistance,
	float temperatureSummer, 
	float temperatureWinter, 
	float rainfallSummer, 
	float rainfallWinter);
typedef uint16_t (*SPBiomeGetSurfaceTypeForPointFunc) (SPBiomeThreadState* threadState, 
	uint16_t incomingType,
	uint16_t* tags,
	int tagCount,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	double altitude,
	float steepness,
	float riverDistance,
	int vegetationState);

MJ_EXPORT void spBiomeInit(SPBiomeThreadState* threadState);


MJ_EXPORT void spBiomeGetTagsForPoint(SPBiomeThreadState* threadState,
	uint16_t* tagsOut,
	int* tagCountOut,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	double altitude,
	float riverDistance,
	float temperatureSummer, 
	float temperatureWinter, 
	float rainfallSummer, 
	float rainfallWinter);

MJ_EXPORT uint16_t spBiomeGetSurfaceTypeForPoint(SPBiomeThreadState* threadState, 
	uint16_t incomingType,
	uint16_t* tags,
	int tagCount,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	double altitude,
	float steepness,
	float riverDistance,
	int vegetationState);


#endif