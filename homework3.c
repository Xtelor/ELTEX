#include <stdio.h>

int main() { 
    int a,n,m;
    char *ptr;
   
    printf("Enter the a: \n"); 
    scanf("%d", &a);
    
    ptr = (char*) &a;
    printf("First byte of a = %d\n", *ptr);
    ptr++;
    printf("Second byte of a = %d\n", *ptr);
    ptr++;
    printf("Third byte of a = %d\n", *ptr);
    ptr++;
    printf("Fourth byte of a = %d\n", *ptr);
    
    printf("Which byte do you want to change?(1/2/3/4) \n");
    scanf("%d", &n);
    printf("Enter new amount of this byte: \n");
    scanf("%d", &m);
    
    ptr = (char*) &a;
    ptr += n - 1;
    *ptr = m;
    
    printf("New a = %d\n", a);
    
    ptr = (char*) &a;
    printf("First byte of new a = %d\n", *ptr);
    ptr++;
    printf("Second byte of new a = %d\n", *ptr);
    ptr++;
    printf("Third byte of new a = %d\n", *ptr);
    ptr++;
    printf("Fourth byte of new a = %d\n", *ptr);
    
    return 0;
}
