#include "std_types.h"
#include "registers.h"
#include "gpio.h"
void gpioPortDirection(uint8 port, uint8 direction)
{
	if(port >=GPIOA && port <=GPIOD)
	{
		switch (port)
		{
		case GPIOA:
			PORTA_DIR=direction;
			break;
		case GPIOB:
			PORTB_DIR=direction;
			break;
		case GPIOC:
			PORTC_DIR=direction;
			break;
		case GPIOD:
			PORTD_DIR=direction;
			break;
		}
	}
}
void gpioPortWrite(uint8 port, uint8 value)
{
	if(port >=GPIOA && port <=GPIOD)
	{
		switch (port)
		{
		case GPIOA:
			PORTA_DATA=value;
			break;
		case GPIOB:
			PORTB_DATA=value;
			break;
		case GPIOC:
			PORTC_DATA=value;
			break;
		case GPIOD:
			PORTD_DATA=value;
			break;
		}
	}
}
void gpioPortToggle(uint8 port)
{
	if(port >=GPIOA && port <=GPIOD)
	{
		switch (port)
		{
		case GPIOA:
			PORTA_DATA^=0xFF;
			break;
		case GPIOB:
			PORTB_DATA^=0xFF;
			break;
		case GPIOC:
			PORTC_DATA^=0xFF;
			break;
		case GPIOD:
			PORTD_DATA^=0xFF;
			break;
		}
	}
}
uint8 gpioPortRead(uint8 port)
{
	if(port >=GPIOA && port <=GPIOD)
	{
		uint8 read_value;
		switch (port)
		{
		case GPIOA:
			read_value= PORTA_PIN &0xff;
			break;
		case GPIOB:
			read_value= PORTB_PIN &0xff;
			break;
		case GPIOC:
			read_value= PORTC_PIN &0xff;
			break;
		case GPIOD:
			read_value= PORTD_PIN &0xff;
			break;
		}
		return read_value;
	}
}





void gpioPinDirection(uint8 port, uint8 pins, uint8 direction)
{
	if(port >=GPIOA && port <=GPIOD)
	{
		if(direction==OUTPUT)
		{
			switch (port)
			{
			case GPIOA:
				PORTA_DIR |=pins;
				break;
			case GPIOB:
				PORTB_DIR|=pins;
				break;
			case GPIOC:
				PORTC_DIR|=pins;
				break;
			case GPIOD:
				PORTD_DIR|=pins;
				break;
			}
		}
		else if(direction==INPUT)
		{
			switch (port)
			{
			case GPIOA:
				PORTA_DIR &=~pins;
				break;
			case GPIOB:
				PORTB_DIR&=~pins;
				break;
			case GPIOC:
				PORTC_DIR&=~pins;
				break;
			case GPIOD:
				PORTD_DIR&=~pins;
				break;
			}
		}
	}
}
void gpioPinWrite(uint8 port, uint8 pins, uint8 value)
{
	if(port >=GPIOA && port <=GPIOD)
	{
		if(value==HIGH)
		{
			switch (port)
			{
			case GPIOA:
				PORTA_DATA |=pins;
				break;
			case GPIOB:
				PORTB_DATA|=pins;
				break;
			case GPIOC:
				PORTC_DATA|=pins;
				break;
			case GPIOD:
				PORTD_DATA|=pins;
				break;
			}
		}
		else if(value==LOW)
		{
			switch (port)
			{
			case GPIOA:
				PORTA_DATA &=~pins;
				break;
			case GPIOB:
				PORTB_DATA &=~pins;
				break;
			case GPIOC:
				PORTC_DATA &=~pins;
				break;
			case GPIOD:
				PORTD_DATA &=~pins;
				break;
			}
		}
	}

}
void gpioPinToggle(uint8 port, uint8 pins)
{
	if(port >=GPIOA && port <=GPIOD)
	{
		switch (port)
		{
		case GPIOA:
			PORTA_DATA ^=pins;
			break;
		case GPIOB:
			PORTB_DATA ^=pins;
			break;
		case GPIOC:
			PORTC_DATA ^=pins;
			break;
		case GPIOD:
			PORTD_DATA ^=pins;
			break;
		}
	}
}
uint8 gpioPinRead(uint8 port, uint8 pin)
{
	if(port >=GPIOA && port <=GPIOD)
	{
		uint8 read_value;
		switch (port)
		{
		case GPIOA:
			read_value= PORTA_PIN &pin;
			break;
		case GPIOB:
			read_value= PORTB_PIN &pin;
			break;
		case GPIOC:
			read_value= PORTC_PIN &pin;
			break;
		case GPIOD:
			read_value= PORTD_PIN &pin;
			break;
		}
		if(read_value==pin)
		{
			return HIGH;
		}
		else
			return LOW;
	}

}
void gpioUpperNibbleDirection(uint8 port, uint8 direction)
{
	if(port >=GPIOA && port <=GPIOD)
	{
			direction&=0xf0;
			switch (port)
			{
			case GPIOA:
				PORTA_DIR &=0x0f;
				PORTA_DIR |=direction;
				break;
			case GPIOB:
				PORTB_DIR &=0x0f;
				PORTB_DIR |=direction;
				break;
			case GPIOC:
				PORTC_DIR &=0x0f;
				PORTC_DIR |=direction;
				break;
			case GPIOD:
				PORTD_DIR &=0x0f;
				PORTD_DIR |=direction;
				break;
			}


	}
}
void gpioUpperNibbleWrite(uint8 port, uint8 value)
{
	if(port >=GPIOA && port <=GPIOD)
	{
		value&=0xf0;
		switch (port)
		{
		case GPIOA:
			PORTA_DATA &= 0x0f;
			PORTA_DATA |=value;
			break;
		case GPIOB:
			PORTB_DATA &= 0x0f;
			PORTB_DATA |=value;
			break;
		case GPIOC:
			PORTC_DATA &= 0x0f;
			PORTC_DATA |=value;
			break;
		case GPIOD:
			PORTD_DATA &= 0x0f;
			PORTD_DATA |=value;
			break;
		}
	}
}
void gpioUpperNibbleToggle(uint8 port)
{
	if(port >=GPIOA && port <=GPIOD)
	{
		switch (port)
		{
		case GPIOA:
			PORTA_DATA ^=0xf0;
			break;
		case GPIOB:
			PORTB_DATA ^=0xf0;
			break;
		case GPIOC:
			PORTC_DATA ^=0xf0;
			break;
		case GPIOD:
			PORTD_DATA ^=0xf0;
			break;
		}
	}

}
uint8 gpioUpperNibbleRead(uint8 port)
{
	if(port >=GPIOA && port <=GPIOD)
	{
		uint8 read_value;
		switch (port)
		{
		case GPIOA:
			read_value= PORTA_PIN &0xf0;
			break;
		case GPIOB:
			read_value= PORTB_PIN &0xf0;
			break;
		case GPIOC:
			read_value= PORTC_PIN &0xf0;
			break;
		case GPIOD:
			read_value= PORTD_PIN &0xf0;
			break;
		}
		return (read_value>>4);
	}
}
void gpioLowerNibbleDirection(uint8 port, uint8 direction)
{
	if(port >=GPIOA && port <=GPIOD)
	{
		direction&=0x0f;
		switch (port)
		{
		case GPIOA:
			PORTA_DIR &=0xf0;
			PORTA_DIR |=direction;
			break;
		case GPIOB:
			PORTB_DIR &=0xf0;
			PORTB_DIR |=direction;
			break;
		case GPIOC:
			PORTC_DIR &=0xf0;
			PORTC_DIR |=direction;
			break;
		case GPIOD:
			PORTD_DIR &=0xf0;
			PORTD_DIR |=direction;
			break;
		}
	}
}
void gpioLowerNibbleWrite(uint8 port, uint8 value)
{
	if(port >=GPIOA && port <=GPIOD)
	{
		value&=0x0f;
		switch (port)
		{
		case GPIOA:
			PORTA_DATA &=0xf0;
			PORTA_DATA |=value;
			break;
		case GPIOB:
			PORTB_DATA &=0xf0;
			PORTB_DATA |=value;
			break;
		case GPIOC:
			PORTC_DATA &=0xf0;
			PORTC_DATA |=value;
			break;
		case GPIOD:
			PORTD_DATA &=0xf0;
			PORTD_DATA |=value;
			break;
		}
	}
}
void gpioLowerNibbleToggle(uint8 port)
{
	if(port >=GPIOA && port <=GPIOD)
	{
		switch (port)
		{
		case GPIOA:
			PORTA_DATA ^=0x0f;
			break;
		case GPIOB:
			PORTB_DATA ^=0x0f;
			break;
		case GPIOC:
			PORTC_DATA ^=0x0f;
			break;
		case GPIOD:
			PORTD_DATA ^=0x0f;
			break;
		}
	}
}
uint8 gpioLowerNibbleRead(uint8 port)
{
	if(port >=GPIOA && port <=GPIOD)
	{
		uint8 read_value;
		switch (port)
		{
		case GPIOA:
			read_value= PORTA_PIN &0x0f;
			break;
		case GPIOB:
			read_value= PORTB_PIN &0x0f;
			break;
		case GPIOC:
			read_value= PORTC_PIN &0x0f;
			break;
		case GPIOD:
			read_value= PORTD_PIN &0x0f;
			break;
		}
		return read_value;
	}
}
