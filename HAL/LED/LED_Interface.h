#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

// typedef struct led {
//     u8 PortName;
//     u8 PinNumber;
// }LED;

typedef struct led {
    PIN pin;
    u8  Status;
}LED;

void LED_voidInitLED(u8 PortName, u8 PinNumber);
void LED_voidSetLEDstatus(u8 PortName, u8 PinNumber, u8 LEDstatus);


void LED_InitLED(LED * Ps_Led);
void LED_SetLEDstatus(LED * Ps_Led);

#endif /* LED_INTERFACE_H_ */