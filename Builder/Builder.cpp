// When piecewise object construction is complicated, Builder provides and API for doing that succintly.
// The Builder Pattern decouples the creation of the object from the object itself. 
// The main idea behind is that an object does not have to be responsible for its own creation.
// The correct and valid assembly of a complex object may be a complicated task in itself, so this task can be delegated to another class.

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
using namespace std;

//example without builder pattern
std::string make_html()
{
    //<p>hello</p>
    auto text = "hello";
    string output;
    output += "<p>";
    output += text;
    output += "</p>";
    return output;
}

struct HtmlElement
{
    string name;
    string text;
    vector<HtmlElement> elements;
    const size_t indent_size = 2;

    HtmlElement(){};
    HtmlElement(const string &name, const string &text)
        : name{name},
          text{text}
    {
    }
    string str(int indent = 0) const
    {
        ostringstream oss;
        string i(indent_size * indent, ' ');
        oss << i << "<" << name << ">" << std::endl;

        if (text.size() > 0)
        {
            oss << std::string(indent_size * (indent + 1), ' ') << text << std::endl;
        }

        for (const auto &e : elements)
        {
            oss << e.str(indent + 1);
        }
        oss << i << "</" << name << ">" << std::endl;
        return oss.str();
    }
};
//builder class
struct HtmlBuilder
{
    HtmlBuilder(string root_name)
    {
        root.name = root_name;
    }

    void add_child(string child_name, string child_text)
    {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
    }

    HtmlElement root;

    string str() const
    {
        return root.str();
    }
};

int main()
{
    std::cout << make_html() << std::endl;
    //what about <ul><li>hello</li></ul><li>world</li> ?
    //this is stupid

    //build is cool
    HtmlBuilder builder{"ul"};
    builder.add_child("li", "hello");
    builder.add_child("li", "world");
    builder.add_child("li", "hello");

    cout << builder.str() << endl;
}