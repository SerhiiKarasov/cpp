#include <thread>

void worker(int n, std::string a) //untill that is copy no need to synchronize
{
    printf("Atata %s %d", a.c_str(), n);
} //no syncro is required as this is void

int main()
{
    std::string data = "halo";
    std::thread t(worker, 1, data);
    std::thread t1(std::move(t));//as t is finished, now need to wait for t1
    t1.join();
    return 0;
}