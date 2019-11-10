#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <future>

bool is_prime(int x)
{
    for(int i = 2; i < x; i++)
    {
        if (x%i == 0)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    int number  = 444444443;
    std::future<bool> fut = std::async(is_prime, number);
    std::cout << "checking please wait" << std::endl;
    
    std::chrono::microseconds span(100);
    while(fut.wait_for(span) == std::future_status::timeout)
    {
        std::cout << "." << std::flush;
    }

    bool x = fut.get();
    std::cout << "number is " << number << (x?" is ":" is not ") << " prime" << std::endl;
    return 0;
}