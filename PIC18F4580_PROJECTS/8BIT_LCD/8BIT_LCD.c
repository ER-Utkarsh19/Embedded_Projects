#include<p18f4580.h>
#define  rs PORTCbits.RC0
#define  rw PORTCbits.RC1
#define  e    PORTCbits.RC2

void delay(int a)
{
int i,j;
for(i=0;i<255;i++)
for(j=0;j<i;j++);
}

void lcd_init()
{
TRISC=0X00;
TRISD=0X00;


}
void lcd_cmd(char cm)
{
PORTD=cm;
rs=0;
rw=0;
e=1;
delay(100);
e=0;
}
void lcd_data(char dt)
{
PORTD=dt;
rs=1;
rw=0;
e=1;
delay(100);
e=0;
}

int main()
{
lcd_init();
delay(20);
lcd_cmd(0x38);// configure display for 16x2 matrix
lcd_cmd(0x0E); //turn on display and start blinking cursor
lcd_cmd(0x01); //clear display screen
lcd_cmd(0x06);//move cursor to right
lcd_cmd(0x80); //set cursor to first line
//lcd data
lcd_data('U');
lcd_data('T');
lcd_data('K');
lcd_data('A');
lcd_data('R');
lcd_data('S');
lcd_data('H');
lcd_cmd(0xc0);
lcd_data('S');
lcd_data('A');
lcd_data('L');
lcd_data('O');
lcd_data('K');
lcd_data('H');
lcd_data('E');
}