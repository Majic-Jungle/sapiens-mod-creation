

#include "SPRainfall.h"
#include <math.h>


void spRainfallGet(SPNoise* noise, 
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	SPWorldGenOptions worldGenOptions, 
	double riverDistance, 
	double pregenRainfall0, 
	double pregenRainfall1,
	double altitude,
	double* outRainfall0,
	double* outRainfall1)
{
	SPVec3 scaledNoiseLoc = spVec3Mul(noiseLoc, 6.456);
	double noiseValue = spNoiseGet(noise, scaledNoiseLoc, 7);

	SPVec3 scaledNoiseLocB = spVec3Mul(noiseLoc, 72.0);
	double noiseValueB = spNoiseGet(noise, scaledNoiseLocB, 2);

	SPVec3 scaledNoiseLocC = spVec3Mul(noiseLoc, 79.0);
	double noiseValueC = spNoiseGet(noise, scaledNoiseLocC, 2);

	double noiseValueS = (noiseValue + noiseValueB) * 1.0;
	double noiseValueW = (noiseValue + noiseValueC) * 1.0;


	*outRainfall0 = (pregenRainfall0 + noiseValueS * (10.0 + pregenRainfall0 * 2.0) + (pregenRainfall0 * altitude * 2000.0)) * worldGenOptions.rainfallMultiplier;
	*outRainfall1 = (pregenRainfall1 + noiseValueW * (10.0 + pregenRainfall1 * 2.0) + (pregenRainfall1 * altitude * 2000.0)) * worldGenOptions.rainfallMultiplier;
	
}