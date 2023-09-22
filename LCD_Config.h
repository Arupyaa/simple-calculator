/*
 * LCD_Config.h
 *
 *  Created on: Sep 15, 2023
 *      Author: Rania Keshk
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include <util/delay.h>

#define LCD_DATA_PORT DIO_PORTC
#define LCD_CONTROL_PORT DIO_PORTD
#define LCD_RS_PIN DIO_PIN0
#define LCD_RW_PIN DIO_PIN1
#define LCD_E_PIN DIO_PIN2

#endif /* LCD_CONFIG_H_ */
