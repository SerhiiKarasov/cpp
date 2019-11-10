
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <functional>
using namespace std;
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

//single function for storing an object to archive or retreaving object from archive

struct Address
{
    string street;
    string city;
    int suite;

    friend std::ostream &operator<<(ostream &os, const Address &obj)
    {
        return os << "street: " << obj.street << " city " << obj.city << " suite: " << obj.suite << endl;
    }

private:
    friend class boost::serialization::access;
    template <class Ar>
    void serialize(Ar &ar, const unsigned int version)
    {
        ar &street;
        ar &city;
        ar &suite;
    }
};

struct Contact
{
    string name;
    Address *work_address;

    friend std::ostream &operator<<(ostream &os, const Contact &obj)
    {
        return os << "name: " << obj.name << " work_address " << obj.work_address << endl;
    }

private:
    friend class boost::serialization::access;
    template <class Ar>
    void serialize(Ar &ar, const unsigned int version)
    {
        ar &name;
        ar &work_address;
    }
};

int main()
{
    Contact john;
    john.name = "John Doe";
    john.work_address = new Address{"Downing Str. 62", "London", 102};

    //we need a function that makes a deep copy

    auto clone = [](Contact c) {
        //serialization to text, need to use another archive for bin serialization e.g.
        // in order to show as text
        ostringstream oss;
        boost::archive::text_oarchive oa(oss);
        oa << c;
        string s = oss.str();
        cout << s << endl;

        Contact result;
        istringstream iss(s);
        boost::archive::text_iarchive ia(iss);
        ia >> result;
        return result;
    };

    Contact jane = clone(john);
    jane.name = "Jane";
    jane.work_address->street = "123b west east";

    cout << john << jane << endl;
}