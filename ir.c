#include<lpc21xx.h>
#include"..\lcd.c"
#include"..\keypad.c"
#include"..\lcd_header.h"
#define IRPIN (0<<21)
#include<string.h>
#include<stdbool.h>
char ch[50];
int flag = 0;
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

void quantity(void){
	 int choice ;
	 int quantity;
	 int total;
	 //char ch;
	 uart_str("choose an item :");
	 //U0LSR |= (0<<0);
	delay(100000);	
	 choice = keypad();
	 //ch = uart_rx();
	 uart_num(choice);
	 //uart_tx(ch);
	 uart1_init();
	 switch(choice){

	  case 1: uart_str("\r\n");
	  		  uart_str(" No. of items :");
	  		  quantity = keypad();
			  uart_num(quantity);
			  uart_str("\r\n");
	  		  uart_str("total cost :" );
			  total = quantity*70;
			  uart_num(total);
			  uart1_init();
		  	  uart1_str("jeera rice, Quantity :");
			  uart1_num(quantity); 
			  break;
			   
	   case 2:uart_str("\r\n"); 
	   		  uart_str(" No. of items :	");
	  		  quantity = keypad();
			   uart_num(quantity);
			   uart_str("\r\n");
	  		  uart_str("total cost :" );
			  total = quantity*50;
			  uart_num(total);
			  uart1_str("chapati curry, Quantity :");
			  uart1_num(quantity); 
			  break;

	   case 3:uart_str("\r\n");
	   		  uart_str(" No. of items :	");
	  		  quantity = keypad();
			   uart_num(quantity);
			   uart_str("\r\n");
	  		  uart_str("total cost :" );
			  total = quantity*50;
			  uart_num(total);
			  uart1_str("masala dosa, Quantity :");
			  uart1_num(quantity); 
			  break;

	   case 4: uart_str("\r\n");
	  		  uart_str(" No. of items :	");
	  		  quantity = keypad();
			   uart_num(quantity);
			   uart_str("\r\n");
	  		  uart_str("total cost :" );
			  total = quantity*30;
			  uart_num(total);
			  uart1_str("idly -vada, Quantity :");
			  uart1_num(quantity); 
			  break;
	   
	   case 5: 	uart_str("\r\n");
	   			uart_str(" No. of items :");
	  		  quantity =keypad();
			   uart_num(quantity);
			   uart_str("\r\n");
	  		  uart_str("total cost :" );
			  total = quantity*30;
			  uart_num(total);
			  uart1_str("curd rice, Quantity :");
			  uart1_num(quantity); 
			  break;

	   case 6: 	uart_str("\r\n");
	   uart_str(" No. of items :");
	  		  quantity = keypad();
			   uart_num(quantity);
			   uart_str("\r\n");
	  		  uart_str("total cost :" );
			  total = quantity*50;
			  uart_num(total);
			  uart1_str("pulka, Quantity :");
			  uart1_num(quantity); 
			  break;

	  default : uart_str("please choose valid option");
	  			break;

	 }
}
int main(){
 
int IR ;
int i=0,j=0;
char *pnr[3];


pnr[0] = "1234567890\r";
pnr[1] = "8618117368\r";
pnr[2] = "7795869229\r";

lcd_init();
uart_init();

 
 IODIR0 = 0<<21;
 IODIR1 = 0xFF<<17;
 IOCLR1 = 0xFF<<17;

while(1){
// IR = IOPIN0 & 1<<21;
 if(IOPIN0 & 1<<21){
 		flag=0;
	 	uart_str("welcome,please enter pnr :");
		ch[i] = uart_rx();
		while(ch[i] != '\r')
		{
		    i++;
		  ch[i] = uart_rx(); 
		 
		}
		i=0;
	disp_str(ch);
	uart_str(ch);
	for(j=0;j<4;j++){
		if(!(strncmp(pnr[j],ch,10))){
			flag=1;
			break;
			}
		}
		if(flag>=1){
		   	display_menu();
			quantity();	
		}
		else 
		{		
//		delay(10000);
				uart_str("\r\n");
				uart_str("authentication failed");
				uart_str("please try again");
		}
		
	}
	else {
		uart_str("\r\n");
		uart_str("indian_railways");
		uart_str("\r\n");
		delay(100000);
	}
 }
}
