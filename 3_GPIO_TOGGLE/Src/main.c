#include"stm32f4xx.h"

#define GPIOBEN					(1U<<1)
#define	LED2_PIN				(1U<<7)

int main(){

	/*Enable clock access to GPIOB*/
	RCC->AHB1ENR |= GPIOBEN;

	/*set PB7 as output*/
	GPIOB->MODER |= (1U<<14);
	GPIOB->MODER &= ~(1U<<15);

	while(1){
		/*set PB7 as a high*/
		//GPIOB_OD_R |= LED2_PIN;

		/*toggle PB7 */
		GPIOB->ODR ^= LED2_PIN;
		for(int i = 0; i <= 100000; i++);

	}


	return 0;
}
