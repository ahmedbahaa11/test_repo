/*
 * DIO_Program.c
 *
 * Created: 6/29/2024 9:29:07 PM
 *  Author: Ahmed Bahaa
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

// void DIO_voidSetPinDirection(u8 PortName,u8 PinNumber,u8 Direction)
// {
// 	switch(Direction)
// 	{
// 		case OUTPUT:
// 					switch(PortName)
// 					{  // Register (address) write on address (Pointer -> address)
// 						case PORTA: SET_BIT(DDRA_REG,PinNumber);  break;
// 						case PORTB: SET_BIT(DDRB_REG,PinNumber);  break;
// 						case PORTC: SET_BIT(DDRC_REG,PinNumber);  break;
// 						case PORTD: SET_BIT(DDRD_REG,PinNumber);  break;
// 						default:							      break; 
// 					}
// 					break;
// 		case INPUT: 
// 					switch(PortName)
// 					{
// 						case PORTA: CLEAR_BIT(DDRA_REG,PinNumber);  break;
// 						case PORTB: CLEAR_BIT(DDRB_REG,PinNumber);  break;
// 						case PORTC: CLEAR_BIT(DDRC_REG,PinNumber);  break;
// 						case PORTD: CLEAR_BIT(DDRD_REG,PinNumber);  break;
// 						default:									break;
// 					}
// 					break;
// 		default:    break;
// 	}
// }


// void DIO_voidSetPinValue(u8 PortName,u8 PinNumber,u8 Value)
// {
// 	switch(Value)
// 	{
// 		case HIGH :
// 					switch(PortName)
// 					{ 
// 						case PORTA: SET_BIT(PORTA_REG,PinNumber);  break;
// 						case PORTB: SET_BIT(PORTB_REG,PinNumber);  break;
// 						case PORTC: SET_BIT(PORTC_REG,PinNumber);  break;
// 						case PORTD: SET_BIT(PORTD_REG,PinNumber);  break;
// 						default:							       break; 
// 					}
// 					break;
// 		case LOW :
// 					switch(PortName)
// 					{ 
// 						case PORTA: CLEAR_BIT(PORTA_REG,PinNumber);  break;
// 						case PORTB: CLEAR_BIT(PORTB_REG,PinNumber);  break;
// 						case PORTC: CLEAR_BIT(PORTC_REG,PinNumber);  break;
// 						case PORTD: CLEAR_BIT(PORTD_REG,PinNumber);  break;
// 						default:							         break; 
// 					}
// 					break;
// 					break;
		
// 	}
// }

// u8 DIO_u8GetPinValue(u8 PortName,u8 PinNumber)
// {
// 	u8 InputValue;
// 	switch(PortName)
// 	{ 
// 		case PORTA: InputValue = GET_BIT(PINA_REG,PinNumber);   break;
// 		case PORTB: InputValue = GET_BIT(PINB_REG,PinNumber);   break;
// 		case PORTC: InputValue = GET_BIT(PINC_REG,PinNumber);   break;
// 		case PORTD: InputValue = GET_BIT(PIND_REG,PinNumber);   break;
// 		default:							         			break; 
// 	}
// 	return InputValue;
// }

// void DIO_voidConfigPullUpResistor(u8 PortName,u8 PinNumber,u8 status)
// {
// 	switch(status)
// 	{
// 		case ON :
// 					switch(PortName)
// 					{ 
// 						case PORTA: SET_BIT(PORTA_REG,PinNumber);  break;
// 						case PORTB: SET_BIT(PORTB_REG,PinNumber);  break;
// 						case PORTC: SET_BIT(PORTC_REG,PinNumber);  break;
// 						case PORTD: SET_BIT(PORTD_REG,PinNumber);  break;
// 						default:							       break; 
// 					}
// 					break;
// 		case OFF :
// 					switch(PortName)
// 					{ 
// 						case PORTA: CLEAR_BIT(PORTA_REG,PinNumber);  break;
// 						case PORTB: CLEAR_BIT(PORTB_REG,PinNumber);  break;
// 						case PORTC: CLEAR_BIT(PORTC_REG,PinNumber);  break;
// 						case PORTD: CLEAR_BIT(PORTD_REG,PinNumber);  break;
// 						default:							         break; 
// 					}
// 					break;
// 					break;
		
// 	}
// }

void DIO_voidInitPin(PIN * pin)
{
	switch(pin->Direction)
	{
		case OUTPUT:
					switch(pin->PortName)
					{  // Register (address) write on address (Pointer -> address)
						case PORTA: SET_BIT(DDRA_REG,pin->PinNumber);  break;
						case PORTB: SET_BIT(DDRB_REG,pin->PinNumber);  break;
						case PORTC: SET_BIT(DDRC_REG,pin->PinNumber);  break;
						case PORTD: SET_BIT(DDRD_REG,pin->PinNumber);  break;
						default:							      	   break; 
					}
					break;
		case INPUT: 
					switch(pin->PortName)
					{
						case PORTA: CLEAR_BIT(DDRA_REG,pin->PinNumber);  break;
						case PORTB: CLEAR_BIT(DDRB_REG,pin->PinNumber);  break;
						case PORTC: CLEAR_BIT(DDRC_REG,pin->PinNumber);  break;
						case PORTD: CLEAR_BIT(DDRD_REG,pin->PinNumber);  break;
						default:										 
									break;
					}
					DIO_voidControlPin(pin); // Control Pull Up Res
					break;
		default:    break;
	}
}
void DIO_voidControlPin(PIN * pin)
{
	switch(pin->Value)
	{
		case HIGH :
					switch(pin->PortName)
					{ 
						case PORTA: SET_BIT(PORTA_REG,pin->PinNumber);  break;
						case PORTB: SET_BIT(PORTB_REG,pin->PinNumber);  break;
						case PORTC: SET_BIT(PORTC_REG,pin->PinNumber);  break;
						case PORTD: SET_BIT(PORTD_REG,pin->PinNumber);  break;
						default:							      	    break; 
					}
					break;
		case LOW :
					switch(pin->PortName)
					{ 
						case PORTA: CLEAR_BIT(PORTA_REG,pin->PinNumber);  break;
						case PORTB: CLEAR_BIT(PORTB_REG,pin->PinNumber);  break;
						case PORTC: CLEAR_BIT(PORTC_REG,pin->PinNumber);  break;
						case PORTD: CLEAR_BIT(PORTD_REG,pin->PinNumber);  break;
						default:							         	  break; 
					}
					break;
					break;
		
	}
}
void DIO_GetPinValue(PIN * pin)
{
	switch(pin->PortName)
	{ 
		case PORTA: pin->Value = GET_BIT(PINA_REG,pin->PinNumber);   break;
		case PORTB: pin->Value = GET_BIT(PINB_REG,pin->PinNumber);   break;
		case PORTC: pin->Value = GET_BIT(PINC_REG,pin->PinNumber);   break;
		case PORTD: pin->Value = GET_BIT(PIND_REG,pin->PinNumber);   break;
		default:							         				 break; 
	}
}