
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#include "LED_Interface.h"
#include "LED_Private.h"
#include "LED_Config.h"


// void LED_voidInitLED(u8 PortName, u8 PinNumber)
// {
//     DIO_voidSetPinDirection(PortName,PinNumber,OUTPUT);
// }

// void LED_voidSetLEDstatus(u8 PortName, u8 PinNumber, u8 LEDstatus)
// {
//     switch(LEDstatus)
//     {
//         case ON : DIO_voidSetPinValue(PortName,PinNumber,HIGH); break;
//         case OFF: DIO_voidSetPinValue(PortName,PinNumber,LOW);  break;
//     }
// }

void LED_InitLED(LED * Ps_Led)
{
    Ps_Led->pin.Direction = OUTPUT;
    Ps_Led->pin.Value     = LOW   ;
    DIO_voidInitPin(&(Ps_Led->pin));
}

void LED_SetLEDstatus(LED * Ps_Led)
{
    switch(Ps_Led->Status)
    {
        case ON : 
                Ps_Led->pin.Value = HIGH;
                DIO_voidControlPin(&(Ps_Led->pin));  
                break;
        case OFF: 
                Ps_Led->pin.Value = LOW;
                DIO_voidControlPin(&(Ps_Led->pin));  
                break;
    }
}