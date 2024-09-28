#include "ptmain.h"

int main() {

  int *p = malloc(sizeof(int));
  PtDumpLeaks();
}