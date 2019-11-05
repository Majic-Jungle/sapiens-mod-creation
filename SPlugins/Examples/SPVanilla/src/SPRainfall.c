

#include "SPRainfall.h"
#include <math.h>


void spRainfallGet(SPNoise* noise, 
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	SPWorldGenOptions worldGenOptions, 
	double riverDistance, 
	double pregenRainfall0, 
	double pregenRainfall1,
	double* outRainfall0,
	double* outRainfall1)
{
	SPVec3 scaledNoiseLoc = spVec3Mul(noiseLoc, 6.456);
	double noiseValue = spNoiseGet(noise, scaledNoiseLoc, 7);

	SPVec3 scaledNoiseLocB = spVec3Mul(noiseLoc, 72.0);
	double noiseValueB = spNoiseGet(noise, scaledNoiseLocB, 2);

	double noiseValueS = (noiseValue + noiseValueB) * 1.0;
	double noiseValueW = (noiseValue - noiseValueB) * 1.0;


	*outRainfall0 = (pregenRainfall0 + noiseValueS * (10.0 + pregenRainfall0 * 1.0)) * worldGenOptions.rainfallMultiplier;// + riverAddition * (4.0 + noiseValueS);
	*outRainfall1 = (pregenRainfall1 + noiseValueW * (10.0 + pregenRainfall1 * 1.0)) * worldGenOptions.rainfallMultiplier;// + riverAddition * (4.0 + noiseValueW);
	
}