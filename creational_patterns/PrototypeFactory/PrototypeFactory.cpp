//a prototype is a partially or fully initialized object that you copy and use
//remember to do a deep copy

#include <vector>
#include <iostream>
#include <string>
#include <memory>

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

struct EmployeeFactory
{
    //
    static Contact main, aux;

    static unique_ptr<Contact> new_hq_employee(string name, int suite)
    {
        return new_employee(name, suite, main);
    }
    static unique_ptr<Contact> new_back_office_employee(string name, int suite)
    {
        return new_employee(name, suite, aux);
    }
private:
    static unique_ptr<Contact> new_employee(string name, int suite, Contact &proto)
    {
        auto result = make_unique<Contact>(proto);
        result->name = name;
        result->work_address->suite = suite;
        return result;
    }
};
Contact EmployeeFactory::main{"", new Address{"123 East Dr", "London", 0}};
Contact EmployeeFactory::aux{"", new Address{"123 West Dr", "London", 0}};

int main()
{
    auto rodrigo = EmployeeFactory::new_hq_employee("rodrigo", 1);
    auto carlos = EmployeeFactory::new_back_office_employee("carlos", 2);

    std::cout << *rodrigo << *carlos << std::endl;
}