#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread()
{
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [] { return ready; });
    std::cout << "Worker thread is processing data" << std::endl;
    data += "after processing.";
    processed = true;
    std::cout << "Worker thread signals data processing completed" << std::endl;
    lk.unlock();
    cv.notify_one();
}

int main()
{
    std::thread worker(worker_thread);
    data = "Example data";
    {
        std::lock_guard<std::mutex> lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing" << std::endl;
    }
    cv.notify_one();
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [] { return processed; });
    }
    std::cout << "Back in main(), data = " << data << '\n';
    worker.join();
    return 0;
}