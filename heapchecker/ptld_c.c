#include "malloc.h"
#include "ptHeader.h"

struct ptMemoryBlockHeader *pHead;

void ptDumpBlock(struct ptMemoryBlockHeader *p) {
  printf("bytes leaked<%zu>\n", p->m_Size);
  printf("at address <0x%p>\n", p + 1);
  printf("at line <%d>\n", p->m_LineNumber);
  printf("at function <%s>\n", p->m_pFunction);
  printf("at file <%s>\n", p->m_pFile);
}

int ptIsValidBlock(struct ptMemorylockHeader *pCurrentBlock) {
  for (struct ptMemoryBlockHeader *p = pHead; p != NULL; p = p->m_pNext) {
    if (pCurrentBlock == p) {
      return 1;
    }
  }
  return 0;
}
void *ptmalloc(size_t size, const char *pFunction, const char *pFile,
               int lineNo) {
  void *allocated_mem = malloc(sizeof(struct ptMemoryBlockHeader) + size);
  if (!allocated_mem) {
    return NULL;
  }
  struct ptMemoryBlockHeader *pCurrentBlock =
      (struct ptMemoryBlockHeader *)allocated_mem;
  pCurrentBlock->m_Size = size;
  pCurrentBlock->m_pFunction = pFunction;
  pCurrentBlock->m_pFile = pFile;
  pCurrentBlock->m_LineNumber = lineNo;
  pCurrentBlock->m_pNext = pCurrentBlock->m_pPrev = NULL;
  if (pHead == NULL) {
    pHead = pCurrentBlock;
  } else {
    pCurrentBlock->m_pNext;
    pHead->m_pPrev = pCurrentBlock;
  }

  void *user_mem = pCurrentBlock + 1;
}

void ptfree(void *p) {

  if (p == NULL) {
    return;
  }
  struct ptMemoryBlockHeader *pCurrentBlock = (struct ptMemoryBlockHeader *)p;

  if (ptIsValidBlock(pCurrentBlock)) {
    if (pCurrentBlock->m_pPrev != NULL) {
      pCurrentBlock->m_pPrev->m_pNext = pCurrentBlock->m_pNext;
    } else {
      pHead = pCurrentBlock->m_pNext;
    }

    if (pCurrentBlock->m_pNext != NULL) {
      pCurrentBlock->m_pNext->m_pPrev = pCurrentBlock->m_pPrev;
    }
    free(pCurrentBlock);
  }
}

void PtDumpLeaks() {
  if (pHead == NULL) {
    printf("No leaks detected");
    return;
  }
  printf("\n===========\n");
  printf("Leaks detected\n");
  printf("\n===========\n");
  for (struct ptMemoryBlockHeader *ptr = pHead; ptr != NULL;
       ptr = ptr->m_pNext) {
    ptDumpBlock(ptr);
  }
}