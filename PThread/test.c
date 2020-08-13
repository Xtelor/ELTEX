#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

    long A = 0;
    
    void * func(void * param)
    {
        long tmp;
        
        for(int i = 0; i < 1000000; i ++)
        {
            tmp = A;
            tmp ++;
            A = tmp;        
        }
    }
    int main(void)
    {
        pthread_t tid[1000];
        
        for(int i = 1; i < 1000; i ++)
        {
            pthread_create(&tid[i - 1], NULL, func, (void*)&i);
        
        }
       
        for(int i = 0; i < 999; i ++)
        {
            pthread_join(tid[i], NULL);
        }
        printf("A = %ld\n", A);
        return 0;
    }
