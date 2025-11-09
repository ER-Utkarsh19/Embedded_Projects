#include <p18f4580.h>

#define RS PORTCbits.RC0
#define RW PORTCbits.RC1
#define E PORTCbits.RC2

void lcd_cmd(char cm);
void lcd_data(char dt);
void lcd_init (void);
void lcd_name(const rom char *ptr);
void delay(int a);

void main() {
    TRISC = 0x00; // Set PORTC as output for LCD control lines
    TRISD = 0x00; // Set PORTD as output for LCD data lines

    lcd_init(); // Initialize LCD
    
    while (1) {  
        lcd_cmd(0x01); // Clear display
        lcd_name("utkarsh"); // Display first name
        lcd_cmd(0xC0); // Move cursor to the second line
        lcd_name("salokhe"); // Display surname

        delay(200); // Delay to keep the display stable before refreshing
    }
}

void lcd_cmd(char cm) {
	char temp;
	temp=(cm&0xF0);
    PORTD = temp;  
    RS = 0;      
    RW = 0;      
    E = 1;       
    delay(100);  
    E = 0; 
    temp=(cm&0x0F);
    temp=temp<<4;
    PORTD=temp;
    E=1;
    delay(100);
    E=0;      
}

void lcd_data(char dt) {
	char temp;
	temp=(dt&0xF0);
	 PORTD = temp; 
   
    RS = 1;      
    RW = 0;      
    E = 1;       
    delay(100);  
    E = 0; 
     temp=(dt&0x0F);
    temp=temp<<4;
    PORTD=temp;
    E=1;
    delay(100);
    E=0;         
}

void lcd_init() {
lcd_cmd(0x02);
    lcd_cmd(0x28); // Function set: 4-bit, 2 line, 5x7 dots
    lcd_cmd(0x0E); // Display ON, cursor ON
    lcd_cmd(0x01); // Clear display
    lcd_cmd(0x06); // Entry mode: Increment cursor
    lcd_cmd(0x80); // Move cursor to beginning of the first line
}

void lcd_name(const rom char *ptr) {
    while (*ptr != '\0') {
        lcd_data(*ptr);
        ptr++;
    }
}

void delay(int a) {
    int i, j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < 255; j++); 
    }
}
