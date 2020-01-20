#include "../src/FCFileInfo.hpp"
#include "gtest/gtest.h"

const std::string testFilePath = "/tmp/testfile.txt";


class FCFileInfoTest : public ::testing::Test
{
protected:
    FCFileInfoTest()
    {
        // set-up work for each test here.
    }

    ~FCFileInfoTest() override
    {
        // clean-up work that doesn't throw exceptions here.
    }
    void SetUp() override
    {
        std::cout << "setup" << std::endl;
    }

    void TearDown() override
    {
        std::cout << "teardown" << std::endl;
    }
};

TEST_F(FCFileInfoTest, check_factory_not_from_fs)
{

    FCFileInfo fileEntry{testFilePath};
    ASSERT_EQ(fileEntry.getFilePath(), testFilePath);
}