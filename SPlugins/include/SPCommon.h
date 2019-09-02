
#ifndef SPCommon_h
#define SPCommon_h

#include "SPMath.h"


typedef struct SPWorldGenOptions {
	double heightOffset;
	double rainfallMultiplier;
	double temperatureOffset;
	SPVec3 scales;
	SPVec3 influences;
} SPWorldGenOptions;

typedef struct SPBiomeType {
	int16_t normalTerrainType;
	int16_t secondaryTerrainType;

	int16_t rockTerrainType;
	int16_t beachTerrainType;

	int16_t vegetationStrippedTerrainType;
	int16_t _padding[3];

} SPBiomeType;



#endif