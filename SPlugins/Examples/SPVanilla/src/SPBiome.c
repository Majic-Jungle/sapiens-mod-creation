

#include "SPBiome.h"
#include <string.h>

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
static uint16_t biomeTag_veryColdWinter;
static uint16_t biomeTag_heavySnowWinter;
static uint16_t biomeTag_lightSnowWinter;
static uint16_t biomeTag_heavySnowSummer;
static uint16_t biomeTag_lightSnowSummer;
static uint16_t biomeTag_drySummer;
static uint16_t biomeTag_dryWinter;
static uint16_t biomeTag_verySparseForest;
static uint16_t biomeTag_sparseForest;
static uint16_t biomeTag_mediumForest;
static uint16_t biomeTag_denseForest;
static uint16_t biomeTag_coniferous;
static uint16_t biomeTag_birch;
static uint16_t biomeTag_cliff;
static uint16_t biomeTag_river;

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

static uint16_t terrainVariation_snow;

static uint16_t gameObjectType_appleTree;
static uint16_t gameObjectType_orangeTree;
static uint16_t gameObjectType_peachTree;
static uint16_t gameObjectType_aspen3;
static uint16_t gameObjectType_sunflower;
static uint16_t gameObjectType_raspberryBush;
static uint16_t gameObjectType_gooseberryBush;
static uint16_t gameObjectType_tallPine;

static uint16_t gameObjectType_rock;
static uint16_t gameObjectType_smallRock;
static uint16_t gameObjectType_birchBranch;
static uint16_t gameObjectType_pineBranch;

#define BIRCH_TYPE_COUNT 7
static uint16_t gameObjectType_birchTypes[BIRCH_TYPE_COUNT];

#define MED_PINE_TYPE_COUNT 2
static uint16_t gameObjectType_medPineTypes[MED_PINE_TYPE_COUNT];

#define WILLOW_TYPE_COUNT 2
static uint16_t gameObjectType_willowTypes[WILLOW_TYPE_COUNT];

static uint16_t gameObjectType_smallPine;

void spBiomeInit(SPBiomeThreadState* threadState)
{
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
	biomeTag_veryColdWinter = threadState->getBiomeTag(threadState, "veryColdWinter");
	biomeTag_heavySnowWinter = threadState->getBiomeTag(threadState, "heavySnowWinter");
	biomeTag_lightSnowWinter = threadState->getBiomeTag(threadState, "lightSnowWinter");
	biomeTag_heavySnowSummer = threadState->getBiomeTag(threadState, "heavySnowSummer");
	biomeTag_lightSnowSummer = threadState->getBiomeTag(threadState, "lightSnowSummer");
	biomeTag_drySummer = threadState->getBiomeTag(threadState, "drySummer");
	biomeTag_dryWinter = threadState->getBiomeTag(threadState, "dryWinter");
	biomeTag_verySparseForest = threadState->getBiomeTag(threadState, "verySparseForest");
	biomeTag_sparseForest = threadState->getBiomeTag(threadState, "sparseForest");
	biomeTag_mediumForest = threadState->getBiomeTag(threadState, "mediumForest");
	biomeTag_denseForest = threadState->getBiomeTag(threadState, "denseForest");
	biomeTag_coniferous = threadState->getBiomeTag(threadState, "coniferous");
	biomeTag_birch = threadState->getBiomeTag(threadState, "birch");
	biomeTag_cliff = threadState->getBiomeTag(threadState, "cliff");
	biomeTag_river = threadState->getBiomeTag(threadState, "river");
	

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

	terrainVariation_snow = threadState->getTerrainVariation(threadState, "snow");

	if(threadState->getGameObjectTypeIndex) //this function isn't set where game object types aren't required eg. in the initial world creation screen
	{
		gameObjectType_appleTree = threadState->getGameObjectTypeIndex(threadState, "appleTree");
		gameObjectType_orangeTree = threadState->getGameObjectTypeIndex(threadState, "orangeTree");
		gameObjectType_peachTree = threadState->getGameObjectTypeIndex(threadState, "peachTree");
		gameObjectType_aspen3 = threadState->getGameObjectTypeIndex(threadState, "aspen3");

		gameObjectType_sunflower = threadState->getGameObjectTypeIndex(threadState, "sunflower");
		gameObjectType_raspberryBush = threadState->getGameObjectTypeIndex(threadState, "raspberryBush");
		gameObjectType_gooseberryBush = threadState->getGameObjectTypeIndex(threadState, "gooseberryBush");

		gameObjectType_rock = threadState->getGameObjectTypeIndex(threadState, "rock");
		gameObjectType_smallRock = threadState->getGameObjectTypeIndex(threadState, "smallRock");
		gameObjectType_birchBranch = threadState->getGameObjectTypeIndex(threadState, "birchBranch");
		gameObjectType_pineBranch = threadState->getGameObjectTypeIndex(threadState, "pineBranch");

		gameObjectType_birchTypes[0] = threadState->getGameObjectTypeIndex(threadState, "birch1");
		gameObjectType_birchTypes[1] = threadState->getGameObjectTypeIndex(threadState, "birch2");
		gameObjectType_birchTypes[2] = threadState->getGameObjectTypeIndex(threadState, "birch3");
		gameObjectType_birchTypes[3] = threadState->getGameObjectTypeIndex(threadState, "birch4");
		gameObjectType_birchTypes[4] = threadState->getGameObjectTypeIndex(threadState, "aspen1");
		gameObjectType_birchTypes[5] = threadState->getGameObjectTypeIndex(threadState, "aspenBaby1");
		gameObjectType_birchTypes[6] = threadState->getGameObjectTypeIndex(threadState, "aspen2");

		gameObjectType_willowTypes[0] = threadState->getGameObjectTypeIndex(threadState, "willow1");
		gameObjectType_willowTypes[1] = threadState->getGameObjectTypeIndex(threadState, "willow2");

		gameObjectType_medPineTypes[0] = threadState->getGameObjectTypeIndex(threadState, "pine1");
		gameObjectType_medPineTypes[1] = threadState->getGameObjectTypeIndex(threadState, "pine3");
		gameObjectType_tallPine = threadState->getGameObjectTypeIndex(threadState, "pine2");
		gameObjectType_smallPine = threadState->getGameObjectTypeIndex(threadState, "pine4");
	}
}

void spBiomeGetTagsForPoint(SPBiomeThreadState* threadState,
	uint16_t* tagsOut,
	int* tagCountOut,
	SPVec3 pointNormal,
	SPVec3 noiseLoc,
	double altitude,
	float steepness,
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



	SPVec3 scaledNoiseLocC = spVec3Mul(noiseLoc, 202.0);
	double noiseValueC = spNoiseGet(threadState->spNoise1, scaledNoiseLocC, 4);
	//double riverRainfallAddition = (1.0 - pow(riverDistance, 0.05));
	//riverRainfallAddition = riverRainfallAddition * (0.5 + noiseValueC) * 500.0;
	double riverRainfallAddition = (1.0 - pow(riverDistance, 0.05));
	riverRainfallAddition = riverRainfallAddition * (1.0 + noiseValueC) * 500.0;

	double annualRainfallWithRiverAddition = annualRainfall + riverRainfallAddition;

	if (rainfallSummer > rainfallWinter * 2.3f)
	{
		temperatureThreshold = temperatureThreshold + 280.0f;
	}
	else if (rainfallWinter < rainfallSummer * 2.3f)
	{
		temperatureThreshold = temperatureThreshold + 140.0f;
	}

	bool cliff = false;
	if(steepness > 0.1)
	{
		cliff = true;
		tagsOut[tagCount++] = biomeTag_cliff;
	}


	if(riverDistance < 0.01 && altitude < 0.0000002)
	{
		tagsOut[tagCount++] = biomeTag_river;
	}

	if(averageTemp >= 18.0f)
	{
		tagsOut[tagCount++] = biomeTag_hot;
	}
	else
	{
		if(temperatureWinter < -5.0f)
		{
			tagsOut[tagCount++] = biomeTag_veryColdWinter;
		}
	
		if(annualRainfall > temperatureThreshold * 0.5)
		{
			if(temperatureSummer < 8.0f)
			{
				if(annualRainfall > temperatureThreshold * 2.0)
				{
					tagsOut[tagCount++] = biomeTag_heavySnowSummer;
				}
				else
				{
					tagsOut[tagCount++] = biomeTag_lightSnowSummer;
				}
			}
			else if(temperatureWinter < 8.0f)
			{
				if(annualRainfall > temperatureThreshold * 2.0)
				{
					tagsOut[tagCount++] = biomeTag_heavySnowWinter;
				}
				else
				{
					tagsOut[tagCount++] = biomeTag_lightSnowWinter;
				}
			}
		}
	}



	if (annualRainfallWithRiverAddition < temperatureThreshold) // B
	{
		tagsOut[tagCount++] = biomeTag_dry;

		if (annualRainfallWithRiverAddition < temperatureThreshold * 0.5)
		{
			tagsOut[tagCount++] = biomeTag_desert;
		}
		else
		{
			tagsOut[tagCount++] = biomeTag_steppe;

			if(averageTemp < 18.0f && !cliff)
			{
				SPVec3 scaledNoiseLoc = spVec3Mul(noiseLoc, 2000.0);
				double noiseValue = spNoiseGet(threadState->spNoise1, scaledNoiseLoc, 4);
				if(noiseValue > 0.1)
				{
					tagsOut[tagCount++] = biomeTag_verySparseForest;
					tagsOut[tagCount++] = biomeTag_coniferous;
				}
			}
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

				if(!cliff)
				{
					SPVec3 scaledNoiseLoc = spVec3Mul(noiseLoc, 12000.0);
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
			}
			else // C or D
			{
				tagsOut[tagCount++] = biomeTag_temperate;

				bool drySummer = false;
				if (rainfallSummer < 30.0f && rainfallSummer < rainfallWinter / 3.0f)
				{
					tagsOut[tagCount++] = biomeTag_drySummer;
					drySummer = true;
				}
				else if (rainfallWinter < rainfallSummer / 10.0f)
				{
					tagsOut[tagCount++] = biomeTag_dryWinter;
				}

				if(!cliff)
				{
					SPVec3 scaledNoiseLoc = spVec3Mul(noiseLoc, 12000.0);
					double noiseValue = spNoiseGet(threadState->spNoise1, scaledNoiseLoc, 4);
					if(noiseValue > -0.2)
					{
						if(noiseValue > 0.5)
						{
							tagsOut[tagCount++] = biomeTag_denseForest;
						}
						else if(noiseValue > 0.2)
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


					SPVec3 scaledNoiseLocB = spVec3Mul(noiseLoc, 14501.0);
					double noiseValueB = spNoiseGet(threadState->spNoise1, scaledNoiseLocB, 4);
					if(temperatureSummer > noiseValueB * 4.0 + 2.0f)
					{
						if(!drySummer)
						{
							tagsOut[tagCount++] = biomeTag_birch;
						}
						if(temperatureWinter < noiseValueB * 10.0 - 5.0f)
						{
							tagsOut[tagCount++] = biomeTag_coniferous;
						}
					}
					else
					{
						tagsOut[tagCount++] = biomeTag_coniferous;
					}
				}

			}
		}
	}

	*tagCountOut = tagCount;
}

#define rockSteepness 0.2


typedef struct SurfaceTypeInfo {
	bool river;
	bool hot;
	int snowDepth;
} SurfaceTypeInfo;

void getSurfaceTypeInfo(uint16_t* biomeTags, int tagCount, int seasonIndex, SurfaceTypeInfo* surfaceTypeInfo)
{
	for(int i = 0; i < tagCount; i++)
	{
		if(biomeTags[i] == biomeTag_river)
		{
			surfaceTypeInfo->river = true;
		}
		else if(biomeTags[i] == biomeTag_hot)
		{
			surfaceTypeInfo->hot = true;
		}
		else if(biomeTags[i] == biomeTag_heavySnowSummer)
		{
			surfaceTypeInfo->snowDepth = 2;
		}
		else if(biomeTags[i] == biomeTag_lightSnowSummer)
		{
			if(seasonIndex == 1)
			{
				surfaceTypeInfo->snowDepth = 1;
			}
			else
			{
				surfaceTypeInfo->snowDepth = 2;
			}
		}
		else if(biomeTags[i] == biomeTag_heavySnowWinter)
		{
			if(seasonIndex == 0 || seasonIndex == 2)
			{
				surfaceTypeInfo->snowDepth = 1;
			}
			else if(seasonIndex == 3)
			{
				surfaceTypeInfo->snowDepth = 2;
			}
		}
		else if(biomeTags[i] == biomeTag_lightSnowWinter)
		{
			if(seasonIndex == 3)
			{
				surfaceTypeInfo->snowDepth = 1;
			}
		}
	}
}

SPSurfaceTypeAndVariation spBiomeGetSurfaceTypeForPoint(SPBiomeThreadState* threadState,
	SPSurfaceTypeAndVariation incomingType,
	uint16_t* tags,
	int tagCount,
	SPVec3 pointNormal,
	SPVec3 noiseLoc,
	double altitude,
	float steepness,
	float riverDistance,
	int vegetationState,
	int seasonIndex)
{
	SurfaceTypeInfo surfaceTypeInfo;
	SPSurfaceTypeAndVariation result = {0,0};
	memset(&surfaceTypeInfo, 0, sizeof(surfaceTypeInfo));
	getSurfaceTypeInfo(tags, tagCount, seasonIndex, &surfaceTypeInfo);


	if(altitude < -0.00000001)
	{
		result.surfaceType = (surfaceTypeInfo.river ? terrainType_gravel : terrainType_beachSand);
		return result;
	}

	bool isBeach = (altitude < 0.0000001);

	if(vegetationState == 1)
	{
		result.surfaceType = terrainType_dirt;
		return result;
	}


	SPVec3 scaledNoiseLoc = spVec3Mul(noiseLoc, 599999.0);
	double noiseValue = spNoiseGet(threadState->spNoise1, scaledNoiseLoc, 4);

	bool isRock = (steepness > rockSteepness + noiseValue * 0.2);
	bool isDirt = (steepness > noiseValue + 0.5);
	bool isSecondary = (noiseValue > 0.0);

	bool isDefault = (!isRock && !isDirt && !isBeach);

	//defaults

	result.surfaceType = terrainType_dirt;
	if(isRock)
	{
		result.surfaceType = terrainType_rock;
	}
	if(isBeach)
	{
		result.surfaceType = (surfaceTypeInfo.river ? terrainType_gravel : terrainType_beachSand);
	}

	//check for primary designations
	for(int i = 0; i < tagCount; i++)
	{
		if(tags[i] == biomeTag_desert)
		{
			if(isRock)
			{
				result.surfaceType = terrainType_redRock;
			}
			else
			{
				if(surfaceTypeInfo.hot)
				{
					result.surfaceType =  terrainType_desertRedSand;
				}
				else
				{
					result.surfaceType = terrainType_desertSand;
				}
			}
		}
		if(tags[i] == biomeTag_steppe)
		{
			if(surfaceTypeInfo.hot)
			{
				if(isRock)
				{
					result.surfaceType = terrainType_redRock;
				}
				else if(isDefault)
				{
					result.surfaceType = terrainType_steppeMostlyDirt;
				}
			}
			else
			{
				if(isDefault)
				{
					result.surfaceType = terrainType_steppeMostlyGrass;
				}
			}
		}
		if(tags[i] == biomeTag_rainforest)
		{
			if(isDefault)
			{
				result.surfaceType = terrainType_tropicalRainforestGrass;
			}
		}
		if(tags[i] == biomeTag_monsoon)
		{
			if(isDefault)
			{
				result.surfaceType = terrainType_monsoonGrass;
			}
		}
		if(tags[i] == biomeTag_savanna)
		{
			if(isDefault)
			{
				result.surfaceType = terrainType_savannaGrass;
			}
		}
		if(tags[i] == biomeTag_icecap)
		{
			if(!isRock && !isDirt)
			{
				result.surfaceType = terrainType_iceCap;
			}
		}
		if(tags[i] == biomeTag_tundra)
		{
			if(isDefault)
			{
				result.surfaceType = terrainType_tundraGrass;
			}
		}
		if(tags[i] == biomeTag_temperate)
		{

			if(isDefault)
			{
				if(seasonIndex == 0 || seasonIndex == 1)
				{
					result.surfaceType = terrainType_temperateGrass;
				}
				else if(seasonIndex == 2)
				{
					result.surfaceType = terrainType_mediterraneanGrass;
				}
				else
				{
					result.surfaceType = terrainType_tundraGrass;
				}
			}
		}
	}

	//add snow
	if(surfaceTypeInfo.snowDepth > 0)
	{
		result.variation = terrainVariation_snow;

		if(surfaceTypeInfo.snowDepth == 2 || (surfaceTypeInfo.snowDepth == 1 && isSecondary))
		{
			result.surfaceType = terrainType_iceCap;
		}
	}

	return result;
}

bool getHasSingleTag(uint16_t* biomeTags, int tagCount, uint16_t tag)
{
	for(int i = 0; i < tagCount; i++)
	{
		if(biomeTags[i] == tag)
		{
			return true;
		}
	}
	return false;
}

typedef struct ForestInfo {
	int forestDensity;
	bool coniferous;
	bool birch;
	bool cold;
	bool river;

} ForestInfo;


void getForestInfo(uint16_t* biomeTags, int tagCount, ForestInfo* forestInfo)
{
	for(int i = 0; i < tagCount; i++)
	{
		if(biomeTags[i] == biomeTag_cliff)
		{
			forestInfo->forestDensity = 0;
			forestInfo->coniferous = false;
			forestInfo->birch = false;
			return;
		}
		else if(biomeTags[i] == biomeTag_river)
		{
			forestInfo->river = true;
		}
		else if(biomeTags[i] == biomeTag_denseForest)
		{
			forestInfo->forestDensity = 4;
		}
		else if(biomeTags[i] == biomeTag_mediumForest)
		{
			forestInfo->forestDensity = 3;
		}
		else if(biomeTags[i] == biomeTag_sparseForest)
		{
			forestInfo->forestDensity = 2;
		}
		else if(biomeTags[i] == biomeTag_verySparseForest)
		{
			forestInfo->forestDensity = 1;
		}
		else if(biomeTags[i] == biomeTag_coniferous)
		{
			forestInfo->coniferous = true;
		}
		else if(biomeTags[i] == biomeTag_birch)
		{
			forestInfo->birch = true;
		}
		else if(biomeTags[i] == biomeTag_polar ||
			biomeTags[i] == biomeTag_veryColdWinter)
		{
			forestInfo->cold = true;
		}
	}
}

#define ADD_OBJECT(__addType__)\
types[addedCount++] = __addType__;\
if(addedCount >= BIOME_MAX_GAME_OBJECT_COUNT_PER_SUBDIVISION)\
{\
	return addedCount;\
}

uint16_t getPineType(uint64_t faceUniqueID, int i)
{
	if(spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 22245 + i, 12) == 1)
	{
		return gameObjectType_tallPine;
	}
	return gameObjectType_medPineTypes[spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 3434 + i, MED_PINE_TYPE_COUNT)];
}

uint16_t getBirchType(uint64_t faceUniqueID, int i)
{
	return gameObjectType_birchTypes[spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 3434 + i, BIRCH_TYPE_COUNT)];
}

uint16_t getWillowType(uint64_t faceUniqueID, int i)
{
	return gameObjectType_willowTypes[spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 3434 + i, WILLOW_TYPE_COUNT)];
}

uint16_t getTreeType(uint64_t faceUniqueID, int i, ForestInfo* forestInfo)
{
	if(forestInfo->river)
	{
		if(spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 342573 + i, 2) == 1)
		{
			return getWillowType(faceUniqueID, i);
		}
	}

	if(forestInfo->birch && forestInfo->coniferous)
	{
		if(spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 54634 + i, 2) == 1)
		{
			return getPineType(faceUniqueID, i);
		}
		return getBirchType(faceUniqueID, i);
	}

	if(forestInfo->birch)
	{
		return getBirchType(faceUniqueID, i);
	}

	return getPineType(faceUniqueID, i);
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
		if(altitude > -0.0000001)
		{
			if(level >= SP_SUBDIVISIONS - 5)
			{
				SPVec3 noiseLookup = spVec3Mul(noiseLoc, 999.0);

				if(level == SP_SUBDIVISIONS - 5)
				{
					ForestInfo forestInfo;
					memset(&forestInfo, 0, sizeof(forestInfo));
					getForestInfo(biomeTags,
						tagCount,
						&forestInfo);


					int treeCount = 0;
					if(forestInfo.coniferous || forestInfo.birch)
					{
						switch(forestInfo.forestDensity)
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
							treeCount = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 3254, 8) + 16;
							break;

						}

						if(treeCount > 0)
						{
							if(forestInfo.birch)
							{
								if(spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 3254, 10 + 1000 / treeCount) == 1)
								{
									ADD_OBJECT(gameObjectType_aspen3);
								}
							}

							for(int i = 0; i < treeCount; i++)
							{
								ADD_OBJECT(getTreeType(faceUniqueID, i, &forestInfo));
							}
						}
					}
				}
				else if(level == SP_SUBDIVISIONS - 4)
				{
					ForestInfo forestInfo;
					memset(&forestInfo, 0, sizeof(forestInfo));
					getForestInfo(biomeTags,
						tagCount,
						&forestInfo);


					if(forestInfo.forestDensity > 0)
					{
						SPVec3 scaledNoiseLoc = spVec3Mul(noiseLookup, 310.0);
						double noiseValue = spNoiseGet(threadState->spNoise1, scaledNoiseLoc, 3);

						if(noiseValue > 0.3)
						{
							int objectCount = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 9235, 16) - 12;
							for(int i = 0; i < objectCount; i++)
							{
								ADD_OBJECT(gameObjectType_appleTree);
							}
						}
						else if(noiseValue < -0.3)
						{
							if(!forestInfo.cold)
							{
								int objectCount = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 9235, 16) - 12;
								for(int i = 0; i < objectCount; i++)
								{
									ADD_OBJECT(gameObjectType_orangeTree);
								}
							}
							else
							{
								int objectCount = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 9235, 16) - 12;
								for(int i = 0; i < objectCount; i++)
								{
									ADD_OBJECT(gameObjectType_peachTree);
								}
							}
						}
					}

					int treeCount = 0;
					if(forestInfo.coniferous)
					{
						switch(forestInfo.forestDensity)
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
							treeCount = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 3254, 8) + 16;
							break;

						}

						treeCount /= 4;

						if(forestInfo.coniferous)
						{
							for(int i = 0; i < treeCount; i++)
							{
								ADD_OBJECT(gameObjectType_smallPine);
							}
						}
					}
				}
				else if(level == SP_SUBDIVISIONS - 3)
				{
					bool temperate = false;
					bool steppe = false;

					for(int i = 0; i < tagCount; i++)
					{
						if(biomeTags[i] == biomeTag_temperate)
						{
							temperate = true;
						}
						else if(biomeTags[i] == biomeTag_steppe)
						{
							steppe = true;
						}
					}

					if(temperate || steppe)
					{
						SPVec3 scaledNoiseLoc = spVec3Mul(noiseLookup, 59.0);
						double noiseValue = spNoiseGet(threadState->spNoise1, scaledNoiseLoc, 3);

						if(noiseValue > 0.4)
						{
							if(temperate)
							{
								int objectCount = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 235432, 16) - 12;
								for(int i = 0; i < objectCount; i++)
								{
									ADD_OBJECT(gameObjectType_sunflower);
								}
							}
						}
						else if(noiseValue < -0.4)
						{
							int objectCount = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 235432, 10) - 8;
							for(int i = 0; i < objectCount; i++)
							{
								ADD_OBJECT(gameObjectType_raspberryBush);
							}
						}
						SPVec3 offset = {0.2,0.1,0.3};
						scaledNoiseLoc = spVec3Mul(spVec3Add(noiseLookup, offset), 54.2);
						noiseValue = spNoiseGet(threadState->spNoise1, scaledNoiseLoc, 3); 
						if(noiseValue > 0.4)
						{
							int objectCount = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 235432, 16) - 12;
							for(int i = 0; i < objectCount; i++)
							{
								ADD_OBJECT(gameObjectType_gooseberryBush);
							}
						}
					}
				}
				else if(level == SP_SUBDIVISIONS - 2)
				{
					ForestInfo forestInfo;
					memset(&forestInfo, 0, sizeof(forestInfo));
					getForestInfo(biomeTags,
						tagCount,
						&forestInfo);

					SPVec3 scaledNoiseLoc = spVec3Mul(noiseLookup, 200.0);
					double rawValue = spNoiseGet(threadState->spNoise1, scaledNoiseLoc, 3);
					double rangedFractionValue = rawValue * rawValue * 8.0;
					if(terrainType == terrainType_gravel)
					{
						rangedFractionValue += 1.0;
					}
					else if(forestInfo.river)
					{
						rangedFractionValue += 0.5;
					}
					int objectCount = ((int)spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 1324, 20)) - 20 + 4 * rangedFractionValue;
					for(int i = 0; i < objectCount; i++)
					{
						ADD_OBJECT(gameObjectType_rock);
					}

					if(forestInfo.forestDensity > 0)
					{
						int denominator = 100 / (forestInfo.forestDensity * forestInfo.forestDensity);
						denominator = spMax(denominator, 2);
						int roll = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 235432, denominator);
						if(forestInfo.coniferous && roll == 0)
						{
							ADD_OBJECT(gameObjectType_pineBranch);
						}
						if(forestInfo.birch && roll == 1)
						{
							ADD_OBJECT(gameObjectType_birchBranch);
						}
					}

				}
				else if(level == SP_SUBDIVISIONS - 1)
				{

					SPVec3 scaledNoiseLoc = spVec3Mul(noiseLookup, 2000.0);
					double rawValue = spNoiseGet(threadState->spNoise1, scaledNoiseLoc, 3);
					double rangedFractionValue = rawValue * rawValue * 8.0;
					if(terrainType == terrainType_gravel)
					{
						rangedFractionValue += 1.0;
					}
					else if(getHasSingleTag(biomeTags, tagCount, biomeTag_river))
					{
						rangedFractionValue += 0.5;
					}
					int objectCount = ((int)spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 5243, 40)) - 38 + 2 * rangedFractionValue;
					for(int i = 0; i < objectCount; i++)
					{
						ADD_OBJECT(gameObjectType_smallRock);
					}
				}
			}
		}
	}
	return addedCount;
}