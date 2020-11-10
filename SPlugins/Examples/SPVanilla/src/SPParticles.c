

#include "SPParticles.h"

//define local identifiers for this mod to use, it will be given back as the localTypeID in update functions, and used by the engine to determine particle type when adding particles

enum {
	sp_vanillaEmitterTypeCampfireLarge = 0,
	sp_vanillaEmitterTypeCampfireMedium,
	sp_vanillaEmitterTypeCampfireSmall,
	sp_vanillaEmitterTypeTorchLarge,
	sp_vanillaEmitterTypeTorchSmall,
	sp_vanillaEmitterTypeWoodChop,
	sp_vanillaEmitterTypeFeathers,
	sp_vanillaEmitterTypeClouds,
};

enum {
	sp_vanillaRenderGroupSmoke = 0,
	sp_vanillaRenderGroupFire,
	sp_vanillaRenderGroupStandard,
	sp_vanillaRenderGroupSpark,
	sp_vanillaRenderGroupCloud,
	sp_vanillaRenderGroupCloudBlended,
};


//define emitter types that we wish to override or add. Vanilla functions and functions for mods with earlier order indexes than this one that override the same type, will not get called.
//Mods with later order indexes than this mod will win, so it's possible that even though you define behavior in the functions here, those functions may not actually get called..

#define EMITTER_TYPES_COUNT 8
static SPParticleEmitterTypeInfo particleEmitterTypeInfos[EMITTER_TYPES_COUNT] = {
	{
		"campfireLarge",
		sp_vanillaEmitterTypeCampfireLarge
	},
	{
		"campfireMedium",
		sp_vanillaEmitterTypeCampfireMedium
	},
	{
		"campfireSmall",
		sp_vanillaEmitterTypeCampfireSmall
	},
	{
		"torchLarge",
		sp_vanillaEmitterTypeTorchLarge
	},
	{
		"torchSmall",
		sp_vanillaEmitterTypeTorchSmall
	},
	{
		"woodChop",
		sp_vanillaEmitterTypeWoodChop
	},
	{
		"feathers",
		sp_vanillaEmitterTypeFeathers
	},
	{
		"clouds",
		sp_vanillaEmitterTypeClouds
	},
};

//define the vertex attributes that the shader will use. In the vanilla mod, all currently take the same, but this could be different for more complex shaders
#define VERTEX_ATTRIBUTE_COUNT 3
static int vertexDescriptionTypes[VERTEX_ATTRIBUTE_COUNT] = {
	SPRenderGroupVertexDescriptionType_vec3, 
	SPRenderGroupVertexDescriptionType_vec2,
	SPRenderGroupVertexDescriptionType_vec4
};

//define render groups that we wish to use, override or add. To use an existing/predefined render group, either define again or set vertexDescriptionTypeCount to 0
#define RENDER_GROUP_TYPES_COUNT 6
static SPParticleRenderGroupInfo renderGroupInfos[RENDER_GROUP_TYPES_COUNT] = {
	{ 
		"cloud",
		sp_vanillaRenderGroupCloud,
		VERTEX_ATTRIBUTE_COUNT,
		vertexDescriptionTypes,
		"img/cloudsN.png",
		"img/cloudsP.png",
		true
	},
	{ 
		"cloudBlended",
		sp_vanillaRenderGroupCloudBlended,
		VERTEX_ATTRIBUTE_COUNT,
		vertexDescriptionTypes,
		"img/cloudsN.png",
		"img/cloudsP.png",
		true
	},
	{
		"smokeParticle",
		sp_vanillaRenderGroupSmoke,
		VERTEX_ATTRIBUTE_COUNT,
		vertexDescriptionTypes,
		"img/particles.png",
		NULL,
		false
	},
	{
		"fireParticle",
		sp_vanillaRenderGroupFire,
		VERTEX_ATTRIBUTE_COUNT,
		vertexDescriptionTypes,
		"img/particles.png",
		NULL,
		false
	},
	{
		"particle",
		sp_vanillaRenderGroupStandard,
		VERTEX_ATTRIBUTE_COUNT,
		vertexDescriptionTypes,
		"img/particles.png",
		NULL,
		false
	},
	{ 
		"spark",
		sp_vanillaRenderGroupSpark,
		VERTEX_ATTRIBUTE_COUNT,
		vertexDescriptionTypes,
		"img/particles.png",
		NULL,
		false
	}
};

int spGetEmitterTypesCount()
{
	return EMITTER_TYPES_COUNT;
}

SPParticleEmitterTypeInfo* spGetEmitterTypes()
{
	return particleEmitterTypeInfos;
}


int spGetRenderGroupTypesCount()
{
	return RENDER_GROUP_TYPES_COUNT;
}

static const double cloudFieldSize = SP_METERS_TO_PRERENDER(600000.0);
static const double cloudFieldHalfSize = SP_METERS_TO_PRERENDER(300000.0);

static const int cumulusLargeGridCount = 16;
static const double cumulusLargeAltitude = SP_METERS_TO_PRERENDER(2000.0);
static const double cumulusLargeScale = 3.0;

static const int cumulusSmallGridCount = 128;
static const double cumulusSmallAltitude = SP_METERS_TO_PRERENDER(1000.0);
static const double cumulusSmallScale = 0.8;

static const int altoCloudGridCount = 45;
static const double altoCloudAltitude = SP_METERS_TO_PRERENDER(6800.0);
static const double altoCloudScale = 80.0;

static const int cirrusCloudGridCount = 6;
static const double cirrusCloudAltitude = SP_METERS_TO_PRERENDER(12000.0);
static const double cirrusCloudScale = 60.0;


SPParticleRenderGroupInfo* spGetRenderGroupTypes()
{
	return renderGroupInfos;
}

bool spEmitterWasAdded(SPParticleThreadState* threadState,
	SPParticleEmitterState* emitterState,
	uint32_t localEmitterTypeID)
{
	bool removeImmediately = false;
	SPRand* spRand = threadState->spRand;


	switch(localEmitterTypeID)
	{
	case sp_vanillaEmitterTypeCampfireLarge:
	case sp_vanillaEmitterTypeCampfireMedium:
	case sp_vanillaEmitterTypeCampfireSmall:
	case sp_vanillaEmitterTypeTorchLarge:
	case sp_vanillaEmitterTypeTorchSmall:
	{
	
	}

		break;
	case sp_vanillaEmitterTypeWoodChop:
	{
		removeImmediately = true;
		double posLength = spVec3Length(emitterState->p);
		SPVec3 normalizedPos = spVec3Div(emitterState->p, posLength);
		SPVec3 gravity = spVec3Mul(normalizedPos, SP_METERS_TO_PRERENDER(-10.0));


		for(int i = 0; i < 32; i++)
		{
			SPParticleState state;
			SPVec3 randPosVec = spVec3Mul(spRandGetVec3(spRand), SP_METERS_TO_PRERENDER(0.2));
			SPVec3 randVelVec = spRandGetVec3(spRand);
			state.p = spVec3Add(spVec3Mul(normalizedPos, posLength), randPosVec);
			state.v = spVec3Mul(spVec3Add(normalizedPos, randVelVec), SP_METERS_TO_PRERENDER(1.0));
			state.particleTextureType = 3;
			state.lifeLeft = 1.0;
			state.randomValueA = spRandGetValue(spRand);
			state.gravity = gravity;

			(*threadState->addParticle)(threadState->particleManager,
				emitterState,
				sp_vanillaRenderGroupStandard,
				&state);
		}
	}
		break;
	case sp_vanillaEmitterTypeFeathers:
	{
		removeImmediately = true;
		double posLength = spVec3Length(emitterState->p);
		SPVec3 normalizedPos = spVec3Div(emitterState->p, posLength);
		SPVec3 gravity = spVec3Mul(normalizedPos, SP_METERS_TO_PRERENDER(-2.0));

		for(int i = 0; i < 8; i++)
		{
			SPParticleState state;
			SPVec3 randPosVec = spVec3Mul(spRandGetVec3(spRand), SP_METERS_TO_PRERENDER(0.2));
			SPVec3 randVelVec = spRandGetVec3(spRand);
			state.p = spVec3Add(spVec3Mul(normalizedPos, posLength + SP_METERS_TO_PRERENDER(0.25)), randPosVec);
			state.v = spVec3Mul(spVec3Add(normalizedPos, randVelVec), SP_METERS_TO_PRERENDER(1.0));
			state.particleTextureType = 4;
			state.lifeLeft = 1.0;
			state.randomValueA = spRandGetValue(spRand);
			state.gravity = gravity;

			(*threadState->addParticle)(threadState->particleManager,
		emitterState,
				sp_vanillaRenderGroupStandard,
				&state);
		}
	}
	case sp_vanillaEmitterTypeClouds:
	{
		double posLength = spVec3Length(emitterState->p);
		SPVec3 normalizedPos = spVec3Div(emitterState->p, posLength);
		SPVec3 north = {0.0, 1.0, 0.0};
		SPVec3 right = spVec3Normalize(spVec3Cross(north, normalizedPos));
		SPVec3 negZ = spVec3Normalize(spVec3Cross(normalizedPos, right));

		SPVec3 zeroVec = {0,0,0};


		SPParticleState state;


		int counter = 0;
		for(int y = 0; y < cumulusLargeGridCount; y++)
		{
			for(int x = 0; x < cumulusLargeGridCount; x++)
			{
				//SPVec3 randPosVec = spVec3Mul(spRandGetVec3(spRand), SP_METERS_TO_PRERENDER(120000.0));
				SPVec3 randVec = spRandGetVec3(spRand);
				if(randVec.z > 0.2)
				{

					state.lifeLeft = ((((double)x) + 0.5 * randVec.x) / cumulusLargeGridCount);

					double xPos = -cloudFieldHalfSize + cloudFieldSize * state.lifeLeft;
					double zPos = -cloudFieldHalfSize + cloudFieldSize * ((((double)y) + 0.5 * randVec.y) / cumulusLargeGridCount);

					SPVec3 pos = spVec3Add(spVec3Mul(right, xPos), spVec3Mul(negZ, zPos));

					SPVec3 offsetVec = spVec3Add(normalizedPos, pos);
					SPVec3 posNormal = spVec3Normalize(offsetVec);

					SPVec3 lookup = {(posNormal.x + 1.2) * 20.9, (posNormal.y + 0.3) * 20.9, (posNormal.z + 2.4)  * 20.9};
					double noiseValue = spNoiseGet(threadState->spNoise, lookup, 2);

					if(noiseValue > 0.0)
					{
						double altitude = 1.0 + cumulusLargeAltitude + 0.0000002 * counter;
						state.p = spVec3Mul(posNormal,altitude);
						state.particleTextureType = (counter % 3);
						state.randomValueA = spRandGetValue(spRand);
						state.scale = (randVec.z + 0.5) * cumulusLargeScale * (noiseValue + 1.0);
						state.userData.x = altitude;

						state.v = spVec3Mul(right,cloudFieldSize);

						(*threadState->addParticle)(threadState->particleManager,
							emitterState,
							sp_vanillaRenderGroupCloud,
							&state);

						state.particleTextureType = (counter % 3) + 4;

						(*threadState->addParticle)(threadState->particleManager,
							emitterState,
							sp_vanillaRenderGroupCloud,
							&state);

						counter++;
					}
				}
			}
		}

		SPVec3 cumulusSmallNorth = {-0.3, 1.0, 0.0};
		cumulusSmallNorth = spVec3Normalize(cumulusSmallNorth);
		SPVec3 cumulusSmallRight = spVec3Normalize(spVec3Cross(cumulusSmallNorth, normalizedPos));
		SPVec3 cumulusSmallNegZ = spVec3Normalize(spVec3Cross(normalizedPos, cumulusSmallRight));


		//counter = 0;
		for(int y = 0; y < cumulusSmallGridCount; y++)
		{
			for(int x = 0; x < cumulusSmallGridCount; x++)
			{
				//SPVec3 randPosVec = spVec3Mul(spRandGetVec3(spRand), SP_METERS_TO_PRERENDER(120000.0));
				SPVec3 randVec = spRandGetVec3(spRand);
				//if(randVec.z > 0.2)
				{

					state.lifeLeft = ((((double)x) + 0.5 * randVec.x) / cumulusSmallGridCount);

					double xPos = -cloudFieldHalfSize + cloudFieldSize * state.lifeLeft;
					double zPos = -cloudFieldHalfSize + cloudFieldSize * ((((double)y) + 0.5 * randVec.y) / cumulusSmallGridCount);

					SPVec3 pos = spVec3Add(spVec3Mul(cumulusSmallRight, xPos), spVec3Mul(cumulusSmallNegZ, zPos));

					SPVec3 offsetVec = spVec3Add(normalizedPos, pos);
					SPVec3 posNormal = spVec3Normalize(offsetVec);

					SPVec3 lookup = {(posNormal.x + 1.2) * 20.9, (posNormal.y + 0.3) * 20.9, (posNormal.z + 2.4)  * 20.9};
					double noiseValue = spNoiseGet(threadState->spNoise, lookup, 2);

					if(noiseValue > 0.0)
					{

						double altitude = 1.0 + cumulusSmallAltitude;
						state.p = spVec3Mul(posNormal, 1.0 + cumulusSmallAltitude);
						state.particleTextureType = (counter % 16) + 12;
						state.randomValueA = spRandGetValue(spRand);
						state.scale = (randVec.z + 1.2) * cumulusSmallScale * (noiseValue + 1.0);

						state.v = spVec3Mul(cumulusSmallRight,cloudFieldSize);
						state.userData.x = altitude;

						(*threadState->addParticle)(threadState->particleManager,
							emitterState,
							sp_vanillaRenderGroupCloud,
							&state);

						counter++;
					}
				}
			}
		}

		SPVec3 cirrusNorth = {0.9, -0.5, 0.0};
		cirrusNorth = spVec3Normalize(cirrusNorth);
		SPVec3 cirrusRight = spVec3Normalize(spVec3Cross(cirrusNorth, normalizedPos));
		SPVec3 cirrusNegZ = spVec3Normalize(spVec3Cross(normalizedPos, cirrusRight));

		//cirrus
		counter = 0;
		for(int y = 0; y < cirrusCloudGridCount; y++)
		{
			for(int x = 0; x < cirrusCloudGridCount; x++)
			{

				SPVec3 randVec = spRandGetVec3(spRand);
				if(randVec.z > 0.2 && randVec.z < 0.4)
				{

					double xPosBase = ((((double)x) + 0.5 * randVec.x) / cirrusCloudGridCount);
					double zPosBase = ((((double)y) + 0.5 * randVec.y) / cirrusCloudGridCount);

					state.lifeLeft = xPosBase;

					double xPos = -cloudFieldHalfSize + cloudFieldSize * xPosBase;
					double zPos = -cloudFieldHalfSize + cloudFieldSize * zPosBase;

					SPVec3 pos = spVec3Add(spVec3Mul(cirrusRight, xPos), spVec3Mul(cirrusNegZ, zPos));

					SPVec3 offsetVec = spVec3Add(normalizedPos, pos);
					SPVec3 posNormal = spVec3Normalize(offsetVec);

					double altitude = 1.0 + cirrusCloudAltitude - 0.0000001 * ((double)counter) * 0.01;
					state.p = spVec3Mul(posNormal, altitude);
					state.randomValueA = spRandGetValue(spRand);
					state.scale = cirrusCloudScale * (1.0 + randVec.z);

					state.v = spVec3Mul(cirrusRight,cloudFieldSize);
					state.userData.x = altitude;

					state.particleTextureType = 9;

					(*threadState->addParticle)(threadState->particleManager,
						emitterState,
						sp_vanillaRenderGroupCloudBlended,
						&state);

					counter++;
				}
			}
		}

		//altocumulus

		SPVec3 altocumulusNorth = {0.5, 1.0, 0.0};
		altocumulusNorth = spVec3Normalize(altocumulusNorth);
		SPVec3 altocumulusRight = spVec3Normalize(spVec3Cross(altocumulusNorth, normalizedPos));
		SPVec3 altocumulusNegZ = spVec3Normalize(spVec3Cross(normalizedPos, altocumulusRight));

		counter = 0;
		for(int y = 0; y < altoCloudGridCount; y++)
		{
			for(int x = 0; x < altoCloudGridCount; x++)
			{

				SPVec3 randVec = spRandGetVec3(spRand);
				if(randVec.z > 0.2 && randVec.z < 0.4)
				{
					double xPosBase = ((((double)x) + 0.5 * randVec.x) / altoCloudGridCount);
					double zPosBase = ((((double)y) + 0.5 * randVec.y) / altoCloudGridCount);

					state.lifeLeft = xPosBase;

					double xPos = -cloudFieldHalfSize + cloudFieldSize * xPosBase;
					double zPos = -cloudFieldHalfSize + cloudFieldSize * zPosBase;

					SPVec3 pos = spVec3Add(spVec3Mul(altocumulusRight, xPos), spVec3Mul(altocumulusNegZ, zPos));

					SPVec3 offsetVec = spVec3Add(normalizedPos, pos);
					SPVec3 posNormal = spVec3Normalize(offsetVec);

					SPVec3 lookup = {(posNormal.x + 1.7) * 20.9, (posNormal.y + 0.6) * 20.9, (posNormal.z + 1.2)  * 20.9};
					double noiseValue = spNoiseGet(threadState->spNoise, lookup, 2);

					if(noiseValue > 0.3)
					{

						int altoType = counter % 3;

						double altitude = 1.0 + altoCloudAltitude - 0.0000001 * ((double)counter) * 0.01;
						state.p = spVec3Mul(posNormal, altitude);
						state.randomValueA = (altoType == 2 ?  2.5 : spRandGetValue(spRand));
						state.scale = (randVec.z + 0.4 - 0.3) * altoCloudScale;

						state.v = spVec3Mul(altocumulusRight,cloudFieldSize);
						state.userData.x = altitude;

						state.particleTextureType = (altoType == 0 ? 8 : (altoType == 1 ? 10 : 11));

						(*threadState->addParticle)(threadState->particleManager,
							emitterState,
							sp_vanillaRenderGroupCloudBlended,
							&state);

						counter++;
					}
				}
			}
		}
	}
	break;

		break;
	}

	if(!removeImmediately)
	{
		for(int i = 0; i < 4; i++)
		{
			emitterState->counters[i] = 0;
		}
		emitterState->timeAccumulatorA = 0.0;
		emitterState->timeAccumulatorB = 0.0;
	}

	return removeImmediately;
}

void emitFireParticle(SPParticleThreadState* threadState,
	SPParticleEmitterState* emitterState,
	double scaleAverage,
	SPVec3 randPosVec)
{
	SPRand* spRand = threadState->spRand;
	SPParticleState state;

	double posLength = spVec3Length(emitterState->p);
	SPVec3 normalizedPos = spVec3Div(emitterState->p, posLength);

	state.p = spVec3Add(spVec3Mul(normalizedPos, posLength + SP_METERS_TO_PRERENDER(0.1)), randPosVec);
	state.v = spVec3Mul(normalizedPos, SP_METERS_TO_PRERENDER(0.2 + spRandGetValue(spRand) * scaleAverage));
	state.particleTextureType = ((spRandGetValue(spRand) > 0.5) ? 1 : 4);
	state.lifeLeft = 1.0;
	state.scale = scaleAverage + spRandGetValue(spRand) * 0.2;
	state.randomValueA = spRandGetValue(spRand);
	state.randomValueB = spRandGetValue(spRand);

	(*threadState->addParticle)(threadState->particleManager,
		emitterState,
		sp_vanillaRenderGroupFire,
		&state);
}

static const double fixedTimeStep = 1.0/60.0;

void spUpdateEmitter(SPParticleThreadState* threadState,
	SPParticleEmitterState* emitterState,
	uint32_t localEmitterTypeID,
	double dt)
{
	SPRand* spRand = threadState->spRand;

	emitterState->timeAccumulatorA += dt;

	while(emitterState->timeAccumulatorA > 0.0)
	{
		emitterState->timeAccumulatorA -= fixedTimeStep;
		emitterState->timeAccumulatorB += fixedTimeStep;
		switch(localEmitterTypeID)
		{
		case sp_vanillaEmitterTypeCampfireLarge:
		case sp_vanillaEmitterTypeCampfireMedium:
		case sp_vanillaEmitterTypeCampfireSmall:
		case sp_vanillaEmitterTypeTorchLarge:
		case sp_vanillaEmitterTypeTorchSmall:
		{
			if(emitterState->counters[0] == 0) // SMOKE
			{
				double posLength = spVec3Length(emitterState->p);
				SPVec3 normalizedPos = spVec3Div(emitterState->p, posLength);
				SPParticleState state;


				SPVec3 randPosVec;
				if(localEmitterTypeID == sp_vanillaEmitterTypeTorchLarge || localEmitterTypeID == sp_vanillaEmitterTypeTorchSmall)
				{
					randPosVec = spVec3Mul(spRandGetVec3(spRand), SP_METERS_TO_PRERENDER(0.02));
					randPosVec = spVec3Add(randPosVec, spVec3Mul(normalizedPos, posLength + SP_METERS_TO_PRERENDER(0.2)));
				}
				else
				{
					randPosVec = spVec3Mul(spRandGetVec3(spRand), SP_METERS_TO_PRERENDER(0.1));
					randPosVec = spVec3Add(randPosVec, spVec3Mul(normalizedPos, posLength + SP_METERS_TO_PRERENDER(0.4)));
				}

				state.p = randPosVec;

				state.particleTextureType = ((spRandGetValue(spRand) > 0.5) ? 2 : 5);
				state.lifeLeft = 1.0;
				state.scale = 0.2 + spRandGetValue(spRand) * 0.2;
				state.randomValueA = spRandGetValue(spRand);
				state.randomValueB = spRandGetValue(spRand);
				if(localEmitterTypeID == sp_vanillaEmitterTypeTorchLarge || localEmitterTypeID == sp_vanillaEmitterTypeTorchSmall)
				{
					//state.lifeLeft = 0.2;
					state.randomValueB += 8.0;
					//state.scale = state.scale * 0.5;
				}
				SPVec3 lookup = {(normalizedPos.x + 1.2) * 99999.9, (normalizedPos.y * 4.5 + normalizedPos.z + 2.4) * 99999.9, emitterState->timeAccumulatorB * 0.1};
				SPVec3 lookupB = {(normalizedPos.x + 1.4) * 99999.9, (normalizedPos.y * 4.6 + normalizedPos.z + 2.8) * 99999.9, emitterState->timeAccumulatorB * 0.1};
				SPVec3 lookupC = {(normalizedPos.x + 1.8) * 99999.9, (normalizedPos.y * 4.8 + normalizedPos.z + 2.9) * 99999.9, emitterState->timeAccumulatorB * 0.5};
				double noiseValue = spNoiseGet(threadState->spNoise, lookup, 2);
				double noiseValueB = spNoiseGet(threadState->spNoise, lookupB, 2);
				double noiseValueC = spNoiseGet(threadState->spNoise, lookupC, 2);

				state.v = spVec3Mul(normalizedPos, SP_METERS_TO_PRERENDER(0.9 + noiseValueC) * 0.7);

				state.gravity = spVec3Mul(spMat3GetRow(emitterState->rot, 0), SP_METERS_TO_PRERENDER(noiseValue) * 0.5);
				state.gravity = spVec3Add(state.gravity, spVec3Mul(spMat3GetRow(emitterState->rot, 2), SP_METERS_TO_PRERENDER(noiseValueB) * 0.5));

				(*threadState->addParticle)(threadState->particleManager,
					emitterState,
					sp_vanillaRenderGroupSmoke,
					&state);

				emitterState->counters[0] = 1 + (uint8_t)(4 * (1.0 - noiseValueC));
			}
			else
			{
				emitterState->counters[0]--;
			}

			float quantityMultiplier = 1.0f;
			float scaleMultiplier = 1.0f;
			if(localEmitterTypeID == sp_vanillaEmitterTypeCampfireLarge)
			{
				quantityMultiplier = 3.0f;
				scaleMultiplier = 1.5f;
			}
			else if(localEmitterTypeID == sp_vanillaEmitterTypeCampfireSmall)
			{
				quantityMultiplier = 0.5f;
				scaleMultiplier = 0.5f;
			}
			else if(localEmitterTypeID == sp_vanillaEmitterTypeTorchLarge)
			{
				quantityMultiplier = 0.5f;
				scaleMultiplier = 0.3f;
			}
			else if(localEmitterTypeID == sp_vanillaEmitterTypeTorchSmall)
			{
				quantityMultiplier = 0.25f;
				scaleMultiplier = 0.2f;
			}

			if(emitterState->counters[1] == 0) //FLAME 1
			{
				SPVec3 randPosVec = spVec3Mul(spRandGetVec3(spRand), SP_METERS_TO_PRERENDER(0.04) * scaleMultiplier);
				double scaleAverage = 0.3 * scaleMultiplier;

				emitFireParticle(threadState,
					emitterState,
					scaleAverage,
					randPosVec);

				emitterState->counters[1] = 2 + (uint8_t)(10 * spRandGetValue(spRand) / quantityMultiplier);

			}
			else
			{
				emitterState->counters[1]--;
			}

			if(emitterState->counters[2] == 0) //FLAME 2
			{
				SPVec3 randPosVec = spVec3Mul(spRandGetVec3(spRand), SP_METERS_TO_PRERENDER(0.04) * scaleMultiplier);
				randPosVec = spVec3Add(randPosVec, spVec3Mul(spMat3GetRow(emitterState->rot, 0), SP_METERS_TO_PRERENDER(0.2) * scaleMultiplier));
				double scaleAverage = 0.15 * scaleMultiplier;

				emitFireParticle(threadState, 
					emitterState,
					scaleAverage,
					randPosVec);

				emitterState->counters[2] = 2 + (uint8_t)(10 * spRandGetValue(spRand) / quantityMultiplier);

			}
			else
			{
				emitterState->counters[2]--;
			}

			if(emitterState->counters[3] == 0) //FLAME 3
			{
				SPVec3 randPosVec = spVec3Mul(spRandGetVec3(spRand), SP_METERS_TO_PRERENDER(0.04) * scaleMultiplier);
				randPosVec = spVec3Add(randPosVec, spVec3Mul(spMat3GetRow(emitterState->rot, 2), SP_METERS_TO_PRERENDER(0.1) * scaleMultiplier));
				double scaleAverage = 0.1 * scaleMultiplier;

				emitFireParticle(threadState, 
					emitterState,
					scaleAverage,
					randPosVec);

				emitterState->counters[3] = 3 + (uint8_t)(10 * spRandGetValue(spRand) / quantityMultiplier);
			}
			else 
			{
				if(emitterState->counters[3] == 6 / quantityMultiplier) //spark
				{

					double posLength = spVec3Length(emitterState->p);
					SPVec3 normalizedPos = spVec3Div(emitterState->p, posLength);
					SPVec3 randVec = spRandGetVec3(spRand);
					SPVec3 randPosVec = spVec3Mul(randVec, SP_METERS_TO_PRERENDER(0.1));
					SPVec3 randVelVec = spVec3Mul(randVec, SP_METERS_TO_PRERENDER(0.4));

					SPParticleState state;

					state.p = spVec3Add(spVec3Mul(normalizedPos, posLength + SP_METERS_TO_PRERENDER(0.1)), randPosVec);
					state.v = spVec3Mul(spVec3Add(normalizedPos, randVelVec), SP_METERS_TO_PRERENDER(2.0 + spRandGetValue(spRand) * 0.5));
					state.particleTextureType = 3;
					state.lifeLeft = 1.0;
					state.scale = 0.01 + spRandGetValue(spRand) * 0.02;
					state.randomValueA = spRandGetValue(spRand);
					state.randomValueB = spRandGetValue(spRand);
					state.gravity = spVec3Mul(spRandGetVec3(spRand), SP_METERS_TO_PRERENDER(1.0));

					(*threadState->addParticle)(threadState->particleManager,
						emitterState,
						sp_vanillaRenderGroupSpark,
						&state);
				}
				emitterState->counters[3]--;
			}

		}
		break;
		}
	}
}

static const SPVec2 texCoords[4] = {
	{0.0,0.0},
	{0.0,1.0},
	{1.0,1.0},
	{1.0,0.0},
};


bool spUpdateParticle(SPParticleThreadState* threadState, 
	SPParticleState* particleState, 
	uint32_t localRenderGroupTypeID,
	double dt, 
	SPVec3 origin, 
	float* renderBuffer)
{
	if(localRenderGroupTypeID == sp_vanillaRenderGroupCloud || localRenderGroupTypeID == sp_vanillaRenderGroupCloudBlended)
	{

		particleState->lifeLeft -= dt * 0.0002;
		if(particleState->lifeLeft < 0.0)
		{
			particleState->lifeLeft += 1.0;
			particleState->p = spVec3Add(particleState->p, spVec3Mul(particleState->v,  1.0));
		}
		else
		{
			particleState->p = spVec3Add(particleState->p, spVec3Mul(particleState->v,  -dt * 0.0002));
		}

		particleState->p = spVec3Mul(spVec3Normalize(particleState->p), particleState->userData.x);

		SPVec3 posLocal = spVec3Mul(spVec3Sub(particleState->p, origin), SP_RENDER_SCALE);
		for(int v = 0; v < 4; v++)
		{
			renderBuffer[v * 9 + 0] = posLocal.x;
			renderBuffer[v * 9 + 1] = posLocal.y;
			renderBuffer[v * 9 + 2] = posLocal.z;
			renderBuffer[v * 9 + 3] = texCoords[v].x;
			renderBuffer[v * 9 + 4] = texCoords[v].y;
			renderBuffer[v * 9 + 5] = particleState->particleTextureType;
			renderBuffer[v * 9 + 6] = particleState->lifeLeft;
			renderBuffer[v * 9 + 7] = particleState->randomValueA;
			renderBuffer[v * 9 + 8] = particleState->scale;
		}

		return true;
	}

	double lifeLeftMultiplier = 1.0;

	if(localRenderGroupTypeID == sp_vanillaRenderGroupSmoke)
	{
		lifeLeftMultiplier = 0.05 + particleState->randomValueB * 0.1;
	}
	else if(localRenderGroupTypeID == sp_vanillaRenderGroupFire)
	{
		lifeLeftMultiplier = (2.0 - particleState->randomValueB * 0.5);
	}
	else if(localRenderGroupTypeID == sp_vanillaRenderGroupSpark)
	{
		lifeLeftMultiplier = (1.5 - particleState->randomValueB * 1.0);
	}

	double lifeLeft = particleState->lifeLeft - dt * lifeLeftMultiplier;


	particleState->lifeLeft = lifeLeft;
	if(lifeLeft < 0.0)
	{
		return false;
	}

	if(localRenderGroupTypeID == sp_vanillaRenderGroupFire)
	{

		particleState->p = spVec3Add(particleState->p, spVec3Mul(particleState->v, (2.0 - lifeLeft) * dt * 1.5));
	}
	else if(localRenderGroupTypeID == sp_vanillaRenderGroupSmoke)
	{
		particleState->v = spVec3Mul(particleState->v, 1.0 - dt * 0.05);

		SPVec3 vel = spVec3Add(particleState->v, particleState->gravity); //gravity is wind

		particleState->p = spVec3Add(particleState->p, spVec3Mul(vel, dt));

		particleState->scale = particleState->scale + dt * (particleState->lifeLeft * particleState->lifeLeft) * (1.0 + particleState->randomValueA) * 0.15;
	}
	else
	{
		particleState->v = spVec3Add(particleState->v, spVec3Mul(particleState->gravity, dt));
		particleState->p = spVec3Add(particleState->p, spVec3Mul(particleState->v, dt));
	}


	SPVec3 posLocal = spVec3Mul(spVec3Sub(particleState->p, origin), SP_RENDER_SCALE);
	for(int v = 0; v < 4; v++)
	{
		renderBuffer[v * 9 + 0] = posLocal.x;
		renderBuffer[v * 9 + 1] = posLocal.y;
		renderBuffer[v * 9 + 2] = posLocal.z;
		renderBuffer[v * 9 + 3] = texCoords[v].x;
		renderBuffer[v * 9 + 4] = texCoords[v].y;
		renderBuffer[v * 9 + 5] = particleState->particleTextureType;
		renderBuffer[v * 9 + 6] = particleState->lifeLeft;
		renderBuffer[v * 9 + 7] = particleState->randomValueA;
		renderBuffer[v * 9 + 8] = particleState->scale;
	}
		
	return true;
}