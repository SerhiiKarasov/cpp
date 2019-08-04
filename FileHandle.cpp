#include <sys/stat.h> //open
#include <fcntl.h>    //open
#include <iostream>
#include <cstdio> // declaration of ::fileno
#include <string>
#include <memory>

namespace filehandle
{
void close_file(std::FILE *fp)
{
    std::cout << "closing" <<std::endl;
    std::fclose(fp);
}

using CFile = std::unique_ptr<std::FILE, decltype(&close_file)>;

auto MakeFileHandle(std::FILE *file)
{
    return CFile(file, close_file);
}
} // namespace filehandle

int main()
{
    auto myfile = filehandle::MakeFileHandle(std::fopen("file", "r"));
    std::cout << fileno(myfile.get()) << std::endl;
}