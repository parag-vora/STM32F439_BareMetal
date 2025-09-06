#include"stm32f4xx.h"

#define GPIOBEN					(1U<<1)
#define GPIOCEN					(1U<<2)
#define	PIN7					(1U<<7)  //PB7
#define PIN13					(1U<<13) //PC13

#define LED2_PIN				PIN7
#define USER_BUTTON				PIN13

int main(){

	/*Enable clock access to GPIOB*/
	RCC->AHB1ENR |= GPIOBEN;

	/*Enable clock access to GPIOC*/
	RCC->AHB1ENR |= GPIOCEN;

	/*set PB7 as Digital output*/
	GPIOB->MODER |= (1U<<14);
	GPIOB->MODER &= ~(1U<<15);

	/*set PC13 as Digital Input*/
	GPIOC->MODER &= ~(1U<<26);
	GPIOC->MODER &= ~(1U<<27);

	while(1){

		/*Read the RC13 PIN*/
		if(GPIOC->IDR & (USER_BUTTON)){
			GPIOB->ODR |= LED2_PIN;
		} else {
			GPIOB->ODR &= ~LED2_PIN;
		}
	}


	return 0;
}
