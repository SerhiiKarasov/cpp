/**
 * @file FCFileInfo.cpp
 *
 * @brief a class to store info on files
 *
 * @ingroup filcomp
  *
 * @author Serhii Karasov
 * Contact: sergeyvkarasyov@gmail.com
 *
 */

#include "FCFileInfoMock.hpp"
#include "gtest/gtest.h"

using ::testing::AtLeast;
const std::string testFilePath = "/tmp/testfile.txt";


TEST(FCFileInfoMockTest, test_moc)
{
    FCFileInfoMock mFileInfoMock;
    // ASSERT_EQ(mFileInfoMock->getFilePath(), testFilePath);
    EXPECT_CALL(mFileInfoMock, getFilePath()).Times(AtLeast(0));
}
