
#ifndef SPNoise_h
#define SPNoise_h

#include "SPCommon.h"

typedef struct SPNoise SPNoise;

MJ_EXPORT SPNoise* spNoiseNew(int seed, double persistance);
MJ_EXPORT void spNoiseDelete(SPNoise* noise);
MJ_EXPORT double spNoiseGet(SPNoise* noise, SPVec3 vec, int endOctave);

#endif