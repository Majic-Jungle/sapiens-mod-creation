

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
	sp_vanillaEmitterTypeClouds
};

enum {
	sp_vanillaRenderGroupSmoke = 0,
	sp_vanillaRenderGroupFire,
	sp_vanillaRenderGroupStandard,
	sp_vanillaRenderGroupSpark,
	sp_vanillaRenderGroupCloud,
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
	}
};

//define the vertex attributes that the shader will use. In the vanilla mod, all currently take the same, but this could be different for more complex shaders
#define VERTEX_ATTRIBUTE_COUNT 3
static int vertexDescriptionTypes[VERTEX_ATTRIBUTE_COUNT] = {
	SPRenderGroupVertexDescriptionType_vec3, 
	SPRenderGroupVertexDescriptionType_vec2,
	SPRenderGroupVertexDescriptionType_vec4
};

//define render groups that we wish to use, override or add. To use an existing/predefined render group, either define again or set vertexDescriptionTypeCount to 0
#define RENDER_GROUP_TYPES_COUNT 5
static SPParticleRenderGroupInfo renderGroupInfos[RENDER_GROUP_TYPES_COUNT] = {
	{
		"smokeParticle",
		sp_vanillaRenderGroupSmoke,
		VERTEX_ATTRIBUTE_COUNT,
		vertexDescriptionTypes,
		"img/particles.png",
		NULL
	},
	{
		"fireParticle",
		sp_vanillaRenderGroupFire,
		VERTEX_ATTRIBUTE_COUNT,
		vertexDescriptionTypes,
		"img/particles.png",
		NULL
	},
	{
		"particle",
		sp_vanillaRenderGroupStandard,
		VERTEX_ATTRIBUTE_COUNT,
		vertexDescriptionTypes,
		"img/particles.png",
		NULL
	},
	{ 
		"spark",
		sp_vanillaRenderGroupSpark,
		VERTEX_ATTRIBUTE_COUNT,
		vertexDescriptionTypes,
		"img/particles.png",
		NULL
	},
	{ 
		"cloud",
		sp_vanillaRenderGroupCloud,
		VERTEX_ATTRIBUTE_COUNT,
		vertexDescriptionTypes,
		"img/cloudsN.png",
		"img/cloudsP.png",
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
		SPVec3 zeroVec = {0,0,0};


		for(int i = 0; i < 128; i++)
		{
			SPParticleState state;
			SPVec3 randPosVec = spVec3Mul(spRandGetVec3(spRand), SP_METERS_TO_PRERENDER(30000.0));
			SPVec3 offsetVec = spVec3Add(normalizedPos, randPosVec);
			double offsetLength = spVec3Length(offsetVec);
			SPVec3 randPosNormal = spVec3Div(offsetVec, offsetLength);

			state.p = spVec3Mul(randPosNormal, 1.0 + SP_METERS_TO_PRERENDER(1000.0));
			state.v = zeroVec;
			state.particleTextureType = 0;
			state.lifeLeft = 1.0;
			state.randomValueA = spRandGetValue(spRand);
			state.gravity = zeroVec;

			(*threadState->addParticle)(threadState->particleManager,
				emitterState,
				sp_vanillaRenderGroupCloud,
				&state);
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
	if(localRenderGroupTypeID == sp_vanillaRenderGroupCloud)
	{

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