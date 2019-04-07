#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>

using namespace std;

mutex values_mtx;
mutex cout_mtx;
vector<int> values;

int randGen(const int &min, const int &max)
{
    static thread_local mt19937 generator(hash<thread::id>()(this_thread::get_id()));
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

void threadFunc(int tid)
{
    cout_mtx.lock();
    cout << "Staring thread: " << tid << endl;
    cout_mtx.unlock();

    values_mtx.lock();
    int val = values[0];
    values_mtx.unlock();

    int rval = randGen(0, 10);
    val += rval;

    cout_mtx.lock();
    cout << "Thread " << tid << " adding " << rval << " . New value : " << val << endl;
    cout_mtx.unlock();

    values_mtx.lock();
    values.push_back(val);
    values_mtx.unlock();
}

int main()
{
    values.push_back(42);

    thread tr1(threadFunc, 1);
    thread tr2(threadFunc, 2);
    thread tr3(threadFunc, 3);
    thread tr4(threadFunc, 4);
    tr1.join();
    tr2.join();
    tr3.join();
    tr4.join();

    cout << "Input: " << values[0] << " Random values: " << values[1] << " " << values[2] << " " << values[3] << " " << values[4] << endl;
    return 1;
}