/*
 * calculator.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Rania Keshk
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "STD_TYPES.h"

//Number macros
#define CALCULATOR_ZERO 0
#define CALCULATOR_ONE 1
#define CALCULATOR_TWO 2
#define CALCULATOR_THREE 3
#define CALCULATOR_FOUR 4
#define CALCULATOR_FIVE 5
#define CALCULATOR_SIX 6
#define CALCULATOR_SEVEN 7
#define CALCULATOR_EIGHT 8
#define CALCULATOR_NINE 9

//operator macros
#define CALCULATOR_ADD 0
#define CALCULATOR_SUB 1
#define CALCULATOR_MUL 2
#define CALCULATOR_DIV 3
#define CALCULATOR_REM 4

struct CalculatorData{
	u8 currPosX;
	u8 number1;
	u8 number2;
	u8 operator;
	u8 negativeFlag;
}calculatorData;

void drawArrow(u8 Copy_u8CurrPos,u8 Copy_u8OldPos);

void cycleNumbers(u8 Copy_u8CurrPos, u8 Copy_u8NumberIndex);

void cycleOperators(u8 Copy_u8CurrPos, u8 Copy_u8OperatorIndex);

void calculatePrint(struct CalculatorData* pcalculatorData);

void Calculator_voidConfig(struct CalculatorData* pcalculatorData);

//callback functions
void Calculator_voidCycleUpCallback(struct CalculatorData* pcalculatorData);
void Calculator_voidCycledownCallback(struct CalculatorData* pcalculatorData);
void Calculator_voidConfirmCallback(struct CalculatorData* pcalculatorData);

#endif /* CALCULATOR_H_ */
