

#ifndef SPBiome_h
#define SPBiome_h

#include "SPCommon.h"
#include "SPNoise.h"
#include "SPRand.h"

#define BIOME_MAX_BIOME_TAG_COUNT_PER_VERTEX 32
#define BIOME_MAX_GAME_OBJECT_COUNT_PER_SUBDIVISION 50

struct SPBiomeThreadState;

typedef struct SPBiomeThreadState {
	void* terrainGenerator; //private
	void* gom; //private

	uint16_t (*getBiomeTag)(struct SPBiomeThreadState*,char*);
	uint16_t (*getTerrainTypeIndex)(struct SPBiomeThreadState*,char*);
	uint16_t (*getGameObjectTypeIndex)(struct SPBiomeThreadState*,char*);

	SPRand* spRand;
	SPNoise* spNoise1;
	SPNoise* spNoise2;
} SPBiomeThreadState;

typedef void (* SPBiomeInitFunc) (SPBiomeThreadState* threadState);
typedef void (* SPBiomeGetTagsForPointFunc) (SPBiomeThreadState* threadState,
	uint16_t* tagsOut,
	int* tagCountOut,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	double altitude,
	float steepness,
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
	int vegetationState,
	int seasonIndex);
typedef int (*SPBiomeGetTransientGameObjectTypesForFaceSubdivisionFunc) (SPBiomeThreadState* threadState,
	int incomingTypeCount,
	uint16_t* types,
	uint16_t* biomeTags,
	int tagCount,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	uint64_t faceUniqueID, 
	int level, 
	double altitude, 
	float steepness,
	uint16_t terrainType, 
	float riverDistance);

MJ_EXPORT void spBiomeInit(SPBiomeThreadState* threadState);

MJ_EXPORT void spBiomeGetTagsForPoint(SPBiomeThreadState* threadState,
	uint16_t* tagsOut,
	int* tagCountOut,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	double altitude,
	float steepness,
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
	int vegetationState,
	int seasonIndex);

MJ_EXPORT int spBiomeGetTransientGameObjectTypesForFaceSubdivision(SPBiomeThreadState* threadState,
	int incomingTypeCount,
	uint16_t* types,
	uint16_t* biomeTags,
	int tagCount,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	uint64_t faceUniqueID, 
	int level, 
	double altitude, 
	float steepness,
	uint16_t terrainType, 
	float riverDistance);


#endif