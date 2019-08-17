#include<lpc21xx.h>


void uart_init(void){
	PINSEL0 |= (1<<0)|(1<<2);

	U0LCR =  (1<<0)|(1<<1)|(1<<7);
	U0DLL = 97;
	U0LCR = (1<<1)|(1<<0);
	U0FCR = 0x01;
}

char uart_rx(void)
{
	while(!(U0LSR & 1<< 0));
	return U0RBR;
}

void uart_tx(char ch)
{
	while(!(U0LSR  & 1<< 5));
	 U0THR = ch;
}
void uart_str(char *ptr)
{

	while(*ptr)
	{
		uart_tx(*ptr);
		ptr++;
	}	
}

void uart_num(int num)
{
	if(num)
	{
		uart_num(num/10);
		uart_tx((num%10)+0x30);
	}
}





