
#ifndef SPNoise_h
#define SPNoise_h

#include "SPCommon.h"

#define RANDOM_N 624

typedef struct SPNoise {
	int* p;
	double* g3;
	double persistance;

	unsigned long state[RANDOM_N];
	int left;
	unsigned long *next;
} SPNoise;

MJ_EXPORT SPNoise* spNoiseNew(int seed, double persistance);
MJ_EXPORT void spNoiseDelete(SPNoise* noise);
MJ_EXPORT double spNoiseGet(SPNoise* noise, SPVec3 vec, int endOctave);

#endif