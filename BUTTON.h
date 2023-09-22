/*
 * BUTTON.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Rania Keshk
 */

#ifndef BUTTON_H_
#define BUTTON_H_
#include "calculator.h"
#include "DIO_Interface.h"
#include <util/delay.h>





struct BUTTON_OBJ{
	u8 val;
	u8 oldVal;
};


void BUTTON_voidButtonConfig(struct BUTTON_OBJ* pButtons);

//polling function frame
void BUTTON_voidPolling(struct BUTTON_OBJ* pButtons);

void BUTTON_voidButtonSampler(struct BUTTON_OBJ* pButtons);


#endif /* BUTTON_H_ */
