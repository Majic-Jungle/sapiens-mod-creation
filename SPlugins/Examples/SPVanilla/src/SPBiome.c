

#include "SPBiome.h"



int spBiomeGetBiomeType(int climateType)
{
	return climateType;
}

#define isBeach(_altitude_) ((_altitude_) < 0.0000001)
#define rockSteepness 0.2

int spBiomeGetSurfaceType(SPNoise* noise, 
	SPBiomeType* biomeTypes,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	int biomeType, 
	int vegetationState, 
	double altitude,
	float steepness,
	float riverDistance)
{
	if(vegetationState == 1)
	{
		if(isBeach(altitude))
		{
			return biomeTypes[biomeType].beachTerrainType;
		}
			
		return biomeTypes[biomeType].vegetationStrippedTerrainType;
	}

	SPVec3 scaledNoiseLoc = spVec3Mul(noiseLoc, 599999.0);
	double noiseValue = spNoiseGet(noise, scaledNoiseLoc, 4);

	if(steepness > rockSteepness + noiseValue * 0.2)
	{
		return biomeTypes[biomeType].rockTerrainType;
	}

	if(isBeach(altitude))
	{
		return biomeTypes[biomeType].beachTerrainType;
	}

	if(steepness > noiseValue + 0.5)
	{
		return biomeTypes[biomeType].vegetationStrippedTerrainType;
	}

	if(biomeTypes[biomeType].secondaryTerrainType != 0 && noiseValue > 0.0)
	{
		return biomeTypes[biomeType].secondaryTerrainType;
	}

	return biomeTypes[biomeType].normalTerrainType;
}