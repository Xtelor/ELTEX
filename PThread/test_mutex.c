#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

    long A = 0;
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    
    void * func(void * param)
    {
        long tmp;
        
        for(int i = 0; i < 1000000; i ++)
        {
            pthread_mutex_lock( &mutex );
            tmp = A;
            tmp ++;
            A = tmp;        
            pthread_mutex_unlock( &mutex );
        }
    }
    int main(void)
    {
        pthread_t tid[1000];
        
        for(int i = 1; i <= 1000; i ++)
        {
            pthread_mutex_lock( &mutex );
            pthread_create(&tid[i - 1], NULL, func, (void*)&i);
            pthread_mutex_unlock( &mutex );
        
        }
       
        for(int i = 0; i < 1000; i ++)
        {   
            pthread_join(tid[i], NULL);
        }
        printf("A = %ld\n", A);       
        return 0;
    }
