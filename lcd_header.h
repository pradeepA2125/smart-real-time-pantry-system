#include<lpc21xx.h>
#define rs (1<<10)
#define rw (1<<12)
#define en (1<<13)
#define data (0xFF<<15)
#define port (rs|rw|en|data)

void delay(int);

void lcd_data(int);

void lcd_cmd(int);

void lcd_init(void);

void disp_str(char []);
void lcd_num(int );
void uart_init(void);
char uart_rx(void);
void uart_tx(char);
void uart_str(char*);
void uart_num(int);
int keypad(void);

void uart1_init(void);
char uart1_rx(void);
void uart1_tx(char);
void uart1_num(int);
void uart1_str(char*);
