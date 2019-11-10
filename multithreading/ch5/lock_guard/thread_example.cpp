#include <thread>
#include <iostream>
#include <mutex>

std::mutex globalMutex;
int counter = 0;

void worker()
{
    std::lock_guard<std::mutex> lock(globalMutex);
    if (counter == 1)
    {
        counter += 10;
    }
    else if (counter >= 10)
    {
        counter += 15;
    }
    else if (counter > 50)
    {
        return;
    }
    else
    {
        ++counter;
    }

    std::cout << std::this_thread::get_id() << ": " << counter << std::endl;
}
int main()
{
    std::cout << __func__ << ": " << counter << std::endl;

    std::thread t1(worker);
    std::thread t2(worker);

    t1.join();
    t2.join();

    std::cout << __func__ << ": " << counter << std::endl;
    return 0;
}