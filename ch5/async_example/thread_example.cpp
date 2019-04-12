#include <thread>
#include <iostream>
#include <mutex>
#include <thread>
#include <future>
#include <chrono>
using namespace std;


bool is_prime(int x)
{
    cout << "Calculating prime..." << endl;
    for (int i = 2; i < x; ++i)
    {
        if (x % i ==0)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    future <bool> pFuture = std::async(is_prime, 343321);
    cout << "checking whether 34321 is a prime number" << endl;

    bool result = pFuture.get();
    if(result)
    {
        cout << "Prime found " << endl;
    }else
    {
        cout << "Prime is found " << endl;
    }
    return 0;
}