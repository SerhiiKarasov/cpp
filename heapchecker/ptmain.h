#ifndef _PT_MAIN_H
#define _PT_MAIN_H

#include <stddef.h>

void * ptmalloc(size_t size, const char *pFunction, const char *pFile,
               int lineNo);
void ptfree(void *p);

void PtDumpLeaks();

#define malloc(size) ptmalloc(size, __PRETTY_FUNCTION__, __FILE__, __LINE__)
#define free ptfree
#endif // _PT_MAIN_H