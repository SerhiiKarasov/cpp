#include <pthread.h>
#include <stdlib.h>
#include <cstdio>
#define NUM_THREADS

using namespace std;

void * worker(void * arg)
{
    int value = *((int*) g);
    printf("Worker");
    return 0;
}

static pthread_mutex_t func_mutex = PTHREAD_MUTEX_INITIALIZER;


void func()
{
    pthread_mutex_lock(&func_mutex);
    printf("func");
    pthread_mutex_unlock(&func_mutex);
}


int main(int argc, char ** argv)
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int result_code;


    for (unsigned int i =0; i < NUM_THREADS; ++i)
    {
        thread_args[i]=i;
        result_code = pthread_create(&threads[i], 0, worker,  (void*) &thread_args[i]);
    }

    for( int i =0; i < NUM_THREADS; ++i)
    {
        result_code = pthread_join(threads[i], 0);
    }

    exit(0);
}