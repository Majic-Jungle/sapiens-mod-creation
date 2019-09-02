

#include "SPParticles.h"

enum {
	sp_emitterTypeCampfire = 1,
	sp_emitterTypeWoodChop,
	sp_emitterTypeFeathers
};

enum {
	sp_particleRenderTypeSmoke = 1,
	sp_particleRenderTypeFire,
	sp_particleRenderTypeStandard,
	sp_particleRenderTypeSpark,
};

static const SPVec2 texCoords[4] = {
	{0.0,0.0},
	{0.0,1.0},
	{1.0,1.0},
	{1.0,0.0},
};


bool spUpdateParticle(SPParticleThreadState* threadState, 
	SPParticleState* particleState, 
	uint32_t renderGroup,
	double dt, 
	SPVec3 origin, 
	float* renderBuffer)
{
	double lifeLeftMultiplier = 1.0;

	if(renderGroup == sp_particleRenderTypeSmoke)
	{
		lifeLeftMultiplier = 0.01; //this is all that this mod does right now, sets this value to 0.01 instead of 0.05 as a simple test.
	}
	else if(renderGroup == sp_particleRenderTypeFire)
	{
		lifeLeftMultiplier = (1.5 - particleState->randomValueB * 0.5);
	}
	else if(renderGroup == sp_particleRenderTypeSpark)
	{
		lifeLeftMultiplier = (1.5 - particleState->randomValueB * 1.0);
	}

	double lifeLeft = particleState->lifeLeft - dt * lifeLeftMultiplier;


	particleState->lifeLeft = lifeLeft;
	if(lifeLeft < 0.0)
	{
		return false;
	}

	if(renderGroup == sp_particleRenderTypeFire)
	{

		particleState->p = spVec3Add(particleState->p, spVec3Mul(particleState->v, (2.0 - lifeLeft) * dt));
	}
	else if(renderGroup == sp_particleRenderTypeSmoke)
	{
		particleState->v = spVec3Mul(particleState->v, 1.0 - dt * 0.05);

		SPVec3 vel = spVec3Add(particleState->v, particleState->gravity); //gravity is wind

		particleState->p = spVec3Add(particleState->p, spVec3Mul(vel, dt));

		particleState->scale = particleState->scale + dt * particleState->lifeLeft * (1.0 + particleState->randomValueA) * 0.15;
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