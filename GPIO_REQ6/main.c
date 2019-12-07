#include "std_types.h"
#include "registers.h"
#include "gpio.h"
#include "softwareDelay.h"
#include "led.h"
#include "pushButtonConfig.h"
#include "pushButton.h"
uint8 Press_flag=0;
uint8 Release_flag=0;
uint8 Delay_flag=0;
En_buttonStatus_t state=Released;
void Button_Check(void);
void main(void)
{

	uint8 i=0;

	Led_Init(LED_0);
	Led_Init(LED_1);

	pushButton_Init(BTN_1);

	while(1)
	{
		Button_Check();
	if(Press_flag==1 && Release_flag==1)
	{
		Press_flag=0;
		Release_flag=0;

		for(i=0;i<100;i++)
		{
		SwDelay_ms(10);
		Button_Check();
		if(Press_flag==1 && Release_flag==1)
		{
			Delay_flag=1;

		}
		}

		Led_Off(LED_0);
		Release_flag=0;
		Press_flag=0;
	}
	if(Delay_flag==1)
	{
		Led_On(LED_0);
		SwDelay_ms(2000);
		Led_Off(LED_0);
		Delay_flag=0;
		Release_flag=0;
		Press_flag=0;
	}
	}
}
void Button_Check(void)
{

pushButton_Update();
state=pushButton_GetStatus(BTN_1);
if(state==Pressed)
{
	Led_On(LED_0);
	Press_flag++;
}
else if(state==Prereleased)
{
	Release_flag++;
}
}



