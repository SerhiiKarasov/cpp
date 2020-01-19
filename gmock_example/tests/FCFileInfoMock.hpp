
#ifndef TEST_FCFILEINFOMOCK_HPP_
#define TEST_FCFILEINFOMOCK_HPP_

/**
 * @file FCFileInfoMock.hpp
 *
 * @brief mock class to store info on files
 *
 * @ingroup filcomp
  *
 * @author Serhii Karasov
 * Contact: sergeyvkarasyov@gmail.com
 *
 */
#include "gmock/gmock.h"

#include "../include/FCFileInfoInterface.hpp"
#include <string>

class FCFileInfoMock : public FCFileInfoInterface
{
public:
    // MOCK_METHOD(std::string, getFilePath, (), (override));
    MOCK_METHOD0(getFilePath, std::string());
};
#endif // TEST_FCFILEINFOMOCK_HPP_
