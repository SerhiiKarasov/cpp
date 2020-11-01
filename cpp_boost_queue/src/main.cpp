#include "consumers.hpp"
#include "producers.hpp"
#include <boost/thread/thread.hpp>
#include <boost/lockfree/queue.hpp>
#include <iostream>
#include <boost/atomic.hpp>

boost::lockfree::queue<int> queue(128);

void producer(void)
{
    for (int i = 0; i != iterations; ++i) {
        int value = ++producer_count;
        while (!queue.push(value))
            ;
    }
}

void consumer(void)
{
    int value;
    while (!done) {
        while (queue.pop(value))
            ++consumer_count;
    }

    while (queue.pop(value))
        ++consumer_count;
}

int main(int argc, char* argv[])
{
    using namespace std;
    cout << "boost::lockfree::queue is ";
    if (!queue.is_lock_free())
        cout << "not ";
    cout << "lockfree" << endl;

    boost::thread_group producer_threads, consumer_threads;

    for (int i = 0; i != producer_thread_count; ++i)
        producer_threads.create_thread(producer);

    for (int i = 0; i != consumer_thread_count; ++i)
        consumer_threads.create_thread(consumer);

    producer_threads.join_all();
    done = true;

    consumer_threads.join_all();

    cout << "produced " << producer_count << " objects." << endl;
    cout << "consumed " << consumer_count << " objects." << endl;
}
