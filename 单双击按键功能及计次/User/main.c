#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.H"
#include "multi_button.h"
#include "Key.H"

int main(void)
{
	OLED_Init();
	OLED_Clear();
	OLED_ShowNum(2, 1, 1, 1);
	Button_Init();
	//µ¥»÷
	Single_Click();
	//Ë«»÷
	Double_Click();
	//³¤°´
	Long_Preass_Start();
	Button_Start();
	OLED_ShowNum(3, 1, 1, 1);
	while(1)
	{
		Delay_ms(5);
		button_ticks();
	}
}
