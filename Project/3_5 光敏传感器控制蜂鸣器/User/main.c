#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Buzzer.H"
#include "LightSensor.H"

int main(void)
{
	Buzzer_Init();
	LightSensor_Init();
	
	while(1)
	{
		if(LightSensor_Get() == 1)
		{
			Buzzer_ON();
		}
		else 
		{
			Buzzer_OFF();
		}
	}
}
