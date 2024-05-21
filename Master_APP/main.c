/*
 * main.c
 *
 *  Created on: Apr 2, 2024
 *      Author: User
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_Interface.h"
#include "SPI_Interface.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

u8 SEND=0,RECEVIE=0;

int main()
{

	/***master****/

	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);
	SPI_VoidInit();
	DIO_u8SetPinValue(DIO_PORTB, DIO_PIN4,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTB, DIO_PIN5,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTB, DIO_PIN7,DIO_PIN_LOW);

	DIO_u8SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_INPUT);
	while(1)
	{
		DIO_u8GetPinValue(DIO_PORTA, DIO_PIN0, &RECEVIE);
		SPI_u8Tranceive(GET_BIT(PINA,DIO_PIN0), &SEND);
	}

}
