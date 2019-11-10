#include <iostream>
#include <chrono>
#include <thread>

void worker()
{
        std::this_thread::sleep_for(std::chrono::seconds(1));
}
using namespace std::literals::chrono_literals;

int main()
{
        std::thread t1(worker);
        std::thread t2(worker);

        std::cout << "t1 " << t1.get_id() << std::endl;
        std::cout << "t2 " << t2.get_id() << std::endl;

        std::swap(t1, t2);

        std::cout << "t1 " << t1.get_id() << std::endl;
        std::cout << "t2 " << t2.get_id() << std::endl;
        t1.join();
        t2.join();
}