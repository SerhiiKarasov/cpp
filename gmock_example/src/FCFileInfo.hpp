
#ifndef SRC_FCFILEINFO_HPP_
#define SRC_FCFILEINFO_HPP_

/**
 * @file FCFileInfo.hpp
 *
 * @brief class to store info on files
 *
 * @ingroup filcomp
  *
 * @author Serhii Karasov
 * Contact: sergeyvkarasyov@gmail.com
 *
 */
#include "../include/FCFileInfoInterface.hpp"
#include <string>

class FCFileInfo : public FCFileInfoInterface
{
private:
    std::string filePath;

public:
    FCFileInfo(const std::string &mFilePath) : filePath{mFilePath} {}
    std::string getFilePath() override;
    virtual ~FCFileInfo() = default;
};
#endif // SRC_FCFILEINFO_HPP_
