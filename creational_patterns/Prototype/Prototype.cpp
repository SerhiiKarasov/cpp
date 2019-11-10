//a prototype is a partially or fully initialized object that you copy and use
//remember to do a deep copy

#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Address
{
    string street;
    string city;
    int suite;

    friend std::ostream &operator<<(ostream &os, const Address &obj)
    {
        return os << "street: " << obj.street << " city " << obj.city << " suite: " << obj.suite << endl;
    }
};

struct Contact
{
    string name;
    Address *work_address;

    ~Contact()
    {
        delete work_address;
    }
    friend std::ostream &operator<<(ostream &os, const Contact &obj)
    {
        return os << "name: " << obj.name << " work_address " << *obj.work_address << endl;
    }

    Contact(const Contact &other)
        : name{other.name}, work_address(new Address{*other.work_address})
    {
    }

    Contact(const string &name, Address *const work_address)
        : name{name}, work_address(new Address{*work_address})
    {
    }
};

int main()
{
    //bad impl example
    Address *addr = new Address{"123 str. Ch", "Cambridge"}; //prototype
    Contact John{"John Doe", addr};
    John.work_address->suite = 1;
    Contact Tony{"Tony Mony Dony", addr};
    Tony.work_address->suite = 100;

    Contact Jill{Tony};
    Jill.work_address->suite = 19000;
    std::cout << John << std::endl;
    std::cout << Tony << std::endl;
    std::cout << Jill << std::endl;

    // this is a prototype
    // a partially initialized object
    // copy constructor was used, we are leaking here
    Contact employee{"", new Address{"123 Eastr Dr", "London", 0}};
    Contact john{employee};
    john.name = "john";
    john.work_address->suite = 1;

    Contact jane{employee};
    jane.name = "jane";
    jane.work_address->suite = 2;

    Contact jill{employee};
    jill.name = "jill";
    jill.work_address->suite = 3;

    std::cout << john << std::endl;
    std::cout << jane << std::endl;
    std::cout << jill << std::endl;
}