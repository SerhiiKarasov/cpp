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
#include "Singletone.hpp"
#include <gtest/gtest.h>

int main(int ac, char *av[])
{
    SingletoneDatabase::get();
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}

TEST(DATA, IsSingleTone)
{
    SingletoneDatabase::get();
}

TEST(SingletoneRecordFinderTest, SingleTonePopulation)
{
    //the problem is that we are testing on real data, not some dummy stuff
    SingletoneRecordFinder rf;
    vector<string> names{"Tokio"};
    int tp = rf.total_population(names);
    EXPECT_EQ(1, tp); //file should be copied to the same folder as binary
}
//how to test record finder without real db from the singletone?

TEST(SingletoneRecordFinderTest, DependantTotalPopulation)
{
    SingletoneRecordFinder rf;
    vector<string> names{"Tokio"};
    int tp = rf.total_population(names);
    EXPECT_EQ(1, tp); //file should be copied to the same folder as binary
}

TEST(SingletoneRecordFinderTest, Dummytest)
{
    DummyDatabase db{};
    ConfigurableRecordFinder rf{db};

    EXPECT_EQ(3, rf.total_population(vector<string>{"alpha", "beta"}));
}