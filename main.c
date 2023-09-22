/*
 * main.c
 *
 *  Created on: Sep 15, 2023
 *      Author: Rania Keshk
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LCD_Interface.h"
#include "BUTTON.h"
#include "calculator.h"


void main(void)
{
	LCD_voidConfiguration();
	LCD_voidLCDInit();

	//u8 Pattern0[8] = {0,0,0,0b00000011,0b00000010,0b00011111,0,0};
	//u8 Pattern1[8] = {0,0,0,0,0b00000001,0b00011111,0b00000100,0};
	//u8 Pattern2[8] = {0,0,0,0b00000001,0b00000001,0b00011111,0b00000000,0};
	//u8 Pattern3[8] = {0,0,0,0b00000111,0b00000101,0b00000111,0b00000001,0b00001111};
	//LCD_voidSendSpecialCharacter(Pattern0,0,15,0);
	//LCD_voidSendSpecialCharacter(Pattern1,1,14,0);
	//LCD_voidSendSpecialCharacter(Pattern2,2,13,0);
	//LCD_voidSendSpecialCharacter(Pattern3,3,12,0);


	struct BUTTON_OBJ BUTTON_structButtons[3] = {};
	BUTTON_voidButtonConfig(BUTTON_structButtons);
	Calculator_voidConfig(&calculatorData);

	while(1)
	{

		BUTTON_voidPolling(BUTTON_structButtons);

		/*u8 temp = DIO_u8GetPinValue(DIO_PORTD,DIO_PIN5) ^1;
		LCD_voidGoToXY(0,0);
		LCD_voidSendData('0'+temp);
		*/
	}
/*assignment:
 * 1. first number then operator + - * divide
 *  with arrow pointing to the block above then 2nd num
 *  and make sure you can't do divide by 0
 *  then = and the result
 *  and handle negative nums
 *  all num handling with 3 switch one up one down one enter
 *
 *  2.draw stickman on lcd
 *  hello hamoksha and then he runs (with legs alternating)
 *  I can play football
 *  I can dance
 *  Don't kill me gun with the bullet moving then this guy dying (falls on ground)
 *
 *
 */

}
