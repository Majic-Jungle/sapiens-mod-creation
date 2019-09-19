

#ifndef SPBiome_h
#define SPBiome_h

#include "SPCommon.h"
#include "SPNoise.h"

typedef int (* SPBiomeGetClimateFunc) (float temperatureSummer, 
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
	float riverDistance);


MJ_EXPORT int spBiomeGetClimate(float temperatureSummer, 
	float temperatureWinter, 
	float rainfallSummer, 
	float rainfallWinter);

MJ_EXPORT int spBiomeGetBiomeType(int climateType);

MJ_EXPORT int spBiomeGetSurfaceType(SPNoise* noise, 
	SPBiomeType* biomeType,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	int vegetationState, 
	double altitude,
	float steepness,
	float riverDistance);


#endif