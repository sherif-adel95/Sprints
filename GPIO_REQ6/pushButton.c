
#include "gpio.h"
#include "pushButtonConfig.h"
#include "pushButton.h"
#include "softwareDelay.h"
uint8 get_values[4]={LOW,LOW,LOW,LOW};
//En_buttonStatus_t state=Released;
void pushButton_Init(En_buttonId btn_id)
{
	switch(btn_id)
	{
	case BTN_0:
		gpioPinDirection(BTN_0_GPIO,BTN_0_BIT,INPUT);
		break;
	case BTN_1:
		gpioPinDirection(BTN_1_GPIO,BTN_1_BIT,INPUT);
		break;
	case BTN_2:
		gpioPinDirection(BTN_2_GPIO,BTN_2_BIT,INPUT);
		break;
	case BTN_3:
		gpioPinDirection(BTN_3_GPIO,BTN_3_BIT,INPUT);
		break;
	}
}
void pushButton_Update(void)
{
	get_values[0]=gpioPinRead(BTN_0_GPIO,BTN_0_BIT);
	get_values[1]=gpioPinRead(BTN_1_GPIO,BTN_1_BIT);
	get_values[2]=gpioPinRead(BTN_2_GPIO,BTN_2_BIT);
	get_values[3]=gpioPinRead(BTN_3_GPIO,BTN_3_BIT);
}

En_buttonStatus_t pushButton_GetStatus(En_buttonId btn_id)
{
	static En_buttonStatus_t state=Released;

	switch (state)
	{
	case Released:
		if(get_values[btn_id]==HIGH)
			state=Prepressed;
		else
			state=Released;
		break;
	case Prepressed:
		SwDelay_ms(100);
		if(get_values[btn_id]==HIGH)
			state=Pressed;
		else
			state=Prereleased;
		break;
	case Pressed:
		if(get_values[btn_id]==LOW)
			state=Prereleased;
		else
			state=Pressed;
		break;
	case Prereleased:
		SwDelay_ms(100);
		if(get_values[btn_id]==LOW)
			state=Released;
		else
			state=Prepressed;
		break;
	}
	return 	state;
}
