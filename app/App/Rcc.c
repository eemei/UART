
#include "Rcc.h"
#include "UART.h"

void gpioUnresetEnableClock(GPIO* port){
	int shift = ((int)port - (0x40020000))/(0x400);
	RCC_reg->RCC_AHB1RSTR &= ~(1 << (shift));
	RCC_reg->RCC_AHB1ENR |= (0x00100000 | ~(0 << (shift)));
}

void UARTUnresetEnableClock (){
	RCC_reg->RCC_APB2RSTR &= ~(1 << 4 );
	RCC_reg->RCC_APB2ENR |= (1 << 4 );
	uint32_t status = RCC_reg->RCC_APB2ENR;
}
