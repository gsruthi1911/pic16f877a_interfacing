#include <xc.h>
#define _XTAL_FREQ 20000000

#define rs RD5
#define rw RD6
#define en RD7
#define lcd PORTB

#define r1 RC0
#define r2 RC1
#define r3 RC2
#define r4 RC3
#define c1 RC4
#define c2 RC5
#define c3 RC6
#define c4 RC7

void data(unsigned char d)
{
    lcd=d;
    rs=1;
    rw=0;
    en=1;
    __delay_ms(1);
    en=0;
}

void comm(unsigned char command)
{
    lcd=command;
    rs=0;
    rw=0;
    en=1;
    __delay_ms(1);
    en=0;
}

void keypad()
{
    TRISC=0xF0;
    r1=1;r2=0;r3=0;r4=0;
    if(c1==1)
    {
        data('7');
        while(1);
    }
    if(c2==1)
    {
        data('8');
        while(1);
    }
    if(c3==1)
    {
        data('9');
        while(1);
    }
    if(c4==1)
    {
        data('/');
        while(1);
    }
    
    r1=0;r2=1;r3=0;r4=0;
    if(c1==1)
    {
        data('4');
        while(1);
    }
    if(c2==1)
    {
        data('5');
        while(1);
    }
    if(c3==1)
    {
        data('6');
        while(1);
    }
    if(c4==1)
    {
        data('*');
        while(1);
    }
    
    r1=0;r2=0;r3=1;r4=0;
    if(c1==1)
    {
        data('1');
        while(1);
    }
    if(c2==1)
    {
        data('2');
        while(1);
    }
    if(c3==1)
    {
        data('3');
        while(1);
    }
    if(c4==1)
    {
        data('-');
        while(1);
    }
    
    r1=0;r2=0;r3=0;r4=1;
    if(c1==1)
    {
        data('o');
        data('n');
        data('/');
        data('c');
        while(1);
    }
    if(c2==1)
    {
        data('0');
        while(1);
    }
    if(c3==1)
    {
        data('=');
        while(1);
    }
    if(c4==1)
    {
        data('+');
        while(1);
    }
    
    
}
void main(void) {
    
    TRISB=0;
    TRISD=0;
    comm(0x38);
    comm(0x0c);
    comm(0x06);
    comm(0x01);
    comm(0x80);
    data('k');
    data('e');
    data('y');
    data('p');
    data('a');
    data('d');
    while(1)
    {
    comm(0xc0);
    keypad();
    }
    
    return;
}
