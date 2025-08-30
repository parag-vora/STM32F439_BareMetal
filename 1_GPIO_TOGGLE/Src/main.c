
#define PERIPH_BASE		 		(0x40000000UL)

#define AHB1PERIPH_OFFSET		(0x00020000UL)
#define AHB1PERIPH_BASE			(PERIPH_BASE + AHB1PERIPH_OFFSET)

#define GPIOB_OFFSET			(0x0400UL)
#define GPIOB_BASE 				(AHB1PERIPH_BASE + GPIOB_OFFSET)

#define RCC_OFFSET 				(0x3800UL)
#define RCC_BASE				(AHB1PERIPH_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET			(0x30UL)
#define RCC_AHB1EN_R			(*(volatile unsigned int*)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET			(0x00UL)
#define GPIOB_MODE_R 			(*(volatile unsigned int*)(GPIOB_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET				(0x14UL)
#define GPIOB_OD_R				(*(volatile unsigned int*)(GPIOB_BASE + OD_R_OFFSET))

#define GPIOBEN					(1U<<1)
#define	LED2_PIN				(1U<<7)


int main(){

	/*Enable clock access to GPIOB*/
	RCC_AHB1EN_R |= GPIOBEN;

	/*set PB7 as output*/
	GPIOB_MODE_R |= (1U<<14);
	GPIOB_MODE_R &= ~(1U<<15);

	while(1){
		/*set PB7 as a high*/
		//GPIOB_OD_R |= LED2_PIN;

		/*toggle PB7 */
		GPIOB_OD_R ^= LED2_PIN;
		for(int i = 0; i <= 100000; i++);

	}


	return 0;
}
