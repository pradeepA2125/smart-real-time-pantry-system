#include<lpc21xx.h>


void uart1_init(void){
	PINSEL0 |= (1<<16)|(1<<18);
	U1LCR =  (1<<0)|(1<<1)|(1<<7);
	U1DLL = 97;
	U1LCR = (1<<1)|(1<<0);
}

char uart1_rx(void)
{
	while(!(U1LSR & 1<< 0));
	return U1RBR;
}

void uart1_tx(char ch)
{
	while(!(U1LSR  & 1<< 5));
	 U1THR = ch;
}

void uart1_num(int num)
{
	if(num)
	{
		uart1_num(num/10);
		uart1_tx((num%10)+0x30);
	}
}

void uart1_str(char *ptr)
{

	while(*ptr)
	{
		uart1_tx(*ptr);
		ptr++;
	}	
}

