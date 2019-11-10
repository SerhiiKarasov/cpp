#include <thread>
#include <iostream>
#include <mutex>

std::mutex globalMutex;

void worker(int n) 
{
    globalMutex.lock();
    std::cout << "ATATATA" << n << std::endl;
    globalMutex.unlock();
} 
int main()
{
    
    std::thread t1(worker, 1);
    std::thread t2(worker, 2);
    
    t1.join();
    t2.join();
    return 0;
}