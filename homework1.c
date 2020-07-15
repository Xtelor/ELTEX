#include <stdio.h>

int main() { 
    int a = 0xBACCBBDD;
    unsigned char c;
    
    printf("a = %x\n", a);
    c = (a & 0xFF);
    printf("First byte is %x\n", c);
    c = ((a >> 8) & 0xFF);
    printf("Second byte is %x\n", c);
    c = ((a >> 16) & 0xFF);
    printf("Third byte is %x\n", c);
    c = ((a >> 24) & 0xFF);
    printf("Fourth byte is %x\n", c);
    
    a = (a & 0xFFFF00FF) | 0x0000AA00;
    a = (a | 0x0000AA00);
    printf("New a = %x\n", a);
    
    return 0;
}
