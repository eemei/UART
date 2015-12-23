#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "Time.h"
#include "Gpio.h"
#include "UART.h"


uint8_t DR = {'N'};

int main(void) {


	 ConfigureUSART();
	 ConfigureGPIO_mode (PIN_9, PORTA);
	 ConfigureGPIO_PA (PIN_2, PORTA);
	 ConfigureGPIO_Speed (PIN_9, PORTA);
	 ConfigurePULL (PIN_9, PORTA);

	//configurePort(GPIO_MODE_OUTPUT, PIN_14,	PORTA);
	//configurePort(GPIO_MODE_OUTPUT, PIN_13,	PORTG);
	//configurePort(GPIO_MODE_OUTPUT, PIN_5,	PORTC);
	//configurePort(GPIO_MODE_OUTPUT, PIN_13,	PORTB);
	//configurePortInput(PIN_0, PORTA);
	//int SignalR;
		USART1->USART_DR = 0x5;


    while(1) {

    	//USART1->USART_DR = 0xa;

    	// SignalR = PORTA->IDR & 1;
    	// if (SignalR){
    		// writeOne(PIN_14, GPIOG);
    		// writeZero(PIN_13, GPIOG);

    	 }

    	 //else{
    		// writeZero(PIN_14, GPIOG);
    		 //writeOne(PIN_13, GPIOG);
    	 //}

    //}

}


//delay(1000000);
//writeOne(PIN_14, GPIOG);
//writeZero(PIN_13, GPIOG);
//writeOne(PIN_5, GPIOC);   //pc5
//writeZero(PIN_13, GPIOB); //pb13

//delay(1000000);
//writeZero(PIN_14, GPIOG);
//writeOne(13, GPIOG);
//writeZero(PIN_5, GPIOC);
//writeOne(PIN_13, GPIOB);
