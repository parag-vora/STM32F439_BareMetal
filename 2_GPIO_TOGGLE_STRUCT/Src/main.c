#include<stdint.h>

#define PERIPH_BASE		 		(0x40000000UL)

#define AHB1PERIPH_OFFSET		(0x00020000UL)
#define AHB1PERIPH_BASE			(PERIPH_BASE + AHB1PERIPH_OFFSET)

#define GPIOB_OFFSET			(0x0400UL)
#define GPIOB_BASE 				(AHB1PERIPH_BASE + GPIOB_OFFSET)

#define RCC_OFFSET 				(0x3800UL)
#define RCC_BASE				(AHB1PERIPH_BASE + RCC_OFFSET)


#define GPIOBEN					(1U<<1)
#define	LED2_PIN				(1U<<7)

#define __IO volatile

typedef struct
{
	__IO uint32_t DUMMY[12];
	__IO uint32_t AHB1ENR;
}RCC_TypeDef;

typedef struct
{
	__IO uint32_t MODER;
	__IO uint32_t DUMMY[4];
	__IO uint32_t ODR;
}GPIO_TypeDef;

#define RCC					((RCC_TypeDef *)RCC_BASE)
#define GPIOB				((GPIO_TypeDef *)GPIOB_BASE)

int main(){

	/*Enable clock access to GPIOB*/
	RCC->AHB1ENR |= GPIOBEN;

	/*set PB7 as output*/
	GPIOB->MODER |= (1U<<14);
	GPIOB->MODER &= ~(1U<<15);

	while(1){
		/*set PB7 as a high*/
		//GPIOB->ODR |= LED2_PIN;

		/*toggle PB7 */
		GPIOB->ODR ^= LED2_PIN;
		for(int i = 0; i <= 100000; i++);

	}


	return 0;
}
