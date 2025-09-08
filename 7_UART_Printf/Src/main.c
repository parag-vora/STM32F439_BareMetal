#include"stm32f4xx.h"
#include<stdio.h>

/*Enable clock to Peripheral*/
#define USART3EN				(1U<<18)
#define GPIODEN					(1U<<3)

/*Peripheral*/
#define	PIND8					(1U<<8) //PD8
#define PIND9					(1U<<9) //PD9
#define USART3_Tx				PIND8
#define USART3_Rx				PIND9
#define CR1_TE					(1U<<3)
#define CR1_UE					(1U<<13)
#define SR_TXE					(1U<<7)

/*Configure UART data*/
#define SYS_FREQ				16000000
#define APB1_CLK				SYS_FREQ
#define USART3_BAUDRATE			115200

void USART3_init(void);
void USART3_Transmit(int);
void USART_SET_BAUDRATE(USART_TypeDef *, uint32_t, uint32_t);
uint32_t CALCULATE_BAUDRATE(uint32_t, uint32_t);

int __io_putchar(int ch){

	USART3_Transmit(ch);
	return ch;
}

int main(){

	USART3_init();
	while(1){
		printf("Hello STM32.....\n\r");
	}


	return 0;
}


void USART3_init(void){

	/***************Configure GPIOD***************/

		/*Enable clock access to GPIOD*/
		RCC->AHB1ENR |= GPIODEN;

		/*set PD8 as Alternating Function*/
		GPIOD->MODER &= ~(1U<<16);
		GPIOD->MODER |=  (1U<<17);

		/*set PD9 as Alternating Function*/
		GPIOD->MODER &= ~(1U<<18);
		GPIOD->MODER |=  (1U<<19);

		/*set PD8 as Alternation Function AF7*/
		GPIOD->AFR[1] |= (1U<<0);
		GPIOD->AFR[1] |= (1U<<1);
		GPIOD->AFR[1] |= (1U<<2);
		GPIOD->AFR[1] &= ~(1U<<3);

		/*set PD9 as Alternating Function AF7*/
		GPIOD->AFR[1] |= (1U<<4);
		GPIOD->AFR[1] |= (1U<<5);
		GPIOD->AFR[1] |= (1U<<6);
		GPIOD->AFR[1] &= ~(1U<<7);

		/***************Configure UART***************/

		/*Enable clock access to USART3*/
		RCC->APB1ENR |= USART3EN;

		/*Baudrate*/
		USART_SET_BAUDRATE(USART3, APB1_CLK, USART3_BAUDRATE);

		/*Transfer direction*/
		USART3->CR1 |= CR1_TE;

		/*Enable USART3*/
		USART3->CR1 |= CR1_UE;

}

void USART3_Transmit(int ch){

	/*Check the Transmit Data buffer*/
	while(!(USART3->SR & SR_TXE));

	/*Write to Data register*/
	USART3->DR = (ch & 0xFF);
}

void USART_SET_BAUDRATE(USART_TypeDef *USARTx, uint32_t periph_clock, uint32_t baudrate){

	USARTx->BRR = CALCULATE_BAUDRATE(periph_clock, baudrate);
}

uint32_t CALCULATE_BAUDRATE(uint32_t periph_clock, uint32_t baudrate){
	return periph_clock/baudrate;
}
