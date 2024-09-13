#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.H"

int main(void)
{
	OLED_Init();
	OLED_Clear();
	
	OLED_ShowChar(1, 1, 'A');
	OLED_ShowString(1, 3, "Hello World!");
	OLED_ShowNum(2, 1, 12345, 5);
	OLED_ShowSignedNum(2, 7, -12345, 5);
	OLED_ShowHexNum(3, 1, 0xAA55, 4);
	OLED_ShowBinNum(4, 1, 0xAA55, 16);
	while(1)
	{
		
	}
}
