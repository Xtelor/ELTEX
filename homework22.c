#include <stdio.h>
#include <stdlib.h>

int main() {

    int i = 0;
    int N, *a;
    printf("Enter the N: \n");
    scanf("%d", &N);
    a = malloc(N * sizeof(int));
    
    do { 
        printf("Fill in the array: \n");
        scanf("%d", &a[i]);
        i++;
    } while (i != N);
    
    printf("Input: \n");
    
    for(int i = 0; i < N; i++) {
        printf("%d\t", a[i]);
    }
    
    printf("\n");
    printf("Output: \n");
    
    for(int i = 0; i < N; i++) {
        printf("%d\t", a[N - i - 1]);
    }
    printf("\n");
   
    free(a);
    return 0;
    }
