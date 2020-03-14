#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
char array1[20];
char array2[20];
char array3[20];
char array4[20];
/*
/home/computer/Coding/cpp/memory_corruption/off-by-one/offbyone.cpp:12:29: warning: the value of the size argument in 'strncat' is too large, might lead to a
      buffer overflow [-Wstrncat-size]
    strncat(array3, array1, sizeof(array3));
                            ^~~~~~~~~~~~~~
/home/computer/Coding/cpp/memory_corruption/off-by-one/offbyone.cpp:12:29: note: change the argument to be the free space in the destination buffer minus the
      terminating null byte
    strncat(array3, array1, sizeof(array3));
                            ^~~~~~~~~~~~~~
                            sizeof(array3) - strlen(array3) - 1

*/

int main(int argc, char **argv)
{
    // strncat(array3, array1, sizeof(array3));
    // strncat(array3, array2, sizeof(array3));
    std::cout << sizeof(array3) << " - " <<  strlen(array3) << "- 1 =" << sizeof(array3) - strlen(array3) - 1<< std::endl;
    strncat(array3, array1, sizeof(array3) - strlen(array3) - 1);
    strncat(array3, array2, sizeof(array3) - strlen(array3) - 1);
    snprintf(array4, sizeof(array4), "%s", array3);
}
