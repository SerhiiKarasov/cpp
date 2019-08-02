#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
std::string::size_type sz; // alias of size_t

//Singletone impl:
// private constructor
// delete copy constr, copy assign
// static function that return static instance

class Database
{
public:
    virtual int get_population(const std::string &name) = 0;
};

class SingletoneDatabase : public Database
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
    // static SingletoneDatabase *instance;

public:
    int get_population(const std::string &name) override
    {
        return capitals[name];
    }
    static SingletoneDatabase &get()
    {
        static SingletoneDatabase instance;
        return instance;
    }
    SingletoneDatabase(SingletoneDatabase const &) = delete;
    void operator=(SingletoneDatabase const &) = delete;
    // static SingletoneDatabase *get_instance()
    // {
    //     //it is not thread safe
    //     if (!instance)
    //     {
    //         instance = new SingletoneDatabase;
    //     }
    //     return instance;
    //     //how to delete? there is no delete for static objects
    // }
};

class DummyDatabase : public Database
{
    map<string, int> capitals;

public:
    DummyDatabase()
    {
        capitals["alpha"] = 1;
        capitals["beta"] = 2;
    }
    int get_population(const std::string &name) override
    {
        return capitals[name];
    }
};

struct SingletoneRecordFinder
{
    int total_population(vector<string> names)
    {
        int result = 0;
        for (auto &name : names)
        {
            result += SingletoneDatabase::get().get_population(name);
        }
        return result;
    }
};
struct ConfigurableRecordFinder
{
    explicit ConfigurableRecordFinder(Database &db)
        : db{db}
    {
    }
    Database &db;
    
    int total_population(vector<string> names)
    {
        int result = 0;
        for (auto &name : names)
        {
            result += db.get_population(name);
        }
        return result;
    }
};
