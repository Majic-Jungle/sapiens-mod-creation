
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



#endif