#include <iostream>
#include <string>
#include <sstream>

std::string get_cpu_name()
{
    unsigned int maxBasicCPUID;
    char vendorString[13];
    uint32_t *str = (uint32_t *)vendorString;
    asm("cpuid"
        : "=a"(maxBasicCPUID), "=b"(str[0]), "=d"(str[1]), "=c"(str[2])
        : "a"(0));
    vendorString[12] = 0;
    printf("maxBasicCPUID = %#x, vendorString = %s\n", maxBasicCPUID, vendorString);
    return vendorString;
}

int main()
{
    std::cout << get_cpu_name() << std::endl;
}