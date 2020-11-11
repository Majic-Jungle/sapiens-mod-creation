
#ifndef SPRand_h
#define SPRand_h

#include "SPCommon.h"
#include "SPMath.h"

typedef struct SPRand SPRand;


MJ_EXPORT double spRandomValueForUniqueIDAndSeed(uint64_t uniqueID, uint32_t seed);
MJ_EXPORT uint32_t spRandomIntegerValueForUniqueIDAndSeed(uint64_t uniqueID, uint32_t seed, uint32_t max);

MJ_EXPORT SPRand* spRandNew(uint32_t seed);
MJ_EXPORT void spRandDelete(SPRand* spRand);

MJ_EXPORT SPVec3 spRandomVec3ForUniqueID(SPRand* spRand, uint64_t uniqueID);
MJ_EXPORT SPVec3 spRandGetVec3(SPRand* spRand);
MJ_EXPORT double spRandGetValue(SPRand* spRand);



#endif