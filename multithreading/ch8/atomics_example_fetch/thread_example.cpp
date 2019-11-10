#include <thread>
#include <iostream>
#include <mutex>
#include <thread>
#include <future>
#include <chrono>
#include <atomic>



std::atomic<long long> count;
void worker()
{
    count.fetch_add(1, std::memory_order_relaxed);
}

int main()
{
    std::thread t1(worker);
    std::thread t2(worker);
    std::thread t3(worker);
    std::thread t4(worker);
    std::thread t5(worker);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    std::cout << "Count value: " << count << std::endl;
    return 0;
}