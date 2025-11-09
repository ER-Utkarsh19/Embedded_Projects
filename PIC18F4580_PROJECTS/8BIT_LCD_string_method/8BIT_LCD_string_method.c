#include <p18f4580.h>

#define RS PORTCbits.RC0
#define RW PORTCbits.RC1
#define E PORTCbits.RC2

void lcd_cmd(char cm);
void lcd_data(char dt);
void lcd_init (void);
void delay(int a);


void main() {
char name[8] = "Utkarsh"; 
char surname[8] = "salokhe";
int i;

    TRISC = 0x00; 
    TRISD = 0x00; 

    lcd_init(); 
    

    while (1) {  
        lcd_cmd(0x01); 
        delay(1000);   

        for (i = 0; name[i] != '\0'; i++) {
            lcd_data(name[i]);
        }

        lcd_cmd(0xC0); 
        for (i = 0; surname[i] != '\0'; i++) {
            lcd_data(surname[i]);
        }

        delay(2000);  
    }
}

void lcd_cmd(char cm) {
    PORTD = cm;  
    RS = 0;      
    RW = 0;      
    E = 1;       
    delay(100);  
    E = 0;       
}

void lcd_data(char dt) {
    PORTD = dt;  
    RS = 1;      
    RW = 0;      
    E = 1;       
    delay(100);  
    E = 0;       
}

void lcd_init() {
    lcd_cmd(0x38); 
    lcd_cmd(0x0E); 
    lcd_cmd(0x01); 
    lcd_cmd(0x06); 
    lcd_cmd(0x80); 
}

void delay(int a) {
    int i, j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < 255; j++); 
    }
}
