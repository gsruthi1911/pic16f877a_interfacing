#include <xc.h>
#define _XTAL_FREQ 20000000
void main(void) {
    int i;
    TRISB=0;
    PORTB=0;
    unsigned char a[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
    while(1)
    {
        for(i=0;i<10;i++)
        {
            PORTB=a[i];
            __delay_ms(1000);
        }      
    }
    return;
}
