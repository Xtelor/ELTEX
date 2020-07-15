#include <stdio.h>
#include <stdlib.h>

int main() {
   
    int N = 0, *a;
    printf("Enter the N: \n"); 
    scanf("%d", &N);
    a = malloc(N * N * sizeof(int));
    int i = 0, j = 0;
    int L = 1, C = 1;
   
    if (N % 2 != 0) {           
        a[N / 2 * N + N / 2]= N * N;  
    }
   
    while(L <= N / 2) {
        j = L - 1;          
        i = L;
        while ( j < N - L + 1 || i < N - L + 1 ) {
            if (j < N - L + 1 ) {               
                a[(L - 1) * N + j] = C;              
                C++;
                j++;
            }
            else {                
                a[i * N + (N - L)] = C;
                C++;
                i++;
            } 
        }
        i = N - 1 - L;    
        j = N - 1 - L;
        while ( j >= L - 1 || i > L - 1 ) {
            if( j >= L - 1) {
                a[(N - L) * N + j] = C;
                C++;
                j--;
            }
            else{
                a[i * N + (L - 1)] = C;
                C++;
                i--;
            }
        }
        L++;
    }
    
    printf("Matrix: \n");
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d\t", a[i * N + j]);
        }
        printf("\n\v");
    }
    
    free(a);
    return 0;   
  
}
