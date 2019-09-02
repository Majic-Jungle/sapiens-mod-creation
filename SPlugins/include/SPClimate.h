
#ifndef SPClimate_h
#define SPClimate_h

#include "SPCommon.h"


typedef int (* SPClimateGetFunc) (float temperatureSummer, 
	float temperatureWinter, 
	float rainfallSummer, 
	float rainfallWinter);

MJ_EXPORT int spClimateGet(float temperatureSummer, 
	float temperatureWinter, 
	float rainfallSummer, 
	float rainfallWinter);

#endif