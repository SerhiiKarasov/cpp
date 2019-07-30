// when piecewise object construction is complicated, Builder provides and API for doing that succintly.
// FluentBuilder makes possible to add chaining for calls, i.e. make code more readable.
// For that we need function to return changed object

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
using namespace std;
struct Tag
{
    string name;
    string text;
    vector<Tag> children;
    vector<pair<string, string>> attributes;

    friend ostream &operator<<(ostream &os, const Tag &tag)
    {
        os << "<" << tag.name;
        for (const auto &att : tag.attributes)
        {
            os << " " << att.first << "=\"" << att.second << "\"";
        }
        if (tag.children.size() == 0 && tag.text.length() == 0)
        {
            os << "/>" << endl;
        }
        else
        {
            os << ">" << endl;
            if (tag.text.length())
            {
                os << tag.text << endl;
            }

            for (const auto &child : tag.children)
            {
                os << child;
            }
            os << "</" << tag.name << ">" << endl;
        }
        return os;
    }
    //no initializing of base class, we would use it only for p or img
protected:
    Tag(const string &name, const string &text)
        : name{name},
          text{text}
    {
    }
    Tag(const string &name, vector<Tag> children)
        : name{name},
          children{children}
    {
    }
};

struct P : Tag
{
    explicit P(const string &text)
        : Tag("p", text)
    {
    }
    explicit P(initializer_list<Tag> children)
        : Tag("p", children)
    {
    }
};

struct IMG : Tag
{
    explicit IMG(const string &url) : Tag("img", "")
    {
        attributes.emplace_back(make_pair("src", url));
    }
};

int main()
{

    cout << P{
                IMG{"http://a.com/b.png"},
                P{"Hi"}
            }
         << endl;
}