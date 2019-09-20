

#include "SPBiome.h"
#include <string.h>

static uint16_t biomeTag_cold;
static uint16_t biomeTag_hot;
static uint16_t biomeTag_wet;
static uint16_t biomeTag_dry;
static uint16_t biomeTag_desert;
static uint16_t biomeTag_steppe;
static uint16_t biomeTag_rainforest;
static uint16_t biomeTag_tropical;
static uint16_t biomeTag_monsoon;
static uint16_t biomeTag_savanna;
static uint16_t biomeTag_polar;
static uint16_t biomeTag_icecap;
static uint16_t biomeTag_tundra;
static uint16_t biomeTag_temperate;
static uint16_t biomeTag_coldWinter;
static uint16_t biomeTag_drySummer;
static uint16_t biomeTag_dryWinter;
static uint16_t biomeTag_lightForest;
static uint16_t biomeTag_denseForest;
static uint16_t biomeTag_plains;

static uint16_t terrainType_tundraGrass;
static uint16_t terrainType_rock;
static uint16_t terrainType_beachSand;
static uint16_t terrainType_gravel;
static uint16_t terrainType_water;
static uint16_t terrainType_desertSand;
static uint16_t terrainType_steppeMostlyGrass;
static uint16_t terrainType_steppeMostlyDirt;
static uint16_t terrainType_tropicalRainforestGrass;
static uint16_t terrainType_monsoonGrass;
static uint16_t terrainType_savannaGrass;
static uint16_t terrainType_iceCap;
static uint16_t terrainType_desertRedSand;
static uint16_t terrainType_taigaGrass;
static uint16_t terrainType_mediterraneanGrass;
static uint16_t terrainType_temperateGrass;
static uint16_t terrainType_redRock;
static uint16_t terrainType_dirt;


void spBiomeInit(SPBiomeThreadState* threadState)
{
	biomeTag_cold = threadState->getBiomeTag(threadState->managerObject, "cold");
	biomeTag_hot = threadState->getBiomeTag(threadState->managerObject, "hot");
	biomeTag_wet = threadState->getBiomeTag(threadState->managerObject, "wet");
	biomeTag_dry = threadState->getBiomeTag(threadState->managerObject, "dry");
	biomeTag_desert = threadState->getBiomeTag(threadState->managerObject, "desert");
	biomeTag_steppe = threadState->getBiomeTag(threadState->managerObject, "steppe");
	biomeTag_rainforest = threadState->getBiomeTag(threadState->managerObject, "rainforest");
	biomeTag_tropical = threadState->getBiomeTag(threadState->managerObject, "tropical");
	biomeTag_monsoon = threadState->getBiomeTag(threadState->managerObject, "monsoon");
	biomeTag_savanna = threadState->getBiomeTag(threadState->managerObject, "savanna");
	biomeTag_polar = threadState->getBiomeTag(threadState->managerObject, "polar");
	biomeTag_icecap = threadState->getBiomeTag(threadState->managerObject, "icecap");
	biomeTag_tundra = threadState->getBiomeTag(threadState->managerObject, "tundra");
	biomeTag_temperate = threadState->getBiomeTag(threadState->managerObject, "temperate");
	biomeTag_coldWinter = threadState->getBiomeTag(threadState->managerObject, "coldWinter");
	biomeTag_drySummer = threadState->getBiomeTag(threadState->managerObject, "drySummer");
	biomeTag_dryWinter = threadState->getBiomeTag(threadState->managerObject, "dryWinter");
	biomeTag_lightForest = threadState->getBiomeTag(threadState->managerObject, "lightForest");
	biomeTag_denseForest = threadState->getBiomeTag(threadState->managerObject, "denseForest");
	biomeTag_plains = threadState->getBiomeTag(threadState->managerObject, "plains");


	terrainType_tundraGrass = threadState->getTerrainTypeIndex(threadState->managerObject, "tundraGrass");
	terrainType_rock = threadState->getTerrainTypeIndex(threadState->managerObject, "rock");
	terrainType_beachSand = threadState->getTerrainTypeIndex(threadState->managerObject, "beachSand");
	terrainType_gravel = threadState->getTerrainTypeIndex(threadState->managerObject, "gravel");
	terrainType_water = threadState->getTerrainTypeIndex(threadState->managerObject, "water");
	terrainType_desertSand = threadState->getTerrainTypeIndex(threadState->managerObject, "steppeMostlyGrass");
	terrainType_steppeMostlyGrass = threadState->getTerrainTypeIndex(threadState->managerObject, "steppeMostlyDirt");
	terrainType_steppeMostlyDirt = threadState->getTerrainTypeIndex(threadState->managerObject, "tundraGrass");
	terrainType_tropicalRainforestGrass = threadState->getTerrainTypeIndex(threadState->managerObject, "tropicalRainforestGrass");
	terrainType_monsoonGrass = threadState->getTerrainTypeIndex(threadState->managerObject, "monsoonGrass");
	terrainType_savannaGrass = threadState->getTerrainTypeIndex(threadState->managerObject, "savannaGrass");
	terrainType_iceCap = threadState->getTerrainTypeIndex(threadState->managerObject, "iceCap");
	terrainType_desertRedSand = threadState->getTerrainTypeIndex(threadState->managerObject, "desertRedSand");
	terrainType_taigaGrass = threadState->getTerrainTypeIndex(threadState->managerObject, "taigaGrass");
	terrainType_mediterraneanGrass = threadState->getTerrainTypeIndex(threadState->managerObject, "mediterraneanGrass");
	terrainType_temperateGrass = threadState->getTerrainTypeIndex(threadState->managerObject, "temperateGrass");
	terrainType_redRock = threadState->getTerrainTypeIndex(threadState->managerObject, "redRock");
	terrainType_dirt = threadState->getTerrainTypeIndex(threadState->managerObject, "dirt");
}

void spBiomeGetTagsForPoint(SPBiomeThreadState* threadState,
	uint16_t* tagsOut,
	int* tagCountOut,
	SPVec3 pointNormal,
	SPVec3 noiseLoc,
	double altitude,
	float riverDistance,
	float temperatureSummer,
	float temperatureWinter,
	float rainfallSummer,
	float rainfallWinter)
{
	int tagCount = *tagCountOut;

	float annualRainfall = rainfallSummer + rainfallWinter;
	float averageTemp = (temperatureSummer + temperatureWinter) * 0.5f;
	float temperatureThreshold = averageTemp * 20.0f;

	if (rainfallSummer > rainfallWinter * 2.3f)
	{
		temperatureThreshold = temperatureThreshold + 280.0f;
	}
	else if (rainfallWinter < rainfallSummer * 2.3f)
	{
		temperatureThreshold = temperatureThreshold + 140.0f;
	}

	if (annualRainfall < temperatureThreshold) // B
	{
		tagsOut[tagCount++] = biomeTag_dry;

		if (annualRainfall < temperatureThreshold * 0.5)
		{
			tagsOut[tagCount++] = biomeTag_desert;
		}
		else
		{
			tagsOut[tagCount++] = biomeTag_steppe;
		}

		if (averageTemp >= 18.0f)
		{
			tagsOut[tagCount++] = biomeTag_hot;
		}
		else
		{
			tagsOut[tagCount++] = biomeTag_cold;
		}
	}
	else
	{
		if (temperatureWinter > 18.0f) // A
		{
			tagsOut[tagCount++] = biomeTag_tropical;

			float driestMonth = (float)spMin(rainfallSummer, rainfallWinter) / 6.0f;
			if (driestMonth > 60.0f)
			{
				tagsOut[tagCount++] = biomeTag_rainforest;
			}
			else if (driestMonth > (100.0f - (annualRainfall / 25.0f)))
			{
				tagsOut[tagCount++] = biomeTag_monsoon;
			}
			else
			{
				tagsOut[tagCount++] = biomeTag_savanna;
			}
		}
		else
		{
			if (temperatureSummer < -2.0f)// EF
			{
				tagsOut[tagCount++] = biomeTag_polar;
				tagsOut[tagCount++] = biomeTag_icecap;
			}
			else if (temperatureSummer < 8.0f)// ET
			{
				tagsOut[tagCount++] = biomeTag_polar;
				tagsOut[tagCount++] = biomeTag_tundra;
			}
			else // C or D
			{
				tagsOut[tagCount++] = biomeTag_temperate;

				if (temperatureWinter < -5.0f)
				{
					tagsOut[tagCount++] = biomeTag_coldWinter;
				}

				if (rainfallSummer < 30.0f && rainfallSummer < rainfallWinter / 3.0f)
				{
					tagsOut[tagCount++] = biomeTag_drySummer;
				}
				else if (rainfallWinter < rainfallSummer / 10.0f)
				{
					tagsOut[tagCount++] = biomeTag_dryWinter;
				}
			}
		}
	}

	*tagCountOut = tagCount;
}

#define rockSteepness 0.2

uint16_t spBiomeGetSurfaceTypeForPoint(SPBiomeThreadState* threadState,
	uint16_t incomingType,
	uint16_t* tags,
	int tagCount,
	SPVec3 pointNormal,
	SPVec3 noiseLoc,
	double altitude,
	float steepness,
	float riverDistance,
	int vegetationState)
{
	bool isBeach = ((altitude) < 0.0000001);
	if(isBeach)
	{
		return terrainType_beachSand;
	}

	if(vegetationState == 1)
	{
		return terrainType_dirt;
	}


	SPVec3 scaledNoiseLoc = spVec3Mul(noiseLoc, 599999.0);
	double noiseValue = spNoiseGet(threadState->spNoise1, scaledNoiseLoc, 4);

	bool isRock = (steepness > rockSteepness + noiseValue * 0.2);
	bool isSecondary = (noiseValue > 0.0);
	bool isDirt = (steepness > noiseValue + 0.5);


	for(int i = 0; i < tagCount; i++)
	{
		if(tags[i] == biomeTag_desert)
		{
			if(isRock)
			{
				return terrainType_redRock;
			}
			for(int j = 0; j < tagCount; j++)
			{
				if(tags[j] == biomeTag_hot)
				{
					return terrainType_desertRedSand;
				}
			}
			return terrainType_desertSand;
		}
		if(tags[i] == biomeTag_steppe)
		{
			for(int j = 0; j < tagCount; j++)
			{
				if(tags[j] == biomeTag_hot)
				{
					if(isRock)
					{
						return terrainType_redRock;
					}
					if(isDirt)
					{
						return terrainType_dirt;
					}
					return terrainType_steppeMostlyDirt;
				}
			}
			if(isRock)
			{
				return terrainType_rock;
			}
			if(isDirt)
			{
				return terrainType_dirt;
			}
			return terrainType_steppeMostlyGrass;
		}
		if(tags[i] == biomeTag_rainforest)
		{
			if(isRock)
			{
				return terrainType_rock;
			}
			if(isDirt)
			{
				return terrainType_dirt;
			}
			return terrainType_tropicalRainforestGrass;
		}
		if(tags[i] == biomeTag_monsoon)
		{
			if(isRock)
			{
				return terrainType_rock;
			}
			if(isDirt)
			{
				return terrainType_dirt;
			}
			return terrainType_monsoonGrass;
		}
		if(tags[i] == biomeTag_savanna)
		{
			if(isRock)
			{
				return terrainType_rock;
			}
			if(isDirt)
			{
				return terrainType_dirt;
			}
			return terrainType_savannaGrass;
		}
		if(tags[i] == biomeTag_icecap)
		{
			if(isRock)
			{
				return terrainType_rock;
			}
			if(isDirt)
			{
				return terrainType_dirt;
			}
			return terrainType_iceCap;
		}
		if(tags[i] == biomeTag_tundra)
		{
			if(isRock)
			{
				return terrainType_rock;
			}
			if(isSecondary)
			{
				return terrainType_iceCap;
			}
			if(isDirt)
			{
				return terrainType_dirt;
			}
			return terrainType_tundraGrass;
		}
		if(tags[i] == biomeTag_temperate)
		{
			if(isRock)
			{
				return terrainType_rock;
			}
			if(isDirt)
			{
				return terrainType_dirt;
			}
			for(int j = 0; j < tagCount; j++)
			{
				if(tags[j] == biomeTag_coldWinter)
				{
					return terrainType_taigaGrass;
				}
				if(tags[j] == biomeTag_drySummer)
				{
					return terrainType_mediterraneanGrass;
				}
			}

			return terrainType_temperateGrass;
		}
	}



	if(isRock)
	{
		return terrainType_rock;
	}
	if(isDirt)
	{
		return terrainType_dirt;
	}


	return terrainType_dirt;
}

/*
int spBiomeGetClimate(float temperatureSummer, 
	float temperatureWinter, 
	float rainfallSummer, 
	float rainfallWinter)
{
	float annualRainfall = rainfallSummer + rainfallWinter;
	float averageTemp = (temperatureSummer + temperatureWinter) * 0.5f;
	float temperatureThreshold = averageTemp * 20.0f;

	if(rainfallSummer > rainfallWinter * 2.3f)
	{
		temperatureThreshold = temperatureThreshold + 280.0f;
	}
	else if(rainfallWinter < rainfallSummer * 2.3f)
	{
		temperatureThreshold = temperatureThreshold + 140.0f;
	}

	if(annualRainfall < temperatureThreshold) // B
	{
		if(annualRainfall < temperatureThreshold * 0.5)
		{
			if(averageTemp >= 18.0f)
			{
				return spc_aridDesertHot;
			}
			else
			{
				return spc_aridDesertCold;
			}
		}
		else
		{
			if(averageTemp >= 18.0f)
			{
				return spc_aridSteppeHot;
			}
			else
			{
				return spc_aridSteppeCold;
			}
		}
	}
	else
	{
		if(temperatureWinter > 18.0f) // A
		{
			float driestMonth = (float)spMin(rainfallSummer, rainfallWinter) / 6.0f;
			if(driestMonth > 60.0f)
			{
				return  spc_tropicalRainforest;
			}
			else if(driestMonth > (100.0f - (annualRainfall / 25.0f)) )
			{
				return  spc_tropicalMonsoon;
			}
			else
			{
				return  spc_tropicalSavanna;
			}
		}
		else
		{
			if(temperatureSummer < -2.0f)// EF
			{
				return  spc_polarIceCap;
			}
			else if(temperatureSummer < 8.0f)// ET
			{
				return  spc_polarTundra;
			}
			else // C or D
			{
				if(rainfallSummer < 30.0f && rainfallSummer < rainfallWinter / 3.0f)
				{
					if(temperatureWinter < -5.0f)
					{
						return spc_coldDrySummer;
					}
					else
					{
						return spc_temperateDrySummer;
					}
				}
				else if(rainfallWinter < rainfallSummer / 10.0f)
				{
					if(temperatureWinter < -5.0f)
					{
						return spc_coldDryWinter;
					}
					else
					{
						return spc_temperateDryWinter;
					}
				}
				else
				{
					if(temperatureWinter < -5.0f)
					{
						return spc_coldWetHotSummer;
					}
					else
					{
						return spc_temperateWetHotSummer;
					}
				}
			}
		}
	}

}



int spBiomeGetBiomeType(int climateType)
{
	return climateType;
}


#define isBeach(_altitude_) ((_altitude_) < 0.0000001)
#define rockSteepness 0.2

int spBiomeGetSurfaceType(SPNoise* noise, 
	SPBiomeType* biomeType,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc,
	int vegetationState, 
	double altitude,
	float steepness,
	float riverDistance)
{
	if(vegetationState == 1)
	{
		if(isBeach(altitude))
		{
			return biomeType->beachTerrainType;
		}
			
		return biomeType->vegetationStrippedTerrainType;
	}

	SPVec3 scaledNoiseLoc = spVec3Mul(noiseLoc, 599999.0);
	double noiseValue = spNoiseGet(noise, scaledNoiseLoc, 4);

	if(steepness > rockSteepness + noiseValue * 0.2)
	{
		return biomeType->rockTerrainType;
	}

	if(isBeach(altitude))
	{
		return biomeType->beachTerrainType;
	}

	if(steepness > noiseValue + 0.5)
	{
		return biomeType->vegetationStrippedTerrainType;
	}

	if(biomeType->secondaryTerrainType != 0 && noiseValue > 0.0)
	{
		return biomeType->secondaryTerrainType;
	}

	return biomeType->normalTerrainType;
}*/