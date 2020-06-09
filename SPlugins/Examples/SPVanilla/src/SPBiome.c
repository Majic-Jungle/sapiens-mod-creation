

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
static uint16_t biomeTag_medSnowWinter;
static uint16_t biomeTag_lightSnowWinter;
static uint16_t biomeTag_heavySnowSummer;
static uint16_t biomeTag_medSnowSummer;
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

static uint32_t terrainBaseType_rock;
static uint32_t terrainBaseType_beachSand;
static uint32_t terrainBaseType_gravel;
static uint32_t terrainBaseType_desertSand;
static uint32_t terrainBaseType_ice;
static uint32_t terrainBaseType_desertRedSand;
static uint32_t terrainBaseType_redRock;
static uint32_t terrainBaseType_dirt;

static uint32_t terrainVariation_snow;
static uint32_t terrainVariation_temperateGrass;
static uint32_t terrainVariation_taigaGrass;
static uint32_t terrainVariation_mediterraneanGrass;
static uint32_t terrainVariation_steppeGrass;
static uint32_t terrainVariation_tropicalRainforestGrass;
static uint32_t terrainVariation_monsoonGrass;
static uint32_t terrainVariation_savannaGrass;
static uint32_t terrainVariation_tundraGrass;

static uint32_t terrainModifcation_snowRemoved;
static uint32_t terrainModifcation_vegetationRemoved;
static uint32_t terrainModifcation_vegetationAdded;

static uint32_t gameObjectType_appleTree;
static uint32_t gameObjectType_orangeTree;
static uint32_t gameObjectType_peachTree;
static uint32_t gameObjectType_aspen3;
static uint32_t gameObjectType_sunflower;
static uint32_t gameObjectType_raspberryBush;
static uint32_t gameObjectType_gooseberryBush;
static uint32_t gameObjectType_tallPine;
static uint32_t gameObjectType_beetrootPlant;

static uint32_t gameObjectType_rock;
static uint32_t gameObjectType_smallRock;
static uint32_t gameObjectType_birchBranch;
static uint32_t gameObjectType_pineBranch;

#define BIRCH_TYPE_COUNT 6
static uint32_t gameObjectType_birchTypes[BIRCH_TYPE_COUNT];

#define MED_PINE_TYPE_COUNT 2
static uint32_t gameObjectType_medPineTypes[MED_PINE_TYPE_COUNT];

#define WILLOW_TYPE_COUNT 2
static uint32_t gameObjectType_willowTypes[WILLOW_TYPE_COUNT];

static uint32_t gameObjectType_smallPine;

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
	biomeTag_medSnowWinter = threadState->getBiomeTag(threadState, "medSnowWinter");
	biomeTag_lightSnowWinter = threadState->getBiomeTag(threadState, "lightSnowWinter");
	biomeTag_heavySnowSummer = threadState->getBiomeTag(threadState, "heavySnowSummer");
	biomeTag_medSnowSummer = threadState->getBiomeTag(threadState, "medSnowSummer");
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

	terrainBaseType_rock						= threadState->getTerrainBaseTypeIndex(threadState, "rock");
	terrainBaseType_beachSand					= threadState->getTerrainBaseTypeIndex(threadState, "beachSand");
	terrainBaseType_gravel						= threadState->getTerrainBaseTypeIndex(threadState, "gravel");
	terrainBaseType_desertSand					= threadState->getTerrainBaseTypeIndex(threadState, "desertSand");
	terrainBaseType_ice							= threadState->getTerrainBaseTypeIndex(threadState, "ice");
	terrainBaseType_desertRedSand				= threadState->getTerrainBaseTypeIndex(threadState, "desertRedSand");
	terrainBaseType_redRock						= threadState->getTerrainBaseTypeIndex(threadState, "redRock");
	terrainBaseType_dirt						= threadState->getTerrainBaseTypeIndex(threadState, "dirt");
												
	terrainVariation_snow						= threadState->getTerrainVariation(threadState, "snow");
	terrainVariation_temperateGrass				= threadState->getTerrainVariation(threadState, "temperateGrass");
	terrainVariation_taigaGrass					= threadState->getTerrainVariation(threadState, "taigaGrass");
	terrainVariation_mediterraneanGrass			= threadState->getTerrainVariation(threadState, "mediterraneanGrass");
	terrainVariation_steppeGrass				= threadState->getTerrainVariation(threadState, "steppeGrass");
	terrainVariation_tropicalRainforestGrass	= threadState->getTerrainVariation(threadState, "tropicalRainforestGrass");
	terrainVariation_monsoonGrass				= threadState->getTerrainVariation(threadState, "monsoonGrass");
	terrainVariation_savannaGrass				= threadState->getTerrainVariation(threadState, "savannaGrass");
	terrainVariation_tundraGrass				= threadState->getTerrainVariation(threadState, "tundraGrass");
												
	terrainModifcation_snowRemoved				= threadState->getTerrainModification(threadState, "snowRemoved");
	terrainModifcation_vegetationRemoved		= threadState->getTerrainModification(threadState, "vegetationRemoved");
	terrainModifcation_vegetationAdded			= threadState->getTerrainModification(threadState, "vegetationAdded");

	if(threadState->getGameObjectTypeIndex) //this function isn't set where game object types aren't required eg. in the initial world creation screen
	{
		gameObjectType_appleTree = threadState->getGameObjectTypeIndex(threadState, "appleTree");
		gameObjectType_orangeTree = threadState->getGameObjectTypeIndex(threadState, "orangeTree");
		gameObjectType_peachTree = threadState->getGameObjectTypeIndex(threadState, "peachTree");
		gameObjectType_aspen3 = threadState->getGameObjectTypeIndex(threadState, "aspen3");

		gameObjectType_sunflower = threadState->getGameObjectTypeIndex(threadState, "sunflower");
		gameObjectType_raspberryBush = threadState->getGameObjectTypeIndex(threadState, "raspberryBush");
		gameObjectType_gooseberryBush = threadState->getGameObjectTypeIndex(threadState, "gooseberryBush");
		gameObjectType_beetrootPlant = threadState->getGameObjectTypeIndex(threadState, "beetrootPlant");

		gameObjectType_rock = threadState->getGameObjectTypeIndex(threadState, "rock");
		gameObjectType_smallRock = threadState->getGameObjectTypeIndex(threadState, "smallRock");
		gameObjectType_birchBranch = threadState->getGameObjectTypeIndex(threadState, "birchBranch");
		gameObjectType_pineBranch = threadState->getGameObjectTypeIndex(threadState, "pineBranch");

		gameObjectType_birchTypes[0] = threadState->getGameObjectTypeIndex(threadState, "birch1");
		gameObjectType_birchTypes[1] = threadState->getGameObjectTypeIndex(threadState, "birch2");
		gameObjectType_birchTypes[2] = threadState->getGameObjectTypeIndex(threadState, "birch3");
		gameObjectType_birchTypes[3] = threadState->getGameObjectTypeIndex(threadState, "birch4");
		gameObjectType_birchTypes[4] = threadState->getGameObjectTypeIndex(threadState, "aspen1");
		gameObjectType_birchTypes[5] = threadState->getGameObjectTypeIndex(threadState, "aspen2");

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
				else if(annualRainfall > temperatureThreshold)
				{
					tagsOut[tagCount++] = biomeTag_medSnowSummer;
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
				else if(annualRainfall > temperatureThreshold)
				{
					tagsOut[tagCount++] = biomeTag_medSnowWinter;
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
			surfaceTypeInfo->snowDepth = 3;
		}
		else if(biomeTags[i] == biomeTag_medSnowSummer)
		{
			if(seasonIndex == 1)
			{
				surfaceTypeInfo->snowDepth = 2;
			}
			else
			{
				surfaceTypeInfo->snowDepth = 3;
			}
		}
		else if(biomeTags[i] == biomeTag_lightSnowSummer)
		{
			if(seasonIndex == 1)
			{
				surfaceTypeInfo->snowDepth = 1;
			}
			else if(seasonIndex == 0 || seasonIndex == 2)
			{
				surfaceTypeInfo->snowDepth = 2;
			}
			else
			{
				surfaceTypeInfo->snowDepth = 3;
			}
		}
		else if(biomeTags[i] == biomeTag_heavySnowWinter)
		{
			if(seasonIndex == 0 || seasonIndex == 2)
			{
				surfaceTypeInfo->snowDepth = 2;
			}
			else if(seasonIndex == 3)
			{
				surfaceTypeInfo->snowDepth = 3;
			}
		}
		else if(biomeTags[i] == biomeTag_medSnowWinter)
		{
			if(seasonIndex == 3)
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

uint32_t getBeachSurfaceType(SurfaceTypeInfo* surfaceTypeInfo, float riverDistance, float noiseValue)
{
	if(surfaceTypeInfo->river)
	{
		if(riverDistance < (noiseValue * 0.01 + 0.005))
		{
			return terrainBaseType_gravel;
		}
		else
		{
			return terrainBaseType_beachSand;
		}
	}

	return (noiseValue > 0.1 ? terrainBaseType_gravel : terrainBaseType_beachSand);
}

SPSurfaceTypeResult spBiomeGetSurfaceTypeForPoint(SPBiomeThreadState* threadState,
	SPSurfaceTypeResult incomingType,
	uint16_t* tags,
	int tagCount,
	uint32_t* modifications,
	int modificationCount,
	uint32_t fillGameObjectTypeIndex,
	int16_t digFillOffset,
	uint32_t* variations,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	double altitude,
	float steepness,
	float riverDistance,
	int seasonIndex)
{
	SurfaceTypeInfo surfaceTypeInfo;
	SPSurfaceTypeResult result = incomingType;
	memset(&surfaceTypeInfo, 0, sizeof(surfaceTypeInfo));
	getSurfaceTypeInfo(tags, tagCount, seasonIndex, &surfaceTypeInfo);

	SPVec3 scaledNoiseLoc = spVec3Mul(noiseLoc, 59999.0);
	double noiseValue = spNoiseGet(threadState->spNoise1, scaledNoiseLoc, 4);

	if(altitude < -0.00000001)
	{
		result.surfaceBaseType = getBeachSurfaceType(&surfaceTypeInfo, riverDistance, noiseValue);

		SPSurfaceTypeDefault defaults = threadState->getSurfaceDefaultsForBaseType(threadState, result.surfaceBaseType);

		result.materialIndexA = defaults.materialIndexA;
		result.materialIndexB = defaults.materialIndexB;
		result.decalTypeIndex = defaults.decalGroupIndex;

		return result;
	}

	bool isBeach = ((altitude + noiseValue * 0.00000005) < 0.0000001);
	bool snowRemoved = false;
	bool vegetationRemoved = false;

	for(int i = 0; i < modificationCount; i++)
	{
		if(modifications[i] == terrainModifcation_snowRemoved)
		{
			snowRemoved = true;
		}
		else if(modifications[i] == terrainModifcation_vegetationRemoved)
		{
			vegetationRemoved = true;
		}
	}

	bool isRock = (steepness > rockSteepness + noiseValue * 0.2);
	bool isDirt = (steepness > noiseValue + 0.5);
	bool isSecondary = (noiseValue > 0.0);

	bool isDefault = (!isRock && !isDirt && !isBeach);

	//defaults

	result.surfaceBaseType = terrainBaseType_dirt;
	if(isRock)
	{
		result.surfaceBaseType = terrainBaseType_rock;
	}
	if(isBeach)
	{
		result.surfaceBaseType = getBeachSurfaceType(&surfaceTypeInfo, riverDistance, noiseValue);
	}
	else
	{
		if(digFillOffset == 0)
		{
			result.surfaceBaseType = terrainBaseType_beachSand;
		}
		else if(digFillOffset == -1)
		{
			result.surfaceBaseType = terrainBaseType_dirt;
		}
		else if(digFillOffset == -2)
		{
			result.surfaceBaseType = terrainBaseType_gravel;
		}
		else
		{
			result.surfaceBaseType = terrainBaseType_rock;
		}
	}

	uint32_t grassVariation = 0;

	//check for primary designations
	for(int i = 0; i < tagCount; i++)
	{
		if(tags[i] == biomeTag_desert)
		{
			if(isRock)
			{
				result.surfaceBaseType = terrainBaseType_redRock;
			}
			else
			{
				if(surfaceTypeInfo.hot)
				{
					result.surfaceBaseType =  terrainBaseType_desertRedSand;
				}
				else
				{
					result.surfaceBaseType = terrainBaseType_desertSand;
				}
			}
		}
		if(tags[i] == biomeTag_steppe)
		{
			if(surfaceTypeInfo.hot)
			{
				if(isRock)
				{
					result.surfaceBaseType = terrainBaseType_redRock;
				}
			}
			else
			{
				if(isDefault)
				{
					grassVariation = terrainVariation_steppeGrass;
				}
			}
		}
		if(tags[i] == biomeTag_rainforest)
		{
			if(isDefault)
			{
				grassVariation = terrainVariation_tropicalRainforestGrass;
			}
		}
		if(tags[i] == biomeTag_monsoon)
		{
			if(isDefault)
			{
				grassVariation = terrainVariation_monsoonGrass;
			}
		}
		if(tags[i] == biomeTag_savanna)
		{
			if(isDefault)
			{
				grassVariation = terrainVariation_savannaGrass;
			}
		}
		if(tags[i] == biomeTag_icecap)
		{
			if(!isRock && !isDirt)
			{
				result.surfaceBaseType = terrainBaseType_ice;
			}
		}
		if(tags[i] == biomeTag_tundra)
		{
			if(isDefault)
			{
				grassVariation = terrainVariation_tundraGrass;
			}
		}
		if(tags[i] == biomeTag_temperate)
		{
			if(isDefault)
			{
				if(seasonIndex == 0 || seasonIndex == 1)
				{
					grassVariation = terrainVariation_temperateGrass;
				}
				else if(seasonIndex == 2)
				{
					grassVariation = terrainVariation_mediterraneanGrass;
				}
				else
				{
					grassVariation = terrainVariation_tundraGrass;
				}
			}
		}
	}

	bool hasSnow = false;

	//add snow
	if(!snowRemoved && surfaceTypeInfo.snowDepth > 0)
	{
		if(surfaceTypeInfo.snowDepth == 3)
		{
			hasSnow = true;
		}
		else if((noiseValue > -0.1))
		{
			if(surfaceTypeInfo.snowDepth == 2 || (noiseValue > 0.3))
			{
				hasSnow = true;
			}
		}
	}

	if(vegetationRemoved)
	{
		grassVariation = 0;
	}

	if(grassVariation != 0)
	{
		variations[result.variationCount++] = grassVariation;
	}
	if(hasSnow)
	{
		variations[result.variationCount++] = terrainVariation_snow;
	}

	if(result.variationCount > 0)
	{
		SPSurfaceTypeDefault variationDefaults = threadState->getSurfaceDefaultsForVariationType(threadState, variations[result.variationCount - 1]);
		result.materialIndexA = variationDefaults.materialIndexA;
		result.materialIndexB = variationDefaults.materialIndexB;
		result.decalTypeIndex = variationDefaults.decalGroupIndex;
	}
	else
	{
		SPSurfaceTypeDefault defaults = threadState->getSurfaceDefaultsForBaseType(threadState, result.surfaceBaseType);
		result.materialIndexA = defaults.materialIndexA;
		result.materialIndexB = defaults.materialIndexB;
		result.decalTypeIndex = defaults.decalGroupIndex;
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

uint32_t getPineType(uint64_t faceUniqueID, int i)
{
	if(spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 22245 + i, 12) == 1)
	{
		return gameObjectType_tallPine;
	}
	return gameObjectType_medPineTypes[spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 3434 + i, MED_PINE_TYPE_COUNT)];
}

uint32_t getBirchType(uint64_t faceUniqueID, int i)
{
	return gameObjectType_birchTypes[spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 3434 + i, BIRCH_TYPE_COUNT)];
}

uint32_t getWillowType(uint64_t faceUniqueID, int i)
{
	return gameObjectType_willowTypes[spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 3434 + i, WILLOW_TYPE_COUNT)];
}

uint32_t getTreeType(uint64_t faceUniqueID, int i, ForestInfo* forestInfo)
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
	uint32_t* types,
	uint16_t* biomeTags,
	int tagCount,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	uint64_t faceUniqueID, 
	int level, 
	double altitude, 
	float steepness,
	uint32_t terrainBaseType, 
	uint32_t* variations,
	int variationCount,
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
							int objectCount = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 235432, 16) - 12;
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
						else if(noiseValue < -0.4)
						{
							int objectCount = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 235432, 16) - 12;
							for(int i = 0; i < objectCount; i++)
							{
								ADD_OBJECT(gameObjectType_beetrootPlant);
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
					if(terrainBaseType == terrainBaseType_gravel)
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
					if(terrainBaseType == terrainBaseType_gravel)
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