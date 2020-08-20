

#ifndef SPBiome_h
#define SPBiome_h

#include "SPCommon.h"
#include "SPNoise.h"
#include "SPRand.h"

#define BIOME_MAX_BIOME_TAG_COUNT_PER_VERTEX 32
#define BIOME_MAX_TERRAIN_VARIATION_COUNT_PER_VERTEX 32
#define BIOME_MAX_TERRAIN_MODIFICATION_COUNT_PER_VERTEX 32
#define BIOME_MAX_GAME_OBJECT_COUNT_PER_SUBDIVISION 50

struct SPBiomeThreadState;

typedef struct SPSurfaceTypeDefault {
	uint32_t materialIndexA;
	uint32_t materialIndexB;
	uint32_t decalGroupIndex;
	float pathDifficultyMultiplier;
} SPSurfaceTypeDefault;

typedef struct SPBiomeThreadState {
	void* terrainGenerator; //private
	void* gom; //private

	uint16_t (*getBiomeTag)(struct SPBiomeThreadState*,char*);
	uint32_t (*getTerrainBaseTypeIndex)(struct SPBiomeThreadState*,char*);
	uint32_t (*getTerrainVariation)(struct SPBiomeThreadState*,char*);
	uint32_t (*getTerrainModification)(struct SPBiomeThreadState*,char*);
	uint32_t (*getGameObjectTypeIndex)(struct SPBiomeThreadState*,char*);

	uint32_t (*getMaterialTypeIndex)(struct SPBiomeThreadState*,char*);
	uint32_t (*getDecalGroupTypeIndex)(struct SPBiomeThreadState*,char*);

	SPSurfaceTypeDefault (*getSurfaceDefaultsForBaseType)(struct SPBiomeThreadState*,uint32_t);
	SPSurfaceTypeDefault (*getSurfaceDefaultsForVariationType)(struct SPBiomeThreadState*,uint32_t);

	uint32_t (*getSurfaceBaseTypeForFillObjectType)(struct SPBiomeThreadState*,uint32_t);


	SPRand* spRand;
	SPNoise* spNoise1;
	SPNoise* spNoise2;
} SPBiomeThreadState;


typedef struct SPSurfaceTypeResult {
	uint32_t surfaceBaseType;
	uint16_t variationCount;
	uint32_t materialIndexA;
	uint32_t materialIndexB;
	uint32_t decalTypeIndex;
	float pathDifficultyMultiplier;
} SPSurfaceTypeResult;

typedef struct SPTerrainVertModification {
	int16_t heightOffset;
	uint32_t* modifications;
	uint16_t modificationCount;
} SPTerrainVertModification;

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
typedef SPSurfaceTypeResult (*SPBiomeGetSurfaceTypeForPointFunc) (SPBiomeThreadState* threadState, 
	SPSurfaceTypeResult incomingType,
	uint16_t* tags,
	int tagCount,
	uint32_t* modifications,
	int modificationCount,
	uint32_t fillGameObjectTypeIndex,
	int16_t digFillOffset,
	uint32_t* variations,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	double altitude,
	float steepness,
	float riverDistance,
	int seasonIndex);
typedef int (*SPBiomeGetTransientGameObjectTypesForFaceSubdivisionFunc) (SPBiomeThreadState* threadState,
	int incomingTypeCount,
	uint32_t* types,
	uint16_t* biomeTags,
	int tagCount,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	uint64_t faceUniqueID, 
	int level, 
	double altitude, 
	float steepness,
	uint32_t terrainBaseType, 
	uint32_t* variations,
	int variationCount,
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

MJ_EXPORT SPSurfaceTypeResult spBiomeGetSurfaceTypeForPoint(SPBiomeThreadState* threadState, 
	SPSurfaceTypeResult incomingType,
	uint16_t* tags,
	int tagCount,
	uint32_t* modifications,
	int modificationCount,
	uint32_t fillGameObjectTypeIndex,
	int16_t digFillOffset,
	uint32_t* variations,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	double altitude,
	float steepness,
	float riverDistance,
	int seasonIndex);

MJ_EXPORT int spBiomeGetTransientGameObjectTypesForFaceSubdivision(SPBiomeThreadState* threadState,
	int incomingTypeCount,
	uint32_t* types,
	uint16_t* biomeTags,
	int tagCount,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	uint64_t faceUniqueID, 
	int level, 
	double altitude, 
	float steepness,
	uint32_t terrainBaseType, 
	uint32_t* variations,
	int variationCount,
	float riverDistance);


#endif