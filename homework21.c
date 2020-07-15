#include <stdio.h>
#include <stdlib.h>

int main() {
    int N = 0, *a;
    printf("Enter the N: \n");
    scanf("%d", &N);
    a = malloc(N*N*sizeof(int));
    
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            a[i * N + j] = N * i + j + 1;
            printf("%d\t", a[i * N + j]);
        }
        printf("\n\v");
    }
    
    free(a);
    return 0;
    }
