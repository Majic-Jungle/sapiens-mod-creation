

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
static uint16_t biomeTag_verySparseForest;
static uint16_t biomeTag_sparseForest;
static uint16_t biomeTag_mediumForest;
static uint16_t biomeTag_denseForest;
static uint16_t biomeTag_coniferous;
static uint16_t biomeTag_birch;

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

static uint16_t gameObjectType_appleTree1;

#define BIRCH_TYPE_COUNT 4
static uint16_t gameObjectType_birchTypes[BIRCH_TYPE_COUNT];

#define PINE_TYPE_COUNT 3
static uint16_t gameObjectType_pineTypes[PINE_TYPE_COUNT];

void spBiomeInit(SPBiomeThreadState* threadState)
{
	biomeTag_cold = threadState->getBiomeTag(threadState, "cold");
	biomeTag_hot = threadState->getBiomeTag(threadState, "hot");
	biomeTag_wet = threadState->getBiomeTag(threadState, "wet");
	biomeTag_dry = threadState->getBiomeTag(threadState, "dry");
	biomeTag_desert = threadState->getBiomeTag(threadState, "desert");
	biomeTag_steppe = threadState->getBiomeTag(threadState, "steppe");
	biomeTag_rainforest = threadState->getBiomeTag(threadState, "rainforest");
	biomeTag_tropical = threadState->getBiomeTag(threadState, "tropical");
	biomeTag_monsoon = threadState->getBiomeTag(threadState, "monsoon");
	biomeTag_savanna = threadState->getBiomeTag(threadState, "savanna");
	biomeTag_polar = threadState->getBiomeTag(threadState, "polar");
	biomeTag_icecap = threadState->getBiomeTag(threadState, "icecap");
	biomeTag_tundra = threadState->getBiomeTag(threadState, "tundra");
	biomeTag_temperate = threadState->getBiomeTag(threadState, "temperate");
	biomeTag_coldWinter = threadState->getBiomeTag(threadState, "coldWinter");
	biomeTag_drySummer = threadState->getBiomeTag(threadState, "drySummer");
	biomeTag_dryWinter = threadState->getBiomeTag(threadState, "dryWinter");
	biomeTag_verySparseForest = threadState->getBiomeTag(threadState, "verySparseForest");
	biomeTag_sparseForest = threadState->getBiomeTag(threadState, "sparseForest");
	biomeTag_mediumForest = threadState->getBiomeTag(threadState, "mediumForest");
	biomeTag_denseForest = threadState->getBiomeTag(threadState, "denseForest");
	biomeTag_coniferous = threadState->getBiomeTag(threadState, "coniferous");
	biomeTag_birch = threadState->getBiomeTag(threadState, "birch");

	terrainType_tundraGrass = threadState->getTerrainTypeIndex(threadState, "tundraGrass");
	terrainType_rock = threadState->getTerrainTypeIndex(threadState, "rock");
	terrainType_beachSand = threadState->getTerrainTypeIndex(threadState, "beachSand");
	terrainType_gravel = threadState->getTerrainTypeIndex(threadState, "gravel");
	terrainType_water = threadState->getTerrainTypeIndex(threadState, "water");
	terrainType_desertSand = threadState->getTerrainTypeIndex(threadState, "desertSand");
	terrainType_steppeMostlyGrass = threadState->getTerrainTypeIndex(threadState, "steppeMostlyGrass");
	terrainType_steppeMostlyDirt = threadState->getTerrainTypeIndex(threadState, "steppeMostlyDirt");
	terrainType_tundraGrass = threadState->getTerrainTypeIndex(threadState, "tundraGrass");
	terrainType_tropicalRainforestGrass = threadState->getTerrainTypeIndex(threadState, "tropicalRainforestGrass");
	terrainType_monsoonGrass = threadState->getTerrainTypeIndex(threadState, "monsoonGrass");
	terrainType_savannaGrass = threadState->getTerrainTypeIndex(threadState, "savannaGrass");
	terrainType_iceCap = threadState->getTerrainTypeIndex(threadState, "iceCap");
	terrainType_desertRedSand = threadState->getTerrainTypeIndex(threadState, "desertRedSand");
	terrainType_taigaGrass = threadState->getTerrainTypeIndex(threadState, "taigaGrass");
	terrainType_mediterraneanGrass = threadState->getTerrainTypeIndex(threadState, "mediterraneanGrass");
	terrainType_temperateGrass = threadState->getTerrainTypeIndex(threadState, "temperateGrass");
	terrainType_redRock = threadState->getTerrainTypeIndex(threadState, "redRock");
	terrainType_dirt = threadState->getTerrainTypeIndex(threadState, "dirt");

	if(threadState->getGameObjectTypeIndex) //this function isn't set where game object types aren't required eg. in the initial world creation screen
	{
		gameObjectType_appleTree1 = threadState->getGameObjectTypeIndex(threadState, "appleTree1");

		gameObjectType_birchTypes[0] = threadState->getGameObjectTypeIndex(threadState, "birch1");
		gameObjectType_birchTypes[1] = threadState->getGameObjectTypeIndex(threadState, "birch2");
		gameObjectType_birchTypes[2] = threadState->getGameObjectTypeIndex(threadState, "birch3");
		gameObjectType_birchTypes[3] = threadState->getGameObjectTypeIndex(threadState, "birch4");

		gameObjectType_pineTypes[0] = threadState->getGameObjectTypeIndex(threadState, "pine1");
		gameObjectType_pineTypes[1] = threadState->getGameObjectTypeIndex(threadState, "pine2");
		gameObjectType_pineTypes[2] = threadState->getGameObjectTypeIndex(threadState, "pine3");
	}
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

				SPVec3 scaledNoiseLoc = spVec3Mul(noiseLoc, 2000.0);
				double noiseValue = spNoiseGet(threadState->spNoise1, scaledNoiseLoc, 4);
				if(noiseValue > 0.0)
				{
					if(noiseValue > 0.3)
					{
						tagsOut[tagCount++] = biomeTag_sparseForest;
					}
					else
					{
						tagsOut[tagCount++] = biomeTag_verySparseForest;
					}
					tagsOut[tagCount++] = biomeTag_coniferous;
				}
			}
			else // C or D
			{
				tagsOut[tagCount++] = biomeTag_temperate;

				SPVec3 scaledNoiseLoc = spVec3Mul(noiseLoc, 2000.0);
				double noiseValue = spNoiseGet(threadState->spNoise1, scaledNoiseLoc, 4);
				if(noiseValue > -0.2)
				{
					if(noiseValue > 0.3)
					{
						tagsOut[tagCount++] = biomeTag_denseForest;
					}
					else if(noiseValue > 0.0)
					{
						tagsOut[tagCount++] = biomeTag_mediumForest;
					}
					else
					{
						tagsOut[tagCount++] = biomeTag_sparseForest;
					}
				}
				else
				{
					tagsOut[tagCount++] = biomeTag_verySparseForest;
				}

				if (temperatureWinter < -5.0f)
				{
					tagsOut[tagCount++] = biomeTag_coldWinter;
				}

				SPVec3 scaledNoiseLocB = spVec3Mul(noiseLoc, 5501.0);
				double noiseValueB = spNoiseGet(threadState->spNoise1, scaledNoiseLocB, 4);
				if(temperatureSummer > noiseValueB * 2.0 + 10.0f)
				{
					tagsOut[tagCount++] = biomeTag_birch;
					if(temperatureWinter < noiseValueB * 5.0 - 5.0f)
					{
						tagsOut[tagCount++] = biomeTag_coniferous;
					}
				}
				else
				{
					tagsOut[tagCount++] = biomeTag_coniferous;
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
				/*if(tags[j] == biomeTag_coldWinter)
				{
					return terrainType_taigaGrass;
				}*/
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

int spBiomeGetTransientGameObjectTypesForFaceSubdivision(SPBiomeThreadState* threadState,
	int incomingTypeCount,
	uint16_t* types,
	uint16_t* biomeTags,
	int tagCount,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	uint64_t faceUniqueID, 
	int level, 
	double altitude, 
	float steepness,
	uint16_t terrainType, 
	float riverDistance)
{
	int addedCount = incomingTypeCount;

	if(addedCount < BIOME_MAX_GAME_OBJECT_COUNT_PER_SUBDIVISION)
	{
		if(altitude > 0.0)
		{
			if(level >= SP_SUBDIVISIONS - 6)
			{
				SPVec3 noiseLookupBAddition = {107.6,26.6,89.4};
				SPVec3 noiseLookupMedAddition = {1.25,1.1,1.5};
				SPVec3 noiseLookupHighAddition = {1.2,1.2,1.2};

				SPVec3 noiseLookup = spVec3Mul(noiseLoc, 999.0);
				SPVec3 noiseLookupB = spVec3Add(noiseLookup, noiseLookupBAddition);
				//SPVec3 noiseLookupMedFreq = spVec3Mul(spVec3Add(noiseLookup,noiseLookupMedAddition), 20000.0);
				//SPVec3 noiseLookupHighFreq = spVec3Mul(spVec3Add(noiseLookup,noiseLookupHighAddition), 99999.0);

				if(level == SP_SUBDIVISIONS - 6)
				{
					//double baseDensityNoise = spNoiseGet(threadState->spNoise1, noiseLookupMedFreq, 1);
					//if(baseDensityNoise > -0.1)
					//{
						if(spNoiseGetChance(threadState->spNoise1, noiseLookupB, 3, 1, 2, faceUniqueID, 42))
						{
							types[addedCount++] = gameObjectType_appleTree1;
							if(addedCount >= BIOME_MAX_GAME_OBJECT_COUNT_PER_SUBDIVISION)
							{
								return addedCount;
							}
						}

						int forestDensity = 0;
						bool coniferous = false;
						bool birch = false;
						for(int i = 0; i < tagCount; i++)
						{
							if(biomeTags[i] == biomeTag_denseForest)
							{
								forestDensity = 4;
							}
							else if(biomeTags[i] == biomeTag_mediumForest)
							{
								forestDensity = 3;
							}
							else if(biomeTags[i] == biomeTag_sparseForest)
							{
								forestDensity = 2;
							}
							else if(biomeTags[i] == biomeTag_verySparseForest)
							{
								forestDensity = 1;
							}

							if(biomeTags[i] == biomeTag_coniferous)
							{
								coniferous = true;
							}
							if(biomeTags[i] == biomeTag_birch)
							{
								birch = true;
							}
						}

						int treeCount = 0;
						if(coniferous || birch)
						{
							switch(forestDensity)
							{
							case 0:
								break;
							case 1:
								treeCount = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 3254, 16) - 14;
								break;
							case 2:
								treeCount = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 3254, 8) - 3;
								break;
							case 3:
								treeCount = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 3254, 8) + 1;
								break;
							case 4:
								treeCount = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 3254, 8) + 8;
								break;

							}

							if(coniferous)
							{
								if(birch)
								{
									for(int i = 0; i < treeCount; i++)
									{
										int treeType = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 22245 + i, PINE_TYPE_COUNT + BIRCH_TYPE_COUNT);
										if(treeType < PINE_TYPE_COUNT)
										{
											types[addedCount++] = gameObjectType_pineTypes[treeType];
										}
										else
										{
											types[addedCount++] = gameObjectType_birchTypes[treeType - PINE_TYPE_COUNT];
										}
										if(addedCount >= BIOME_MAX_GAME_OBJECT_COUNT_PER_SUBDIVISION)
										{
											return addedCount;
										}
									}
								}
								else
								{
									for(int i = 0; i < treeCount; i++)
									{
										int pineType = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 22245 + i, PINE_TYPE_COUNT);
										types[addedCount++] = gameObjectType_pineTypes[pineType];
										if(addedCount >= BIOME_MAX_GAME_OBJECT_COUNT_PER_SUBDIVISION)
										{
											return addedCount;
										}
									}
								}
							}
							else
							{
								for(int i = 0; i < treeCount; i++)
								{
									int birchType = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 22245 + i, BIRCH_TYPE_COUNT);
									types[addedCount++] = gameObjectType_birchTypes[birchType];
									if(addedCount >= BIOME_MAX_GAME_OBJECT_COUNT_PER_SUBDIVISION)
									{
										return addedCount;
									}
								}
							}
						}

					//}
				}
			}
		}
	}
	return addedCount;
}