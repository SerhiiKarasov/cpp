#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int APP_SIZE = 0x02000;
char *TARGET_LOC;
int MAX_ADDR = 0x0200;

void initialization()
{
    TARGET_LOC = (char *)malloc(MAX_ADDR);
    memset(TARGET_LOC, 0x66, MAX_ADDR);
}

void do_job(int count, int offset, char *source)
{
    memcpy(TARGET_LOC + offset, source, count);
}

int checking(int argc, char **argv)
{
    int k, RET = 0;
    if (argc == 4)
    {
        for (k = 1; k < 3; k++)
            if (atoi(argv[k]) > 0 && atoi(argv[k]) < (MAX_ADDR >> 2))
                RET = 1;
        if (atoi(argv[3]) > APP_SIZE)
            RET = 0;
    }
    return RET;
}

int main(int argc, char **argv)
{
    if (checking(argc, argv))
    {
        auto data = atoi(argv[1]);
        initialization(data);
        do_job(atoi(argv[1]), atoi(argv[2]), argv[3]);
        return 0;
    }
    return -1;
}
