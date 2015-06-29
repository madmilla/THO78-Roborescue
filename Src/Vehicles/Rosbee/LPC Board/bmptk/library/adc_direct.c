#include "LPC11xx.h"
#include "adc_direct.h"

void conversion_init(){
	//enable ADClock
	LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 13);
	//enable IOCON
	LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 16);
	
	// make pull up and pull down resitors inactive
	LPC_IOCON->R_PIO1_0 |= (1 << 3);
	
	//make xx10 for pin 1_0 CONNECT TO PIN 1-0!!!!
	LPC_IOCON->R_PIO1_0 &= ~(7);	//write lowest 2 bits to 0
	LPC_IOCON->R_PIO1_0 |= (2);//write second bit to 1

	//set pin 1_0 ADMODE to Analog
	LPC_IOCON->R_PIO1_0 &= ~(1 << 7);//write ADMODE bit to 0

	//enable power
	LPC_SYSCON->PDRUNCFG &= ~(1 << 4);

	//select pin 1_0 (FUNC to AD1) in ADConf set others off
	LPC_ADC->CR &= ~(255); //255 = 11111111
	LPC_ADC->CR |= 2;	 //1 makes 00000001

	//divide clock by 3 (12 /3 = 4)
	LPC_ADC->CR &= ~(255 << 8);
	LPC_ADC->CR |= (2 << 8);    //2 makes 00000010 (+1)

	//BURST to software
	LPC_ADC->CR &= ~(1 << 16);
}

unsigned int conversion_value(){
	//start the conversion
	LPC_ADC->CR &= ~(7 << 24);
	LPC_ADC->CR |= (1 << 24);

	//wait for result
	while ((LPC_ADC->GDR & (1 << 31)) != 0){}

	//read value with mask
	unsigned int tempvalue = (LPC_ADC->GDR & (1023 << 6));
	return tempvalue >> 6;
}