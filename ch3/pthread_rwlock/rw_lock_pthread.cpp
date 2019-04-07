#include <pthread.h> 
int pthread_rwlock_init(pthread_rwlock_t* rwlock, const pthread_rwlockattr_t* attr); 
pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER; 
