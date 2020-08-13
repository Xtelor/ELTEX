#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t mutex[5] = PTHREAD_MUTEX_INITIALIZER;
int store[5];
int i;



void *loader()
{
    int i = 0;
    int delivery = 500;
    while (1)
    {
        i = rand() % 5;
        if (pthread_mutex_trylock(&mutex[i]) == 0)
        {
            store[i] += delivery;
            printf("Loader delivered %d product to store #%d\n", delivery, i + 1);
            printf("%d products in store #%d\n", store[i], i + 1);
            pthread_mutex_unlock(&mutex[i]);
        }
        sleep(1);
    }
}

void *customer(int a)
{
    int i = 0;
    int demand = 10000 + ((rand() % 400 + 1) - 200);
    while (demand != 0)
    {
        i = rand() % 5;
        if (pthread_mutex_trylock(&mutex[i]) == 0) 
        {
            if (store[i] != 0 && demand > store[i]) 
            {
                
                printf("Customer #%d in store #%d and buy %d product\n", a + 1, i + 1, store[i]);
                demand -= store[i];
                store[i] = 0;
                pthread_mutex_unlock(&mutex[i]);
            }
            else if (store[i] != 0 && demand <= store[i]) 
            {
                store[i] -= demand;
                demand = 0;
                pthread_mutex_unlock(&mutex[i]);
                printf("Customer #%d in store #%d and buy his last product\n", a + 1, i + 1);
            }
            else if (store[i] == 0) 
            {
                printf("Store #%d is empty!\n", i + 1);
                pthread_mutex_unlock(&mutex[i]);
            }
        }
        else
        {
            printf("Store #%d is closed!\n", i + 1);
        }
        printf("Customer #%d's demand = %d\n", a + 1, demand);
        sleep(2);
        if (demand == 0)
    {
        printf("Customer #%d's demand satisfied.\n", a + 1);
        sleep(2);
        demand = 10000 + ((rand() % 400 + 1) - 200);
        
    }
    }  
}

int main()
{
    pthread_t customer_tid[3];
    pthread_t loader_tid;
    pthread_mutex_init(&mutex[i], NULL);
  
    
    for (int j = 0; j < 5; j++)
    {
        store[i] = 500 + ((rand() % 100 + 1) - 50);
    }
    
    pthread_create(&loader_tid, NULL, loader, NULL);
    
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&customer_tid[i], NULL, (void *)customer, (int *)i);
    }
    
    for (int i = 0; i < 3; i++)
    {
        pthread_join(customer_tid[i], NULL);
    }
    
    pthread_join(loader_tid, NULL);
   
    return 0;
}
