#include <pthread.h>
int pthread_rwlock_init(pthread_rwlock_t *rwlock, const pthread_rwlockattr_t *attr);
pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

//thread local storage
pthread_key_t global_var_key;
void *worker(void *arg)
{
    int *p = new int;
    *p = 1;
    pthread_setspecific(global_var_key, p);
    global_var_key++;
    pthread_setspecific(global_var_key, 0);
    delete p;
    pthread_exit(0);
}

int main(void)
{
    pthread_t threads[5];
    pthread_key_create(&global_var_key, 0);

    for (int i = 0; i < 5; ++i)
        pthread_create(&threads[i], 0, worker, 0);
    for (int i = 0; i < 5; ++i)
    {
        pthread_join(threads[i], 0);
    }
    return 0;
}