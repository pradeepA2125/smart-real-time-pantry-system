#include<lpc21xx.h>
#include"..\lcd.c"
#include"..\lcd_header.h"
#define IRPIN (0<<21)
#include<string.h>

void display_menu(void){
		uart_str("\r\n");
		uart_str("items				price");
		uart_str("\r\n");
		uart_str("1.jeera rice			70rs/-");
		uart_str("\r\n");
		uart_str("2.chapati curry			50rs/-");
		uart_str("\r\n");
		uart_str("3.masala dosa			50rs/-");
		uart_str("\r\n");
		uart_str("4.idly-vada			30rs/-");
		uart_str("\r\n");
		uart_str("5.curd rice			30rs/-");
		uart_str("\r\n");
		uart_str("6.pulka				50rs/-");
		uart_str("\r\n");

}
int main(){
	char ch[50];
	int i=0,j=0,flag=0;
	int IR;
	char *pnr[3];
pnr[0] = "1234567890\r";
pnr[1] = "8618117368\r";
pnr[2] = "7795869229\r";


	IODIR0 = IRPIN;
	

	 lcd_init();
	 uart_init();
while(1){
 IR = IOPIN0 & 1<<21;
	 if(IR){
	 	uart_str("welcome,please enter pnr :");
		
	 	ch[i] = uart_rx();
		lcd_data(ch[i]);
		while(ch[i] != '\r')
		{
		  i++;
		  ch[i] = uart_rx();
		}
	disp_str(ch);
	uart_str(ch);
	for(j=0;j<4;j++){
		uart_str("\r\n");
		if(!(strcmp(pnr[j],ch))){
			flag = 1;
			break;
			}
		}
		if(flag==0){
		uart_str("\r\n");
		uart_str("authentication failed");
	    }
		else
		display_menu();	
	}
	else
	uart_str("indian_railways");
}
}
