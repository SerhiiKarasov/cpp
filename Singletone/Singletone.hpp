#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
std::string::size_type sz; // alias of size_t

class SingletoneDatabase
{
    SingletoneDatabase()
    {
        std::cout << "Initializiing db" << std::endl;
        std::ifstream ifs("file.txt");
        std::string s, s2;
        while (std::getline(ifs, s))
        {
            getline(ifs, s2);
            int pop = std::stoi(s2, &sz);
            capitals[s] = pop;
        }
    }

    map<string, int> capitals;
    static SingletoneDatabase *instance;

public:
    SingletoneDatabase(SingletoneDatabase const &) = delete;
    void operator=(SingletoneDatabase const &) = delete;
    static SingletoneDatabase *get_instance()
    {
        //it is not thread safe
        if (!instance)
        {
            instance = new SingletoneDatabase;
        }
        return instance;
        //how to delete? there is no delete for static objects
    }
};
