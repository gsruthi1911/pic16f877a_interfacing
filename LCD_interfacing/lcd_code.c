#include <xc.h>
#define _XTAL_FREQ 20000000

#define lcd PORTB
#define RS RD0
#define RW RD1
#define E RD2

void cmd(unsigned char command)
{
lcd = command;
 RS = 0;
 RW = 0;
 E = 1;
 __delay_ms(10);
 E = 0;
}
void data(unsigned char data)
{
lcd = data;
 RS = 1;
 RW = 0;
 E = 1;
__delay_ms(10);
 E = 0;
}
void main(void) {
    TRISB = 0;
 TRISD = 0;
cmd(0x38);
cmd(0x0E);
cmd(0x01);
cmd(0x06);
cmd(0x80);
data('a');
data('b');
data('c');
data('d');
data('e');
data('f');
data('g');
data('h');
while(1){}
    return;
}
