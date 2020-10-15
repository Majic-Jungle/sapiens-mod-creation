

#include "SPNoise.h"
#include "SPCommon.h"
#include "SPRand.h"
#include <stdio.h>
#include <stdlib.h>



#define RANDOM_N 624
typedef struct SPNoise {
	int* p;
	double* g3;
	double persistance;

	unsigned long state[RANDOM_N];
	int left;
	unsigned long *next;
} SPNoise;

/* Period parameters */  
#define RANDOM_M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UMASK 0x80000000UL /* most significant w-r bits */
#define LMASK 0x7fffffffUL /* least significant r bits */
#define MIXBITS(u,v) ( ((u) & UMASK) | ((v) & LMASK) )
#define TWIST(u,v) ((MIXBITS(u,v) >> 1) ^ ((v)&1UL ? MATRIX_A : 0UL))


double noise3DPrivate(SPNoise* noise, SPVec3 vec);

#define SPN_SAMPLE_SIZE 2048

#define PERLIN_B_FAST SPN_SAMPLE_SIZE
#define PERLIN_BM_FAST (SPN_SAMPLE_SIZE-1)
#define PERLIN_N_FAST 0x1000


#define normalize3(v) \
double d;\
d = (double)sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);\
d = 1.0/d;\
v[0] = v[0] * d;\
v[1] = v[1] * d;\
v[2] = v[2] * d;

#define s_curve(t) ( t * t * (3.0 - 2.0 * t) )
#define lerp(t, a, b) ( a + t * (b - a) )

#define setup(vecIn,b0,b1,r0,r1)\
t = vecIn + PERLIN_N_FAST;\
b0 = (((int)t) & PERLIN_BM_FAST);\
b1 = ((b0+1) & PERLIN_BM_FAST);\
r0 = t - (int)t;\
r1 = r0 - 1.0;


double spNoiseRand(SPNoise* noise)
{
	unsigned long y;

	if(--noise->left == 0)
	{
		unsigned long *p=noise->state;
		int j;

		noise->left = RANDOM_N;
		noise->next = noise->state;

		for (j=RANDOM_N-RANDOM_M+1; --j; p++) 
			*p = p[RANDOM_M] ^ TWIST(p[0], p[1]);

		for (j=RANDOM_M; --j; p++) 
			*p = p[RANDOM_M-RANDOM_N] ^ TWIST(p[0], p[1]);

		*p = p[RANDOM_M-RANDOM_N] ^ TWIST(p[0], noise->state[0]);
	}
	y = *noise->next++;

	y ^= (y >> 11);
	y ^= (y << 7) & 0x9d2c5680UL;
	y ^= (y << 15) & 0xefc60000UL;
	y ^= (y >> 18);

	return (double)y * (1.0/4294967295.0); 
}

SPNoise* spNoiseNew(int seed, double persistance)
{
	SPNoise* noise = (SPNoise*)malloc(sizeof(SPNoise));

	noise->persistance = persistance;
	noise->p = (int*)malloc(sizeof(int) * (SPN_SAMPLE_SIZE + SPN_SAMPLE_SIZE + 2));
	noise->g3 = (double*)malloc(sizeof(double) * (SPN_SAMPLE_SIZE + SPN_SAMPLE_SIZE + 2) * 3);

	noise->state[0]= seed & 0xffffffffUL;
	for (int j=1; j<RANDOM_N; j++) {
		noise->state[j] = (1812433253UL * (noise->state[j-1] ^ (noise->state[j-1] >> 30)) + j); 
		noise->state[j] &= 0xffffffffUL; 
	}
	noise->left = 1; 

	int i, j, k;

	for (i = 0 ; i < PERLIN_B_FAST ; i++)
	{
		noise->p[i] = i;
		for (j = 0 ; j < 3 ; j++)
			noise->g3[i * 3 + j] = (double)((spNoiseRand(noise) * (PERLIN_B_FAST + PERLIN_B_FAST)) - PERLIN_B_FAST) / PERLIN_B_FAST;
		double* vec = &(noise->g3[i * 3]);
		normalize3(vec);
	}

	while (--i)
	{
		k = noise->p[i];
		noise->p[i] = noise->p[j = (int)(spNoiseRand(noise) * PERLIN_B_FAST)];
		noise->p[j] = k;
	}

	for (i = 0 ; i < PERLIN_B_FAST + 2 ; i++)
	{
		noise->p[PERLIN_B_FAST + i] = noise->p[i];
		for (j = 0 ; j < 3 ; j++)
			noise->g3[(PERLIN_B_FAST + i) *3 + j] = noise->g3[i * 3 + j];
	}

	return noise;
}

void spNoiseDelete(SPNoise* noise)
{
	free(noise->p);
	free(noise->g3);
	free(noise);
}

double noise3DPrivate(SPNoise* noise, SPVec3 vec)
{
	int bx0, bx1, by0, by1, bz0, bz1, b00, b10, b01, b11;
	double rx0, rx1, ry0, ry1, rz0, rz1, *q, sy, sz, a, b, c, d, t, u, v;
	int i, j;

	int* p = noise->p;
	double* g3 = noise->g3;

	setup(vec.x,bx0,bx1,rx0,rx1);
	setup(vec.y,by0,by1,ry0,ry1);
	setup(vec.z,bz0,bz1,rz0,rz1);

	i = p[ bx0 ];
	j = p[ bx1 ];

	b00 = p[ i + by0 ];
	b10 = p[ j + by0 ];
	b01 = p[ i + by1 ];
	b11 = p[ j + by1 ];

	t  = s_curve(rx0);
	sy = s_curve(ry0);
	sz = s_curve(rz0);

#define at3(rx,ry,rz) ( rx * q[0] + ry * q[1] + rz * q[2] )

	q = &(g3[ (b00 + bz0) * 3 ]) ; u = at3(rx0,ry0,rz0);
	q = &(g3[ (b10 + bz0) * 3 ]) ; v = at3(rx1,ry0,rz0);
	a = lerp(t, u, v);

	q = &(g3[ (b01 + bz0) * 3 ]); u = at3(rx0,ry1,rz0);
	q = &(g3[ (b11 + bz0) * 3 ]); v = at3(rx1,ry1,rz0);
	b = lerp(t, u, v);

	c = lerp(sy, a, b);

	q = &(g3[ (b00 + bz1) * 3 ]); u = at3(rx0,ry0,rz1);
	q = &(g3[ (b10 + bz1) * 3 ]); v = at3(rx1,ry0,rz1);
	a = lerp(t, u, v);

	q = &(g3[ (b01 + bz1) * 3 ]); u = at3(rx0,ry1,rz1);
	q = &(g3[ (b11 + bz1) * 3 ]); v = at3(rx1,ry1,rz1);
	b = lerp(t, u, v);

	d = lerp(sy, a, b);

	return lerp(sz, c, d);
}


double noise3DPrivateWithRate(SPNoise* noise, SPVec3 vec, SPVec3* rateOfChange) //this is untested, unused for now.
{
	int bx0, bx1, by0, by1, bz0, bz1, b00, b10, b01, b11;
	double rx0, rx1, ry0, ry1, rz0, rz1, *q, sy, sz, a, b, c, d, t;
	double uv000, uv100, uv010, uv110, uv001, uv101, uv011, uv111;
	int i, j;

	double rateA,rateB,rateC, rateD;

	int* p = noise->p;
	double* g3 = noise->g3;

	setup(vec.x,bx0,bx1,rx0,rx1);
	setup(vec.y,by0,by1,ry0,ry1);
	setup(vec.z,bz0,bz1,rz0,rz1);

	i = p[ bx0 ];
	j = p[ bx1 ];

	b00 = p[ i + by0 ];
	b10 = p[ j + by0 ];
	b01 = p[ i + by1 ];
	b11 = p[ j + by1 ];

	t  = s_curve(rx0);
	sy = s_curve(ry0);
	sz = s_curve(rz0);

#define at3(rx,ry,rz) ( rx * q[0] + ry * q[1] + rz * q[2] )

	q = &(g3[ (b00 + bz0) * 3 ]) ; uv000 = at3(rx0,ry0,rz0);
	q = &(g3[ (b10 + bz0) * 3 ]) ; uv100 = at3(rx1,ry0,rz0);
	a = lerp(t, uv000, uv100);

	q = &(g3[ (b01 + bz0) * 3 ]); uv010 = at3(rx0,ry1,rz0);
	q = &(g3[ (b11 + bz0) * 3 ]); uv110 = at3(rx1,ry1,rz0);
	b = lerp(t, uv010, uv110);

	c = lerp(sy, a, b);

	q = &(g3[ (b00 + bz1) * 3 ]); uv001 = at3(rx0,ry0,rz1);
	q = &(g3[ (b10 + bz1) * 3 ]); uv101 = at3(rx1,ry0,rz1);
	a = lerp(t, uv001, uv101);

	q = &(g3[ (b01 + bz1) * 3 ]); uv011 = at3(rx0,ry1,rz1);
	q = &(g3[ (b11 + bz1) * 3 ]); uv111 = at3(rx1,ry1,rz1);
	b = lerp(t, uv011, uv111);

	d = lerp(sy, a, b);

	rateA = fabs(uv100-uv000);
	rateB = fabs(uv110-uv010);

	rateC = lerp(sy, rateA, rateB);

	rateA = fabs(uv101-uv001);
	rateB = fabs(uv111-uv011);

	rateD = lerp(sy, rateA, rateB);

	(*rateOfChange).x = lerp(sz, rateC, rateD);


	rateA = fabs(uv010-uv000);
	rateB = fabs(uv110-uv100);

	rateC = lerp(t, rateA, rateB);

	rateA = fabs(uv011-uv001);
	rateB = fabs(uv111-uv101);

	rateD = lerp(sz, rateA, rateB);

	(*rateOfChange).y = lerp(sz, rateC, rateD);

	rateA = fabs(uv001-uv000);
	rateB = fabs(uv101-uv100);

	rateC = lerp(t, rateA, rateB);

	rateA = fabs(uv011-uv010);
	rateB = fabs(uv111-uv110);

	rateD = lerp(t, rateA, rateB);

	(*rateOfChange).z = lerp(sy, rateC, rateD);

	return lerp(sz, c, d);
}

double spNoiseGet(SPNoise* noise, SPVec3 vec, int endOctave)
{
	if(endOctave <= 1)
	{
		return noise3DPrivate(noise, vec);
	}
	double result = 0.0;
	double amp = 1.0;

	for(int i = 0; i<endOctave; i++ )
	{
		result += noise3DPrivate(noise, vec) * amp;
		vec.x *= 2.0;
		vec.y *= 2.0;
		vec.z *= 2.0;
		amp*=noise->persistance;
	}

	return result;
}

double spNoiseGetWithChangeRate(SPNoise* noise, SPVec3 vec, int endOctave, SPVec3* rateOfChange) //this is untested, unused for now.
{
	if(endOctave <= 1)
	{
		return noise3DPrivateWithRate(noise, vec, rateOfChange);
	}
	double result = 0.0;
	double amp = 1.0;

	for(int i = 0; i<endOctave; i++ )
	{
		SPVec3 thisRateOfChange;
		result += noise3DPrivateWithRate(noise, vec, &thisRateOfChange) * amp;

		(*rateOfChange).x = (*rateOfChange).x + thisRateOfChange.x * amp;
		(*rateOfChange).y = (*rateOfChange).y + thisRateOfChange.y * amp;
		(*rateOfChange).z = (*rateOfChange).z + thisRateOfChange.z * amp;

		vec.x *= 2.0;
		vec.y *= 2.0;
		vec.z *= 2.0;
		amp*=noise->persistance;
	}

	return result;
}

double spNoiseGetRangedFraction(SPNoise* noise, SPVec3 vec, int endOctave)
{
	double rawValue = spNoiseGet(noise, vec, endOctave);
	return spClamp(rawValue * rawValue * 8.0, 0.0, 1.0);
}

bool spNoiseGetChance(SPNoise* noise,
	SPVec3 vec,
	int endOctave,
	uint32_t chanceNumerator,
	uint32_t chanceDenominator,
	uint64_t uniqueID,
	uint32_t seed)
{
	double rangedFractionValue = spNoiseGetRangedFraction(noise, vec, endOctave);
	uint32_t randomValue = spRandomIntegerValueForUniqueIDAndSeed(uniqueID, seed, chanceDenominator * 1000);
	bool win = (randomValue < rangedFractionValue * chanceNumerator * 1000);
	return win;
}