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

u8 SEND=0,RECEVIE=0;

int main()
{
	/****slave*/

	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN7, DIO_PIN_INPUT);
	SPI_VoidInit();
	//DIO_u8SetPinValue(DIO_PORTB, DIO_PIN4,DIO_PIN_LOW);

	DIO_u8SetPinDirection(DIO_PORTC, DIO_PIN0, DIO_PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_LOW);

	while(1)
	{
		SPI_u8Tranceive(SEND, &RECEVIE);

		if(RECEVIE == 1)
		{
			DIO_u8SetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_HIGH);
		}
		else
			DIO_u8SetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_LOW);

	}


}
