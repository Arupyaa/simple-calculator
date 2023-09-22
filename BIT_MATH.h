/*
 * BIT_MATH.h
 *
 *  Created on: Sep 8, 2023
 *      Author: Keshk
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg, nbit) reg|= (1<<nbit)

#define CLR_BIT(reg, nbit) reg&= ~(1<<nbit)

#define TOG_BIT(reg, nbit) reg^= (1<<nbit)

#define GET_BIT(reg, nbit) 1&(reg>>nbit)

#endif /* BIT_MATH_H_ */
