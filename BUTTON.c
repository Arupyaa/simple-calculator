/*
 * BUTTON.c
 *
 *  Created on: Sep 19, 2023
 *      Author: Rania Keshk
 */

#include "BUTTON.h"


//struct BUTTON_OBJ BUTTON_structButtons[3] = {};

void (*BUTTON_FuncList[3])(struct CalculatorData*) = {Calculator_voidCycleUpCallback,Calculator_voidCycledownCallback,Calculator_voidConfirmCallback};


void BUTTON_voidButtonConfig(struct BUTTON_OBJ* pButtons)
{
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN6,DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN7,DIO_PIN_INPUT);

	DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,DIO_HIGH);
	DIO_voidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_HIGH);
	DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,DIO_HIGH);

	for(u8 Local_u8ButtonItterator = 0;Local_u8ButtonItterator<3;Local_u8ButtonItterator++)
	{
		pButtons[Local_u8ButtonItterator].val = 0;
		pButtons[Local_u8ButtonItterator].oldVal = 0;
	}

}

void BUTTON_voidPolling(struct BUTTON_OBJ* pButtons)
{
	while(1)
	{
		//scan over all buttons
		BUTTON_voidButtonSampler(pButtons);

		//see if any changes happened and take action for them
		for(u8 Local_u8ButtonItterator;Local_u8ButtonItterator <3;Local_u8ButtonItterator++)
		{
			if(pButtons[Local_u8ButtonItterator].val != pButtons[Local_u8ButtonItterator].oldVal)
			{
				//change took place
				if( pButtons[Local_u8ButtonItterator].val > pButtons[Local_u8ButtonItterator].oldVal)
				{
					//only take action on low to high change

					//debug
					//LCD_voidSendData('A');
					//OG code
					BUTTON_FuncList[Local_u8ButtonItterator](&calculatorData);
				}
			}
		}
	}
}



void BUTTON_voidButtonSampler(struct BUTTON_OBJ* pButtons)
{
	//buttons are from PORTD pins 5,6,7

	//temp button array to save button vals
	u8 Local_u8arrTempBtns[3] = {0, 0 ,0};

//	for(u8 Local_u8ButtonItterator = 0;Local_u8ButtonItterator<3;Local_u8ButtonItterator++)
//		{
//		Local_u8arrTempBtns[Local_u8ButtonItterator] = pButtons[Local_u8ButtonItterator].val;
//		}

	//save first sample as ref
	for(u8 Local_u8ButtonItterator = 0;Local_u8ButtonItterator<3;Local_u8ButtonItterator++)
		{
			Local_u8arrTempBtns[Local_u8ButtonItterator] = DIO_u8GetPinValue(DIO_PORTD,DIO_PIN5+Local_u8ButtonItterator) ^1;
		}

	//sleep for 100micro sec
	_delay_us(100);

	//cycle rate is 10ms each cycle we get 100sample, sampling rate is 1/(1/10000) = 10kHZ
	for(u8 Local_u8SampleItterator = 0; Local_u8SampleItterator<99; Local_u8SampleItterator++)
	{
		//sample 100 times every 1/10000sec = 100micro sec
		for(u8 Local_u8ButtonItterator = 0; Local_u8ButtonItterator<3; Local_u8ButtonItterator++)
		{
			if(Local_u8arrTempBtns[Local_u8ButtonItterator] != DIO_u8GetPinValue(DIO_PORTD,DIO_PIN5+Local_u8ButtonItterator) ^1 )
			{
				Local_u8arrTempBtns[Local_u8ButtonItterator] = -1;
			}
		}

		//sleep for 100micro sec
		_delay_us(100);
	}

	for(u8 Local_u8ButtonItterator = 0;Local_u8ButtonItterator<3;Local_u8ButtonItterator++)
	{
		if(Local_u8arrTempBtns[Local_u8ButtonItterator] == -1)
			continue;
		else
			pButtons[Local_u8ButtonItterator].val = Local_u8arrTempBtns[Local_u8ButtonItterator];
	}
}
