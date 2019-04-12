#include <thread>
#include <iostream>
#include <mutex>
#include <thread>
#include <future>
#include <chrono>

using namespace std;
int countdown(int from, int to)
{
    for (int i = from; i != to; --i)
    {
        cout << i << endl;
        std::chrono::microseconds span(100);

        std::this_thread::sleep_for(span);
    }
    cout << "finished countdown " << endl;
    return from - to;
}

int main()
{
    packaged_task<int(int, int)> task(countdown);
    future<int> result = task.get_future();
    thread t(std::move(task), 10 , 0);

    int value = result.get();
    cout << "the countdown lasted for " << value << " microseconds" << endl;
    t.join();
    return 0;
}