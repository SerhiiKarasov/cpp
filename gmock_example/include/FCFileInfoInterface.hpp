
#ifndef SRC_FCFILEINFOINTERFACE_HPP_
#define SRC_FCFILEINFOINTERFACE_HPP_

/**
 * @file FCFileInfoInterface.hpp
 *
 * @brief an interface class to store info on files
 *
 * @ingroup filcomp
  *
 * @author Serhii Karasov
 * Contact: sergeyvkarasyov@gmail.com
 *
 */

#include <string>

class FCFileInfoInterface
{
public:
    virtual std::string getFilePath() = 0;
};
#endif // SRC_FCFILEINFOINTERFACE_HPP_
