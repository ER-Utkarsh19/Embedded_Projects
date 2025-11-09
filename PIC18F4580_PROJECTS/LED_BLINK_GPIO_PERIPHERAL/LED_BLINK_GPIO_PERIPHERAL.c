#include <p18f4580.h>
#define led PORTCbits.RC0
#define led_dir TRISCbits.RC0
void delay(int a)
{
	int i,j;
	for(i=0;i<255;i++)
	for(j=0;j<i;j++);
}

int main()
{
	led_dir=0;// set gpio as output
	while(1) //infinite loop
	{
		led=1// on
		delay(100);
		led=0;//off
		delay(100);
	}
}