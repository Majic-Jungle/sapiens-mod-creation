

#include "SPHeight.h"

#define TERRAIN_HEIGHT_MAXISH 0.0008


bool spReplacesPreviousHeight()
{
	return true;
}

SPVec4 spHeightGet(SPVec4 previousHeight, //if spReplacesPreviousHeight returns false, then previousHeight is the output of the previous mod, otherwise it should be ignored. 
	SPNoise* noise1, 
	SPNoise* noise2,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	SPWorldGenOptions worldGenOptions, 
	double riverValue,
	double riverDistance)
{
	SPVec3 scales = worldGenOptions.scales;
	SPVec3 influences = worldGenOptions.influences;

	//double lookupOffset = fabs(spNoiseGet(noise1, spVec3Mul(noiseLoc,  0.8 * (0.5 + scales.x * 0.5)), 1)) * 0.8;

	//SPVec3 lookupOffsetVec = {lookupOffset + 1.2,lookupOffset + 1.2,lookupOffset + 1.2};
	SPVec3 offsetPoint = noiseLoc;//spVec3Add(noiseLoc, lookupOffsetVec);

	SPVec3 pz = spVec3Mul(noiseLoc, 8.0);
	SPVec3 op = spVec3Mul(offsetPoint, 8.0);

	SPVec3 offsetx = {1.4,1.8,1.3};
	SPVec3 offsety= {1.7,1.1,1.2};

	double lookupOffsetBx = spNoiseGet(noise1, spVec3Mul(spVec3Add(noiseLoc, offsetx), 125.2 * scales.y), 1) * 0.005;
	double lookupOffsetBy = spNoiseGet(noise1, spVec3Mul(spVec3Add(noiseLoc, offsety), 134.2 * scales.y), 1) * 0.005;
	double lookupOffsetBz = spNoiseGet(noise1, spVec3Mul(noiseLoc, 144.1 * scales.y), 1) * 0.005;

	SPVec3 lookupOffsetVecB = {lookupOffsetBx + 1.2,lookupOffsetBy + 1.2,lookupOffsetBz + 1.2};
	SPVec3 offsetPointB = spVec3Add(noiseLoc, lookupOffsetVecB);
	SPVec3 p = spVec3Mul(offsetPointB, 8.0);


	double continents = (riverValue - 0.5) * (2.0 + influences.x * 4.0) + spNoiseGet(noise1, spVec3Mul(op, scales.x * 0.5), 8) * influences.x * 0.3;
	//continents = fabsf(continents) * continents;

	double scaleYMultiplier = scales.y / 4.0;

	double mountainTopRoughnessLarge = spNoiseGet(noise1, spVec3Mul(p, 32.0 * scaleYMultiplier ), 6) * influences.y;
	double mountainTopRoughnessMid = spNoiseGet(noise1, spVec3Mul(pz, 1024.0 * scales.z), 6) * influences.z;
	//double mountainTopRoughnessSmall = 0.0;
	double lookupB = spNoiseGet(noise1, spVec3Mul(p, 64.0 * scaleYMultiplier), 6) * influences.y;


	double mountainSupressionBaseA = spNoiseGet(noise2, spVec3Mul(p, 9.0 * scaleYMultiplier), 6) * influences.y;
	double mountainSupressionBaseB = spNoiseGet(noise2, spVec3Mul(p, 500.0 * scaleYMultiplier), 4) * influences.y;
	double mountainSupressionBaseC = spNoiseGet(noise2, spVec3Mul(p, 120.0 * scaleYMultiplier), 4) * influences.y;
	double mountainSupressionA = spMax(mountainSupressionBaseA, 0.0);
	mountainSupressionA = mountainSupressionA + 0.05;
	double mountainSupressionB = spMax(mountainSupressionBaseB, 0.05);

	double mountainRangesBase = continents * 0.9 + lookupB * 0.1;
	double mountainRanges = 1.0 - pow(fabs(mountainRangesBase * 0.8), 1.1);
	//mountainRanges = pow(mountainRanges, 2.0);
	mountainRanges = mountainRanges + mountainTopRoughnessLarge * 0.2;

	double value = (continents) * (0.1 + mountainSupressionA) + spMax(mountainRanges * mountainSupressionA + (mountainTopRoughnessMid * 0.01 * mountainSupressionA), 0.0) - 0.05;
	double valueB = mountainSupressionB;//MAX(mountainRanges * mountainSupressionB + (mountainTopRoughnessMid * 0.01 * mountainSupressionB), 0.0);

	//SPVec4 resultDebug = {(spMax(mountainRanges * mountainSupressionA + (mountainTopRoughnessMid * 0.01 * mountainSupressionA), 0.0) - 0.05) * TERRAIN_HEIGHT_MAXISH, riverDistance, 0.0, 0.0};
	//return resultDebug;


	/*double riverPlaneLevelNoiseValue = spNoiseGet(noise1, spVec3Mul(p, 14.0), 2);
	double riverPlaneLevel = spMax(0.0001 + 0.03 * riverPlaneLevelNoiseValue, 0.000001);
	if(riverDistance > riverPlaneLevel)
	{
		riverDistance = spMax(riverDistance - 0.01, 0.0) / (1.0 - 0.01) + riverPlaneLevel;
	}*/

	double valleyShapePower = spNoiseGet(noise1, spVec3Mul(p, 8.1), 1);
	riverDistance = pow(riverDistance, 1.0 + valleyShapePower);


	value *= TERRAIN_HEIGHT_MAXISH;


	double valleyDistanceAtLowAltitudesMultiplier = spNoiseGet(noise1, spVec3Mul(p, 12.1), 2);
	valleyDistanceAtLowAltitudesMultiplier = spClamp(valleyDistanceAtLowAltitudesMultiplier * 4.0, 0.0, 1.0);

	riverDistance = riverDistance * (1.0 + spSmoothStep(0.2, 0.0, value * 4000.0) * 100.0 * valleyDistanceAtLowAltitudesMultiplier);
	riverDistance = spMin(riverDistance, 1.0);

	value += (valueB * 0.02 - fabs(mountainSupressionBaseC) * 0.1 * (1.0 + spNoiseGet(noise1, spVec3Mul(pz, 12000.0 * scales.z), 2) * 0.1 * influences.z)) * TERRAIN_HEIGHT_MAXISH;

	value += mountainRanges * (mountainTopRoughnessMid * 0.02) * TERRAIN_HEIGHT_MAXISH * mountainSupressionA;
	value += spNoiseGet(noise1, spVec3Mul(pz, 50000.0 * scales.z), 4) * 0.0001 * influences.z * TERRAIN_HEIGHT_MAXISH;

	value = (value + worldGenOptions.heightOffset);


	riverDistance = (riverDistance - 0.00004) / (1.0 - 0.00004);


	double riverDepth = spSmoothStep(0.999, 1.0, 1.0 - riverDistance) * 0.0000004;
	double oceanMultiplier = spSmoothStep(0.0, -0.00000001, value);
	riverDistance = spMix(riverDistance, 1.0, oceanMultiplier);




	value = spMix(value * riverDistance, value, spSmoothStep(1.0, 2.3, value * 4000.0) + 0.0001);
	value = value - riverDepth;

	if(value > 0.000001)
	{
		double noiseValue = spNoiseGet(noise2, spVec3Mul(noiseLoc, 20000.0), 2);
		double remainder = fmod(value - 0.000001, 0.000005);
		double multiplier = spSmoothStep(0.000005, 0.000003, remainder);
		value = spMix(value -  remainder * multiplier, value, spClamp((noiseValue + 0.4) * 4.0, 0.0, 1.0));
	}

/*
		if altitude > 0.0 then
			local noiseValue = heightGenerator:getNoise(noiseLoc, 15000.0, 2)
			if noiseValue > -0.4 then
				altitude = altitude + mj:mToP(1.0)
				end
				*/
	SPVec4 result = {value, riverDistance, 0.0, 0.0};

	return result;
}