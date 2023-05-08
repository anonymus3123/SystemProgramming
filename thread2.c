#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREAD 10

void *ThreadSafe(void *args)
{
    int *threadId = (int*)args;
    printf("Hello from the thread %d\n", *threadId);
}

int main(int args, char* argv[])
{
    pthread_t threads[NUM_THREAD];
    int threads_args[NUM_THREAD];

    printf("Not in thread.\n");

    for(int i = 0; i < NUM_THREAD; i++) //tworze 10 watkow.
    {
        pthread_create(&threads[i], NULL, ThreadSafe, (void*)&threads_args[i]);
        threads_args[i] = i;
    }

    for(int j = 0; j < NUM_THREAD; j++)
    {
        pthread_join(threads[j], NULL);
    }

    printf("After thread.\n");
    pthread_exit(NULL);

    return 0;
}   