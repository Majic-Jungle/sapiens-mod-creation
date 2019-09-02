

#ifndef SPBiome_h
#define SPBiome_h


#include "SPCommon.h"
#include "SPNoise.h"

typedef int (* SPBiomeGetBiomeTypeFunc) (int climateType);

MJ_EXPORT int spBiomeGetBiomeType(int climateType);

typedef int (* SPBiomeGetSurfaceTypeFunc) (SPNoise* noise, 
	SPBiomeType* biomeTypes,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	int biomeType, 
	int vegetationState, 
	double altitude,
	float steepness,
	float riverDistance);

MJ_EXPORT int spBiomeGetSurfaceType(SPNoise* noise, 
	SPBiomeType* biomeTypes,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	int biomeType, 
	int vegetationState, 
	double altitude,
	float steepness,
	float riverDistance);

#endif