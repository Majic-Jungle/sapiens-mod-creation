
#ifndef SPHeight_h
#define SPHeight_h

#include "SPCommon.h"
#include "SPNoise.h"

typedef SPVec4 (* SPHeightGetFunc) (SPNoise* noise1, 
	SPNoise* noise2,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	SPWorldGenOptions worldGenOptions, 
	double riverValue,
	double riverDistance);

MJ_EXPORT SPVec4 spHeightGet(SPNoise* noise1, 
	SPNoise* noise2,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	SPWorldGenOptions worldGenOptions, 
	double riverValue,
	double riverDistance);

#endif