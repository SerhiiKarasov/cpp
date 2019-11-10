#include <thread>
#include <iostream>
#include <mutex>

std::mutex m1, m2, m3; 
std::unique_lock<std::mutex> lock1(m1, std::defer_lock); 
std::unique_lock<std::mutex> lock3(m3, std::adopt_lock); 

std::mutex m;

int count = 0; 

int function()
{
    std::unique_lock<std::mutex> lock(m);
    count++;
}

int main()
{
    return 0;
}