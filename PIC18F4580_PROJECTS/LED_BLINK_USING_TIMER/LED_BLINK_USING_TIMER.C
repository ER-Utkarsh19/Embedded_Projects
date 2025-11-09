#include <p18f4580.h>
#define LED PORTCbits.RC0 

void T1_delay_10ms()
{
T1CON=0B00100000; //4 FOSC, 16BIT,1;4 PRESCALER 
TMR1H=0XD8;
TMR1L=0XBF; //10MS DELAY
T1CONbits.TMR1ON=1;
while( PIR1bits.TMR1IF ==0);
 PIR1bits.TMR1IF = 0; //CLEAR FLAG BITS
T1CONbits.TMR1ON=0;//OFF
}
int main()
{
TRISCbits.RC0=0;
while(1)
{
LED=1;
 T1_delay_10ms();
LED=0;
 T1_delay_10ms();
}
}
