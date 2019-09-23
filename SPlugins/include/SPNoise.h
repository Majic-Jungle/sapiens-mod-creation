
#ifndef SPNoise_h
#define SPNoise_h

#include "SPCommon.h"

typedef struct SPNoise SPNoise;

MJ_EXPORT SPNoise* spNoiseNew(int seed, double persistance);
MJ_EXPORT void spNoiseDelete(SPNoise* noise);

MJ_EXPORT double spNoiseGet(SPNoise* noise, SPVec3 vec, int endOctave);
MJ_EXPORT double spNoiseGetRangedFraction(SPNoise* noise, SPVec3 vec, int endOctave);
MJ_EXPORT bool spNoiseGetChance(SPNoise* noise,
	SPVec3 vec,
	int endOctave,
	uint32_t chanceNumerator,
	uint32_t chanceDenominator,
	uint64_t uniqueID,
	uint32_t seed);

#endif