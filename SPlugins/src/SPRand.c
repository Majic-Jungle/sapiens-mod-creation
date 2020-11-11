

#include "SPRand.h"
#include "SPCommon.h"
#include <stdlib.h>


typedef struct SPRand {
	uint32_t seed;
	uint32_t counter;
} SPRand;

// MurmurHash3_x86_32 is public domain taken from MurmurHash3  written by Austin Appleby, https://github.com/aappleby/smhasher/wiki/MurmurHash3

#if defined(_MSC_VER)

#define FORCE_INLINE	__forceinline
#define ROTL32(x,y)	_rotl(x,y)

#else

#define	FORCE_INLINE inline __attribute__((always_inline))

static inline uint32_t rotl32 ( uint32_t x, int8_t r )
{
	return (x << r) | (x >> (32 - r));
}

#define	ROTL32(x,y)	rotl32(x,y)

#endif 


FORCE_INLINE uint32_t fmix32 ( uint32_t h )
{
	h ^= h >> 16;
	h *= 0x85ebca6b;
	h ^= h >> 13;
	h *= 0xc2b2ae35;
	h ^= h >> 16;

	return h;
}

void MurmurHash3_x86_32 ( const void * key, int len,
	uint32_t seed, void * out )
{
	const uint8_t * data = (const uint8_t*)key;
	const int nblocks = len / 4;

	uint32_t h1 = seed;

	const uint32_t c1 = 0xcc9e2d51;
	const uint32_t c2 = 0x1b873593;

	//----------
	// body

	const uint32_t * blocks = (const uint32_t *)(data + nblocks*4);

	for(int i = -nblocks; i; i++)
	{
		uint32_t k1 = blocks[i];

		k1 *= c1;
		k1 = ROTL32(k1,15);
		k1 *= c2;

		h1 ^= k1;
		h1 = ROTL32(h1,13); 
		h1 = h1*5+0xe6546b64;
	}

	//----------
	// tail

	const uint8_t * tail = (const uint8_t*)(data + nblocks*4);

	uint32_t k1 = 0;

	switch(len & 3)
	{
	case 3: k1 ^= tail[2] << 16;
	case 2: k1 ^= tail[1] << 8;
	case 1: k1 ^= tail[0];
		k1 *= c1; k1 = ROTL32(k1,15); k1 *= c2; h1 ^= k1;
	};

	//----------
	// finalization

	h1 ^= len;

	h1 = fmix32(h1);

	*(uint32_t*)out = h1;
} 

double spRandomValueForUniqueIDAndSeed(uint64_t uniqueID, uint32_t seed)
{
	uint32_t hash;
	MurmurHash3_x86_32(&uniqueID, sizeof(uint64_t), seed, &hash);
	double value = hash;
	value = value / UINT32_MAX;
	return value;
}

uint32_t spRandomIntegerValueForUniqueIDAndSeed(uint64_t uniqueID, uint32_t seed, uint32_t max)
{
	uint32_t hash;
	MurmurHash3_x86_32(&uniqueID, sizeof(uint64_t), seed, &hash);
	return hash % max;
}

SPRand* spRandNew(uint32_t seed)
{
	SPRand* spRand = (SPRand*)malloc(sizeof(SPRand));

	spRand->seed = seed;
	spRand->counter = 0;

	return spRand;
}

void spRandDelete(SPRand* spRand)
{
	free(spRand);
}


SPVec3 spRandomVec3ForUniqueID(SPRand* spRand, uint64_t uniqueID)
{
	SPVec3 result = {
		(spRandomValueForUniqueIDAndSeed(uniqueID, spRand->seed) - 0.5) * 2.0,
		(spRandomValueForUniqueIDAndSeed(uniqueID + 8932114, spRand->seed) - 0.5) * 2.0,
		(spRandomValueForUniqueIDAndSeed(uniqueID + 90191230, spRand->seed) - 0.5) * 2.0
	};
	return result;
}

SPVec3 spRandGetVec3(SPRand* spRand)
{
	SPVec3 result = {
		(spRandomValueForUniqueIDAndSeed(spRand->counter++, spRand->seed) - 0.5) * 2.0,
		(spRandomValueForUniqueIDAndSeed(spRand->counter++, spRand->seed) - 0.5) * 2.0,
		(spRandomValueForUniqueIDAndSeed(spRand->counter++, spRand->seed) - 0.5) * 2.0
	};
	return result;
}

double spRandGetValue(SPRand* spRand)
{
	return spRandomValueForUniqueIDAndSeed(spRand->counter++, spRand->seed);
}
