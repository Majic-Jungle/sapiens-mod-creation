
#ifndef SPRand_h
#define SPRand_h

#include "SPCommon.h"
#include "SPMath.h"

typedef struct SPRand {
	uint32_t seed;
	uint32_t counter;
} SPRand;

MJ_EXPORT SPRand* spRandNew(uint32_t seed);
MJ_EXPORT void spRandDelete(SPRand* spRand);

MJ_EXPORT SPVec3 spRandGetVec3(SPRand* spRand);
MJ_EXPORT double spRandGetValue(SPRand* spRand);

#endif