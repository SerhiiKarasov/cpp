#ifndef _PT_HEADER_H
#define _PT_HEADER_H

#include <stddef.h>
struct ptMemoryBlockHeader {
    const char *m_pFunction;
    const char *m_pFile;
    int m_LineNumber;
    size_t m_Size;
    struct ptMemoryBlockHeader *m_pPrev;
    struct ptMemoryBlockHeader *m_pNext;
};

#endif // _PT_HEADER_H