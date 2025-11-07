#include<p18f4580.h>
#define buzzer PORTCbits.RC0
#define Dir_buzzer TRISCbits.RC0

#define sw   PORTCbits.RC1
#define Dir_switch TRISCbits.RC1

void delay(int a)
{
	int i,j;
	for(i=0;i<255;i++)
	for(j=0;j<i;j++);
}

int main()
{
	Dir_buzzer=0; //set as output
	Dir_switch =1; // set as input
	
	while(1)
	{
		if(sw==0)
		{
			buzzer=1;
			delay(100);
		}	
		else
		{
			buzzer=0;
			delay(100);
		}
	}
}