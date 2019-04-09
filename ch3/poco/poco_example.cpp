#include "Poco/Thread.h" 
#include "Poco/Runnable.h" 
#include "Poco/ThreadPool.h" 
#include <iostream> 

class HelloRunnable: public Poco::Runnable { 
    virtual void run() { 
        std::cout << "Hello, world!" << std::endl; 
    } 
}; 

class HelloRunnable1: public Poco::Runnable { 
    virtual void run() { 
        std::cout << "Hello, world!" << std::endl; 
    } 
}; 


int main(int argc, char** argv) { 
    HelloRunnable runnable; 
    Poco::Thread thread; 
    thread.start(runnable); 
    thread.join(); 

    HelloRunnable1 runnable1; 

    Poco::ThreadPool::defaultPool().start(runnable1); 
    Poco::ThreadPool::defaultPool().joinAll(); 
    return 0; 
} 