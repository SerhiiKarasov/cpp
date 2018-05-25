#include <string>
#include <vector>
#include <iostream>


enum class Size {Small, Medium, Large};
enum class Color {Red, Green, Blue};


struct Product
{
    std::string name;
    Size size;
    Color color;
};

struct ProductFilter
{
    typedef std::vector<Product*> Items;
    static Items by_color(Items items, Color color)
    {
        Items result;
        for (auto& i : items)
            if(i -> color == color)
                result.push_back(i);
        return result;
    }
    
    static Items by_size(Items items, Size size)
    {
        Items result;
        for (auto& i : items)
            if(i -> size == size)
                result.push_back(i);
        return result;
    }

    static Items by_size_and_color(Items items, Size size, Color color)
    {
        Items result;
        for (auto& i : items)
            if(i -> size == size && i -> color == color)
                result.push_back(i);
        return result;
    }
};

// a specification template

template<typename T> struct ISpecification
{
    virtual bool is_satisfied(T* item) = 0;
};

template <typename T> struct IFilter
{
    virtual std::vector<T*> filter(std::vector<T*> items, ISpecification<T>& spec) = 0;
};

struct BetterFilter : IFilter <Product>
{
        typedef std::vector<Product*> Items;

        virtual std::vector<Product*> filter(std::vector<Product*> items, ISpecification<Product>& spec)
        {
        Items result;
        for (auto& p: items)
            if(spec.is_satisfied(p))
                result.push_back(p);
        return result;
        }

};


struct ColorSpecification: ISpecification<Product>
{
    Color color;
    explicit ColorSpecification(const Color color)   
     : color{color}
    {

    }

    bool is_satisfied(Product* item) override{
        return item->color == color;
    }
};

template <typename T> struct AndSpecification: ISpecification<T>
{
    ISpecification <T>& first;
    ISpecification <T&> second;

    bool is_satisfied(T * item) override
    {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};


int main()
{
    Product apple{"Apple",Size::Small, Color::Green };
    Product tree{"Tree", Size::Large, Color::Green };
    Product house{"Tree", Size::Large, Color::Green };


    std::vector<Product *> all{&apple,&tree, &house};
    BetterFilter bf;
    ColorSpecification green(Color::Green);

    auto green_things = bf.filter(all, green);
    for (auto &x: green_things)
        {
            std::cout<< x->name << " is green" << std::endl;
        }


    return 0;

}