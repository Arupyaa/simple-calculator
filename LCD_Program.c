/*
 * LCD_Program.c
 *
 *  Created on: Sep 15, 2023
 *      Author: Rania Keshk
 */

#include "LCD_Interface.h"

void LCD_voidSendCommand(u8 Copy_u8Command)
{
	/* set RS to low
	 * set RW to low
	 * send command

	 * set enable */

	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);
	DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Command);

	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
}

void LCD_voidSendData(u8 Copy_u8Data)
{
	/*
		 * set RS to high
		 * set RW to low
		 * send data
		 * set enable */

	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);
	DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Data);

	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
}

void LCD_voidLCDInit(void)
{
	/*delay 30ms after VDD rise
	 * send function set command
	 * wait 1ms
	 * send display on command
	 * wait 1 ms
	 * send clear display command
	 * wait 1ms
	 * */

	_delay_ms(30);
	LCD_voidSendCommand(0b00111000);
	_delay_ms(1);
	LCD_voidSendCommand(0b00001100);
	_delay_ms(1);
	LCD_voidSendCommand(1);
	_delay_ms(2);
}

void LCD_voidConfiguration(void)
{
	DIO_voidSetPortDirection(LCD_DATA_PORT,DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_E_PIN,DIO_PIN_OUTPUT);
}

void LCD_voidSendString(u8* Copy_pu8String)
{
	for(u8 Local_u8Itterator = 0; Copy_pu8String[Local_u8Itterator] != '\0';++Local_u8Itterator)
	{
		LCD_voidSendData(Copy_pu8String[Local_u8Itterator]);
	}
}

void LCD_voidSendNumber(u32 Copy_u32Number)
{
	u8 Local_u8DigitOrder = 0;
	u32 Local_u32NumberCopy = Copy_u32Number;
	u32 Local_u32TenthOrder = 10;

	//test if number is less than 9;
	if(Copy_u32Number<=9)
	{
		LCD_voidSendData(Copy_u32Number+'0');
	}
	else
	{
		while(Local_u32NumberCopy !=0)
		{
			Local_u8DigitOrder++;
			Local_u32NumberCopy/=Local_u32TenthOrder;
		}

		//Digit order has number of digits in the number
		Local_u32NumberCopy = Copy_u32Number;

		/*debug
		LCD_voidSendData(Local_u8DigitOrder+'0');
		LCD_voidSendData(' ');
		*/

		while(Local_u8DigitOrder !=0)
		{
			Local_u32TenthOrder = 1;
			for(int i =0; i<Local_u8DigitOrder-1;i++)
			{
				Local_u32TenthOrder *=10;
			}
			u8 Local_u8Num = Local_u32NumberCopy/Local_u32TenthOrder;
			LCD_voidSendData(Local_u8Num+'0');
			Local_u32NumberCopy = Local_u32NumberCopy%Local_u32TenthOrder;
			Local_u8DigitOrder--;
		}
	}
}


void LCD_voidGoToXY(u8 Copy_u8X, u8 Copy_u8Y)
{
	LCD_voidSendCommand(128 + Copy_u8X+(0x40*Copy_u8Y));

}

void LCD_voidSendSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternSlot ,u8 Copy_u8X, u8 Copy_u8Y)
{
	//calculate addr of pattern in CGROM and set LCD addr counter to it
	u8 Local_u8CGRAMAddress = Copy_u8PatternSlot*8;
	LCD_voidSendCommand(64+Local_u8CGRAMAddress);

	//print byte by byte of pattern
	for(u8 Local_u8Itterator=0;Local_u8Itterator<8;Local_u8Itterator++)
	{
		LCD_voidSendData(Copy_pu8Pattern[Local_u8Itterator]);
	}

	//set DDRAM location
	LCD_voidGoToXY(Copy_u8X,Copy_u8Y);

	LCD_voidSendData(Copy_u8PatternSlot);
}

void LCD_voidClearSymbolAtXY(u8 Copy_u8X, u8 Copy_u8Y)
{
	LCD_voidGoToXY(Copy_u8X,Copy_u8Y);
	LCD_voidSendData(0b00100000); //draw nothing
}
