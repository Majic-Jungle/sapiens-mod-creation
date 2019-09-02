

#include "SPClimate.h"
#include "SPCommon.h"

enum {
	spc_tropicalRainforest = 1,
	spc_tropicalMonsoon,
	spc_tropicalSavanna,
	spc_aridDesertHot,
	spc_aridDesertCold,
	spc_aridSteppeHot,
	spc_aridSteppeCold,
	spc_temperateDrySummer,
	spc_temperateDryWinter,
	spc_temperateWetHotSummer,
	spc_temperateWetWarmSummer,
	spc_temperateWetColdSummer,
	spc_coldDrySummer,
	spc_coldDryWinter,
	spc_coldWetHotSummer,
	spc_coldWetWarmSummer,
	spc_coldWetVeryColdWinter,
	spc_polarTundra,
	spc_polarIceCap,
};


int spClimateGet(float temperatureSummer, 
	float temperatureWinter, 
	float rainfallSummer, 
	float rainfallWinter)
{
	float annualRainfall = rainfallSummer + rainfallWinter;
	float averageTemp = (temperatureSummer + temperatureWinter) * 0.5f;
	float temperatureThreshold = averageTemp * 20.0f;

	if(rainfallSummer > rainfallWinter * 2.3f)
	{
		temperatureThreshold = temperatureThreshold + 280.0f;
	}
	else if(rainfallWinter < rainfallSummer * 2.3f)
	{
		temperatureThreshold = temperatureThreshold + 140.0f;
	}

	if(annualRainfall < temperatureThreshold) // B
	{
		if(annualRainfall < temperatureThreshold * 0.5)
		{
			if(averageTemp >= 18.0f)
			{
				return spc_aridDesertHot;
			}
			else
			{
				return spc_aridDesertCold;
			}
		}
		else
		{
			if(averageTemp >= 18.0f)
			{
				return spc_aridSteppeHot;
			}
			else
			{
				return spc_aridSteppeCold;
			}
		}
	}
	else
	{
		if(temperatureWinter > 18.0f) // A
		{
			float driestMonth = (float)spMin(rainfallSummer, rainfallWinter);
			if(driestMonth > 60.0f)
			{
				return  spc_tropicalRainforest;
			}
			else if(driestMonth > (100.0f - (annualRainfall / 25.0f)) )
			{
				return  spc_tropicalMonsoon;
			}
			else
			{
				return  spc_tropicalSavanna;
			}
		}
		else
		{
			if(temperatureSummer < -2.0f)// EF
			{
				return  spc_polarIceCap;
			}
			else if(temperatureSummer < 8.0f)// ET
			{
				return  spc_polarTundra;
			}
			else // C or D
			{
				if(rainfallSummer < 30.0f && rainfallSummer < rainfallWinter / 3.0f)
				{
					if(temperatureWinter < -5.0f)
					{
						return spc_coldDrySummer;
					}
					else
					{
						return spc_temperateDrySummer;
					}
				}
				else if(rainfallWinter < rainfallSummer / 10.0f)
				{
					if(temperatureWinter < -5.0f)
					{
						return spc_coldDryWinter;
					}
					else
					{
						return spc_temperateDryWinter;
					}
				}
				else
				{
					if(temperatureWinter < -5.0f)
					{
						return spc_coldWetHotSummer;
					}
					else
					{
						return spc_temperateWetHotSummer;
					}
				}
			}
		}
	}
	
}