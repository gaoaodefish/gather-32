#include "Device/Include/stm32f10x.h"   // Device header
#include "multi_button.h"
#include "OLED.H"
#include "Key.H"

#define KEY_PORT GPIOB				//��������˿�
#define KEY_PIN1 GPIO_Pin_11		//�����˿ڣ���1λ
#define KEY_PIN2 GPIO_Pin_1			//�����˿ڣ���2λ
#define KEY_PIN3 GPIO_Pin_12		//�����˿ڣ���3λ
#define KEY_PIN4 GPIO_Pin_13		//�����˿ڣ���4λ

struct Button button1;				//Button1
struct Button button2;				//Button2
struct Button button3;				//Button3
struct Button button4;				//Button4

#define btn1_id  1                  //����id1
#define btn2_id  2                  //����id2
#define btn3_id  3                  //����id3
#define btn4_id  4                  //����id4

//��ȡ����˿ڵĵ�λ
u8 read_button_GPIO(u8 button_id)
{
  // you can share the GPIO read function with multiple Buttons
  switch(button_id)
  {
    case btn1_id:
      return GPIO_ReadInputDataBit(KEY_PORT, KEY_PIN1);
    case btn2_id:
      return GPIO_ReadInputDataBit(KEY_PORT, KEY_PIN2);
	case btn3_id:
      return GPIO_ReadInputDataBit(KEY_PORT, KEY_PIN3);
	case btn4_id:
      return GPIO_ReadInputDataBit(KEY_PORT, KEY_PIN4);
    default:
      return 0;
  }
}

#define PeriphClockCmd_Port RCC_APB2Periph_GPIOB 	//����ʱ�ӿ��ƶ˿�
#define Valid 0		//��Чλ��0�͵�ƽ��Ч��1�ߵ�ƽ��Ч

void Button_Init(void)
{
	RCC_APB2PeriphClockCmd(PeriphClockCmd_Port, ENABLE);
	
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Initstructure.GPIO_Pin = KEY_PIN1 | KEY_PIN2 | KEY_PIN3 | KEY_PIN4;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Initstructure);
	
	button_init(&button1, read_button_GPIO, Valid, btn1_id);
	button_init(&button2, read_button_GPIO, Valid, btn2_id);
	button_init(&button3, read_button_GPIO, Valid, btn3_id);
	button_init(&button4, read_button_GPIO, Valid, btn4_id);
}

//��������
void Callback_SINGLE_CLICK_Handler(void *btn)
{
   Button *temp_button = (Button *)btn;
   switch(temp_button->button_id)
   {
		  case btn1_id:
			  OLED_Clear();
				 OLED_ShowNum(1, 1, 1, 1);
				 break;
		  case btn2_id:
			  OLED_Clear();
				 OLED_ShowNum(1, 1, 2, 1);
				 break;
		  case btn3_id:
			  OLED_Clear();
				 OLED_ShowNum(1, 1, 3, 1);
				 break;
		  case btn4_id:
			  OLED_Clear();
				 OLED_ShowNum(1, 1, 4, 1);
				 break;
		  default:
				 break;
   }
}

//˫������
void Callback_DOUBLE_Click_Handler(void *btn)
{
	Button *temp_button = (Button *)btn;
   switch(temp_button->button_id)
   {
		  case btn1_id:
			  OLED_Clear();
				 OLED_ShowNum(1, 1, 11, 2);
				 break;
		  case btn2_id:
			  OLED_Clear();
				 OLED_ShowNum(1, 1, 22, 2);
				 break;
		  case btn3_id:
			  OLED_Clear();
				 OLED_ShowNum(1, 1, 33, 2);
				 break;
		  case btn4_id:
			  OLED_Clear();
				 OLED_ShowNum(1, 1, 44, 2);
				 break;
		  default:
				 break;
   }
}

//��������
void Callback_LONG_PRESS_START_Handler(void *btn)
{
	Button *temp_button = (Button *)btn;
   switch(temp_button->button_id)
   {
		  case btn1_id:
			  OLED_Clear();
				 OLED_ShowNum(1, 1, 111, 3);
				 break;
		  case btn2_id:
			  OLED_Clear();
				 OLED_ShowNum(1, 1, 222, 3);
				 break;
		  case btn3_id:
			  OLED_Clear();
				 OLED_ShowNum(1, 1, 333, 3);
				 break;
		  case btn4_id:
			  OLED_Clear();
				 OLED_ShowNum(1, 1, 432, 3);
				 break;
		  default:
				 break;
   }
}

//��������
void Button_Start()
{
	button_start(&button1);
	button_start(&button2);
	button_start(&button3);
	button_start(&button4);
}

//����
void Single_Click()
{
	button_attach(&button1, SINGLE_CLICK, Callback_SINGLE_CLICK_Handler);
	button_attach(&button2, SINGLE_CLICK, Callback_SINGLE_CLICK_Handler);
	button_attach(&button3, SINGLE_CLICK, Callback_SINGLE_CLICK_Handler);
	button_attach(&button4, SINGLE_CLICK, Callback_SINGLE_CLICK_Handler);
}	

//˫��
void Double_Click()
{
	button_attach(&button1, DOUBLE_CLICK, Callback_DOUBLE_Click_Handler);
	button_attach(&button2, DOUBLE_CLICK, Callback_DOUBLE_Click_Handler);
	button_attach(&button3, DOUBLE_CLICK, Callback_DOUBLE_Click_Handler);
	button_attach(&button4, DOUBLE_CLICK, Callback_DOUBLE_Click_Handler);
}
	
//����
void Long_Preass_Start()
{
	button_attach(&button1, LONG_PRESS_START, Callback_LONG_PRESS_START_Handler);
	button_attach(&button2, LONG_PRESS_START, Callback_LONG_PRESS_START_Handler);
	button_attach(&button3, LONG_PRESS_START, Callback_LONG_PRESS_START_Handler);
	button_attach(&button4, LONG_PRESS_START, Callback_LONG_PRESS_START_Handler);
}	
