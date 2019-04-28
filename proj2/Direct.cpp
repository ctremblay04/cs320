#include "Direct.h"

Direct :: Direct(int size) : Cache(size) {
  int shift = size-LINE_BITS;
  this->table = new unsigned long long[1<<shift];
  for (int i = 0; i < 1<<shift; i++) {
    this->table[i] = 0;
  }
}

Direct :: ~Direct() {
  delete[] this->table;
}

int Direct :: updateCache(unsigned long long addr, int inst) {
  int ret = this->table[this->getInd(addr)] == this->getTag(addr);
  this->table[this->getInd(addr)] = this->getTag(addr);
  return ret;
}
