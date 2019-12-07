#include "std_types.h"
#include "registers.h"
#include "gpio.h"
#include "softwareDelay.h"
#include "led.h"
#include "pushButtonConfig.h"
#include "pushButton.h"
void main(void)
{
	enum states_t
	{
		GO,
		Stop,
		Get_Ready
	}state;

	Led_Init(LED_1);
	Led_Init(LED_2);
	Led_Init(LED_3);

	state=GO;

	while(1)
	{
		switch(state)
		{
		case GO:
			Led_On(LED_1);
			SwDelay_ms(1000);
			Led_Off(LED_1);
			state=Stop;
			break;
		case Get_Ready:
			Led_On(LED_2);
			SwDelay_ms(1000);
			Led_Off(LED_2);
			state=GO;
			break;
		case Stop:
			Led_On(LED_3);
			SwDelay_ms(1000);
			Led_Off(LED_3);
			state=Get_Ready;
			break;
		}
	}

}

