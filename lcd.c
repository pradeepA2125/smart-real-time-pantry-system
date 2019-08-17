#include<lpc21xx.h>
//#include"..\lcd_header.h"
#define rs (1<<10)
#define rw (1<<12)
#define en (1<<13)
#define data (0xFF<<15)
#define port (rs|rw|en|data)

void delay(int count){
	int i,j;
	for(i = 0;i<count;i++)
		for(j=0;j<1000;j++);
}

void lcd_data(int c)
{
	IOCLR0 = 0xFF<<15;
	IOSET0 = c<<15;
	IOSET0 = rs;
	IOCLR0 = rw;
	IOSET0 = en;
	delay(1000);
	IOCLR0 = en;

}

void lcd_cmd(int c)
{			
	IOCLR0 = 0xFF<<15;
	IOSET0 = c<<15;
	IOCLR0 = rs;  // rs = 0
	IOCLR0 = rw;  // rw = 0
	IOSET0 = en;  // en = 1
	delay(1000);
	IOCLR0 = en;  // en = 1

}

void lcd_init(void){

	IODIR0 |= port;
	lcd_cmd(0x38);
	lcd_cmd(0x0E);
	lcd_cmd(0x01);
	lcd_cmd(0x80);

}


void disp_str(char /*str[]*/ *ptr){
	//char *ptr =str;
	lcd_init();
	while(*ptr)
	{
		lcd_data(*ptr);
		ptr++;
	}	
}

void lcd_num(int num)
{
	if(num)
	{
		lcd_num(num/10);
		lcd_data((num%10)+0x30);
	}
}

