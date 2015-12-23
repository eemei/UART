#include "Gpio.h"
#include "stm32f4xx_hal_rcc.h"


 void configurePort(int direction, int pinNum, GPIO *port) {

	 gpioUnresetEnableClock(port);
	 port->MODER &= ~(3<<(pinNum* 2));			//mode.pin= output
	 port->MODER |= direction << (pinNum * 2);

	 port->OTYPER &= ~(3<<(pinNum* 2));			//otype.pin = push-pull;
	 port->OTYPER |= 0 << (pinNum);

	 port->OSPEEDR &= ~(3 << (pinNum* 2));		//ospeed.pin = high speed;
	 port->OSPEEDR |= VERY_HIGH_SPEED << (pinNum * 2);
 	 }

 void configurePortInput(int pinNum, GPIO *port){
	 port->PUPDR &= ~(3 << (pinNum* 2));
	 port->PUPDR |= PULL_DOWN << (pinNum * 2);
 }

void writeOne(uint16_t pinNum, GPIO *port) {
	//HAL_GPIO_WritePin(port, pinNum, GPIO_PIN_SET);
	port->ODR &= ~( 1 << (pinNum));
	port->ODR |= 1 << (pinNum);
	}

void writeZero (uint16_t pinNum, GPIO *port){
	//HAL_GPIO_WritePin(port,pinNum, GPIO_PIN_RESET);
	port->ODR &= ~( 1 << (pinNum));
	port->ODR |= 0 << (pinNum);
	}

void ReadOne (uint16_t pinNum, GPIO *port) {
	port->IDR &= 1;
}

void portBitSetReset (int pinNum, GPIO *port){
	port->BSRR = 0x00006000;
}

void ConfigureGPIO_mode (uint16_t pinNum, GPIO *port){
	gpioUnresetEnableClock(port);
	port->MODER &= ~(3 << (pinNum* 2));
	port->MODER |= (2 << (pinNum* 2));

	uint32_t statusMode = port->MODER;
}

void ConfigureGPIO_PA (uint16_t pinNum, GPIO *port){
	port->AFRH &= ~(0xf << (pinNum* 2) );
	port->AFRH |= (7 << (pinNum* 2));

	uint32_t statusPA = port->AFRH;
}

void ConfigureGPIO_Speed (uint16_t pinNum, GPIO *port){
	port->OSPEEDR &= ~(3 << (pinNum* 2));
	port->OSPEEDR |= (VERY_HIGH_SPEED << (pinNum* 2));

	uint32_t statusSpeed = port->OSPEEDR;
}

void ConfigurePULL (uint16_t pinNum, GPIO *port){
	port->PUPDR &= ~(3 << (pinNum *2));
	port->PUPDR |= (2 << (pinNum *2));


}
