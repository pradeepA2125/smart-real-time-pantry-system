#include<lpc21xx.h>
#define col (0x0f<<17)
#define row (0x0f<<21)
#include"..\lcd.c"
#include"..\lcd_header.h"

void keypad()
{
	int y,z;
	lcd_init();
	
	while(1){
		IODIR1 = col;
		IOCLR1 = col;
		IOSET1 = row;
		
		z = (IOPIN1 & row);
		z = z>>21;
		
		switch(z){
		
		case 0X0E : IODIR1 = row;
					IOCLR1 = row;
					y = (IOPIN1 & col);
					y = y>>17;
					
					switch(y)
					{
						case 0X0E : disp_str("key pressed = 0");
									IODIR0 =1<<11;
									IOSET0 = 1<<11 ;
									delay(1000);
									IOCLR0 = 1<<11;
									delay(500);
									break;
						
						case 0X0D : disp_str("key pressed = 1");
									delay(500);
									break;
						
						case 0X0B : disp_str("key pressed = 2");
									delay(500);
									break;
						
						case 0X07 : disp_str("key pressed = 3");
									delay(500);
									break;
					}
		
		
		case 0X0D : IODIR1 = row;
					IOCLR1 = row;
					y = (IOPIN1 & col);
					y = y>>17;
					
					switch(y)
					{
						case 0X0E : disp_str("key pressed = 4");
									delay(500);
									break;
						
						case 0X0D : disp_str("key pressed = 5");
									delay(500);
									break;
						
						case 0X0B : disp_str("key pressed = 6");
									delay(500);
									break;
						
						case 0X07 : disp_str("key pressed = 7");
									delay(500);
									break;
					}
		
		case 0X0B : IODIR1 = row;
					IOCLR1 = row;
					y = (IOPIN1 & col);
					y = y>>17;
					
					switch(y)
					{
						case 0X0E : disp_str("key pressed = 8");
									delay(500);
									break;
						
						case 0X0D : disp_str("key pressed = 9");
									delay(500);
									break;
						
						case 0X0B : disp_str("key pressed = A");
									delay(500);
									break;
						
						case 0X07 : disp_str("key pressed = B");
									delay(500);
									break;
					}

	   	case 0X07 : IODIR1 = row;
					IOCLR1 = row;
					y = (IOPIN1 & col);
					y = y>>17;
					
					switch(y)
					{
						case 0X0E : disp_str("key pressed = C");
									delay(500);
									break;
						
						case 0X0D : disp_str("key pressed = D");
									delay(500);
									break;
						
						case 0X0B : disp_str("key pressed = E");
									delay(500);
									break;
						
						case 0X07 : disp_str("key pressed = F");
									delay(500);
									break;
					}
	
		}
	
	}

}
		
	
					
							

