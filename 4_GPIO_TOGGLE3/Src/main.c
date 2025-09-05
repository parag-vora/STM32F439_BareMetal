#include"stm32f4xx.h"

#define GPIOBEN					(1U<<1)
#define	LED2_PIN_SET			(1U<<7)
#define LED2_PIN_RESET 			(1U<<23)

int main(){

	/*Enable clock access to GPIOB*/
	RCC->AHB1ENR |= GPIOBEN;

	/*set PB7 as output*/
	GPIOB->MODER |= (1U<<14);
	GPIOB->MODER &= ~(1U<<15);

	while(1){

		/*toggle PB7 */
		GPIOB->BSRR |= LED2_PIN_SET;
		for(int i = 0; i <= 100000; i++);

		GPIOB->BSRR |=  LED2_PIN_RESET;
		for(int i = 0; i <= 100000; i++);

	}


	return 0;
}
