/*
 * DIO_Program.c
 *
 *  Created on: Sep 9, 2023
 *      Author: Keshk
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Register.h"
#include "DIO_Interface.h"


void DIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction)
{
	if(Copy_u8Direction == DIO_PIN_INPUT)
	{
		switch(Copy_u8Port)
		{
		case DIO_PORTA:
			CLR_BIT(DDRA,Copy_u8Pin);
			break;
		case DIO_PORTB:
			CLR_BIT(DDRB,Copy_u8Pin);
			break;
		case DIO_PORTC:
			CLR_BIT(DDRC,Copy_u8Pin);
			break;
		case DIO_PORTD:
			CLR_BIT(DDRD,Copy_u8Pin);
			break;
		}
	}
	else if(Copy_u8Direction == DIO_PIN_OUTPUT)
	{
		switch(Copy_u8Port)
		{
		case DIO_PORTA:
			SET_BIT(DDRA,Copy_u8Pin);
			break;
		case DIO_PORTB:
			SET_BIT(DDRB,Copy_u8Pin);
			break;
		case DIO_PORTC:
			SET_BIT(DDRC,Copy_u8Pin);
			break;
		case DIO_PORTD:
			SET_BIT(DDRD,Copy_u8Pin);
			break;
		}
	}

}

void DIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	if(Copy_u8Value == DIO_HIGH)
	{
		switch(Copy_u8Port)
		{
		case DIO_PORTA:
			SET_BIT(PORTA,Copy_u8Pin);
			break;
		case DIO_PORTB:
			SET_BIT(PORTB,Copy_u8Pin);
			break;
		case DIO_PORTC:
			SET_BIT(PORTC,Copy_u8Pin);
			break;
		case DIO_PORTD:
			SET_BIT(PORTD,Copy_u8Pin);
			break;
		}

	}
	else if(Copy_u8Value == DIO_LOW)
	{
		switch(Copy_u8Port)
		{
		case DIO_PORTA:
			CLR_BIT(PORTA,Copy_u8Pin);
			break;
		case DIO_PORTB:
			CLR_BIT(PORTB,Copy_u8Pin);
			break;
		case DIO_PORTC:
			CLR_BIT(PORTC,Copy_u8Pin);
			break;
		case DIO_PORTD:
			CLR_BIT(PORTD,Copy_u8Pin);
			break;
		}

	}
}

void DIO_voidTogglePinValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
	case DIO_PORTA:
		TOG_BIT(PORTA,Copy_u8Pin);
		break;
	case DIO_PORTB:
		TOG_BIT(PORTB,Copy_u8Pin);
		break;
	case DIO_PORTC:
		TOG_BIT(PORTC,Copy_u8Pin);
		break;
	case DIO_PORTD:
		TOG_BIT(PORTD,Copy_u8Pin);
		break;
	}
}

void DIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction)
{
	switch(Copy_u8Port)
		{
		case DIO_PORTA:
			DDRA = Copy_u8Direction;
			break;
		case DIO_PORTB:
			DDRB = Copy_u8Direction;
			break;
		case DIO_PORTC:
			DDRC = Copy_u8Direction;
			break;
		case DIO_PORTD:
			DDRD = Copy_u8Direction;
			break;
		}
}

void DIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
	case DIO_PORTA:
		PORTA = Copy_u8Value;
		break;
	case DIO_PORTB:
		PORTB = Copy_u8Value;
		break;
	case DIO_PORTC:
		PORTC = Copy_u8Value;
		break;
	case DIO_PORTD:
		PORTD = Copy_u8Value;
		break;
	}
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8ReturnValue;
	switch(Copy_u8Port)
	{
	case DIO_PORTA:
		Local_u8ReturnValue = GET_BIT(PINA,Copy_u8Pin);
		break;
	case DIO_PORTB:
		Local_u8ReturnValue = GET_BIT(PINB,Copy_u8Pin);
		break;
	case DIO_PORTC:
		Local_u8ReturnValue = GET_BIT(PINC,Copy_u8Pin);
		break;
	case DIO_PORTD:
		Local_u8ReturnValue = GET_BIT(PIND,Copy_u8Pin);
		break;
	}
	return Local_u8ReturnValue;
}
