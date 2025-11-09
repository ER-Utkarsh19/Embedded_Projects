#include<p18f4580.h>
#define  IN1 PORTCbits.RC0
#define  IN2 PORTCbits.RC1
#define  EN1 PORTCbits.RC2

#define Dir_IN1 TRISCbits.RC0
#define Dir_IN2 TRISCbits.RC1
#define Dir_EN1 TRISCbits.RC2

void delay(int a)
{
	int i,j;
	for(i=0;i<255;i++)
	for(j=0;j<i;j++);
}

int main()
{
	Dir_IN1=Dir_IN2=Dir_EN1=0;
	
	while(1)
	{
		IN1=EN1=1; //clk wise operation
		IN2=0;
		delay(100);
		
		IN1=IN2=EN1=0; // motor off
		delay(100);
		
		IN1=0;
		IN2=EN1=1;
		delay(100); //anti clk wise operation
		
		IN1=IN2=EN1=0; // motor off
		delay(100);
		
	}	
	
}
		