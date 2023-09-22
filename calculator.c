/*
 * calculator.c
 *
 *  Created on: Sep 19, 2023
 *      Author: Rania Keshk
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LCD_Interface.h"
#include "calculator.h"

void drawArrow(u8 Copy_u8CurrPos,u8 Copy_u8OldPos)
{
	LCD_voidClearSymbolAtXY(Copy_u8OldPos,1); //delete old arrow
	//set cursor pos
	LCD_voidGoToXY(Copy_u8CurrPos,1);
	LCD_voidSendData(0b01011110); //print arrow
}


void cycleNumbers(u8 Copy_u8CurrPos, u8 Copy_u8NumberIndex)
{
	LCD_voidGoToXY(Copy_u8CurrPos,0);
	switch(Copy_u8NumberIndex)
	{
	case CALCULATOR_ZERO:
		LCD_voidSendData('0');
		break;
	case CALCULATOR_ONE:
			LCD_voidSendData('1');
			break;
	case CALCULATOR_TWO:
			LCD_voidSendData('2');
			break;
	case CALCULATOR_THREE:
			LCD_voidSendData('3');
			break;
	case CALCULATOR_FOUR:
			LCD_voidSendData('4');
			break;
	case CALCULATOR_FIVE:
			LCD_voidSendData('5');
			break;
	case CALCULATOR_SIX:
			LCD_voidSendData('6');
			break;
	case CALCULATOR_SEVEN:
			LCD_voidSendData('7');
			break;
	case CALCULATOR_EIGHT:
			LCD_voidSendData('8');
			break;
	case CALCULATOR_NINE:
			LCD_voidSendData('9');
			break;
	}
}


void cycleOperators(u8 Copy_u8CurrPos, u8 Copy_u8OperatorIndex)
{
	LCD_voidGoToXY(Copy_u8CurrPos,0);
	switch(Copy_u8OperatorIndex)
	{
	case CALCULATOR_ADD:
		LCD_voidSendData('+');
		break;
	case CALCULATOR_SUB:
			LCD_voidSendData('-');
			break;
	case CALCULATOR_MUL:
			LCD_voidSendData('*');
			break;
	case CALCULATOR_DIV:
			LCD_voidSendData('/');
			break;
	case CALCULATOR_REM:
			LCD_voidSendData('%');
			break;
		}
}


void calculatePrint(struct CalculatorData* pcalculatorData)
{
	s8 Local_s8Result;

	switch(pcalculatorData->operator)
	{
	case CALCULATOR_ADD:
		Local_s8Result = pcalculatorData->number1+pcalculatorData->number2;
		break;
	case CALCULATOR_SUB:
		Local_s8Result = pcalculatorData->number1-pcalculatorData->number2;
			break;
	case CALCULATOR_MUL:
		Local_s8Result = pcalculatorData->number1*pcalculatorData->number2;
			break;
	case CALCULATOR_DIV:
		Local_s8Result = pcalculatorData->number1/pcalculatorData->number2;
		break;
	case CALCULATOR_REM:
		Local_s8Result = pcalculatorData->number1%pcalculatorData->number2;
			break;
	}

	if(Local_s8Result>9)
	{
		LCD_voidSendData('0' + (Local_s8Result/10) );
		LCD_voidSendData('0' + (Local_s8Result%10) );
	}
	else
	{
		if(Local_s8Result<0)
			LCD_voidSendData('-');

		LCD_voidSendData('0'+Local_s8Result);
	}

}

void Calculator_voidCycleUpCallback(struct CalculatorData* pcalculatorData)
{
	//determine determine operation based on pos
	if(pcalculatorData->currPosX == 0)
	{
		//1st number
		pcalculatorData->number1 = (pcalculatorData->number1+1)%10; //update number
		cycleNumbers(pcalculatorData->currPosX,pcalculatorData->number1);

	}else if(pcalculatorData->currPosX == 1)
	{
		//operator
		pcalculatorData->operator = (pcalculatorData->operator+1)%5; //update operator
		cycleOperators(pcalculatorData->currPosX,pcalculatorData->operator);
	}
	else if(pcalculatorData->currPosX == 2)
	{
		//2nd number
		pcalculatorData->number2 = (pcalculatorData->number2+1)%10; //update number
		cycleNumbers(pcalculatorData->currPosX,pcalculatorData->number2);
	}
}


void Calculator_voidCycledownCallback(struct CalculatorData* pcalculatorData)
{
	//determine determine operation based on pos
	if(pcalculatorData->currPosX == 0)
	{
		//1st number
		pcalculatorData->number1 = (pcalculatorData->number1-1)%10; //update number
		cycleNumbers(pcalculatorData->currPosX,pcalculatorData->number1);

	}else if(pcalculatorData->currPosX == 1)
	{
		//operator
		pcalculatorData->operator = (pcalculatorData->operator-1)%5; //update operator
		cycleOperators(pcalculatorData->currPosX,pcalculatorData->operator);
	}
	else if(pcalculatorData->currPosX == 2)
	{
		////2nd number
		pcalculatorData->number2 = (pcalculatorData->number2-1)%10; //update number
		cycleNumbers(pcalculatorData->currPosX,pcalculatorData->number2);
	}
}


void Calculator_voidConfirmCallback(struct CalculatorData* pcalculatorData)
{
	//determine operation based on pos
	if(pcalculatorData->currPosX == 0)
	{
		//advance from 1st num to operator
		pcalculatorData->currPosX++;
		drawArrow(pcalculatorData->currPosX,pcalculatorData->currPosX-1); //advance arrow

	}else if(pcalculatorData->currPosX == 1)
	{
		//advance from operator to 2nd num
		pcalculatorData->currPosX++;
		drawArrow(pcalculatorData->currPosX,pcalculatorData->currPosX-1); //advance arrow
	}
	else if(pcalculatorData->currPosX == 2)
	{
		//advance from 2nd num to res
		pcalculatorData->currPosX++;
		drawArrow(pcalculatorData->currPosX,pcalculatorData->currPosX-1); //advance arrow
		calculatePrint(pcalculatorData);
	}
	else if(pcalculatorData->currPosX == 3)
	{
		//advance from res to a new operation (to be implemented
	}
}


void Calculator_voidConfig(struct CalculatorData* pcalculatorData)
{
	//intial config for calculator elements
	pcalculatorData->currPosX = 0;
	pcalculatorData->number1 = 0;
	pcalculatorData->number2 = 0;
	pcalculatorData->operator = 0;

	//intialize arrow
	drawArrow(pcalculatorData->currPosX,pcalculatorData->currPosX);
}
