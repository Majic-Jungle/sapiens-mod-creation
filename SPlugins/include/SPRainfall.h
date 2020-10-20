

#ifndef SPRainfall_h
#define SPRainfall_h

#include "SPCommon.h"
#include "SPNoise.h"

typedef void (* SPRainfallGetFunc) (SPNoise* noise, 
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	SPWorldGenOptions worldGenOptions, 
	double riverDistance, 
	double pregenRainfall0, 
	double pregenRainfall1,
	double altitude,
	double* outRainfall0,
	double* outRainfall1);

MJ_EXPORT void spRainfallGet(SPNoise* noise, 
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	SPWorldGenOptions worldGenOptions, 
	double riverDistance, 
	double pregenRainfall0, 
	double pregenRainfall1,
	double altitude,
	double* outRainfall0,
	double* outRainfall1);

#endif