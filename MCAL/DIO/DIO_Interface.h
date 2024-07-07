/*
 * DIO_Interface.h
 *
 * Created: 6/29/2024 9:30:06 PM
 *  Author: Ahmed Bahaa
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_




#define PORTA  0
#define PORTB  1
#define PORTC  2
#define PORTD  3

#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

#define OUTPUT  0
#define INPUT   1

#define LOW     0
#define HIGH    1

#define OFF     0
#define ON     1

// void DIO_voidSetPinDirection(u8 PortName,u8 PinNumber,u8 Direction);
// void DIO_voidSetPinValue(u8 PortName,u8 PinNumber,u8 Value);
// u8   DIO_u8GetPinValue(u8 PortName,u8 PinNumber);
// void DIO_voidConfigPullUpResistor(u8 PortName,u8 PinNumber,u8 status);

typedef struct pin {
	u8 PortName;
	u8 PinNumber;
	u8 Direction;
	u8 Value;
}PIN;

void DIO_voidInitPin(PIN * pin);
void DIO_voidControlPin(PIN * pin);
void DIO_GetPinValue(PIN * pin);


#endif /* DIO_INTERFACE_H_ */