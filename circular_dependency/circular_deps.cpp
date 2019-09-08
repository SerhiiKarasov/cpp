#include <memory>

struct House
{
    std::weak_ptr<House> neighbour;
};


int main()
{
    std::shared_ptr<House> house1 = std::make_shared<House>();
    std::shared_ptr<House> house2 = std::make_shared<House>();;
    house1->neighbour = house2;
    house2->neighbour = house1;
}