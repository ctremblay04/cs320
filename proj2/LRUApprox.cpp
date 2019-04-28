#include "LRUApprox.h"

LRUApprox :: LRUApprox() : Cache(LINE_BITS) {
  this->setSize = 1<<(SIZE-LINE_BITS);
  this->table = new Entry[this->setSize+1];
}

LRUApprox :: ~LRUApprox() {
  delete[] this->table;
}

int LRUApprox :: updateCache(unsigned long long addr, int inst) {
  unsigned long long tag = getTag(addr);
  int index;
  int match = 0;
  for (int i = 0; i < this->setSize; i++) {
    if (this->table[i].tag == tag) { 
      match = 1;
      index = i;
      break;
    }
  }
  
  if (not match) {
    int tempInd = 0;
    int temp = this->setSize;
    while (temp) {
      temp >>= 1;
      if (not this->table[tempInd+temp].hot) {
        tempInd += temp;
      }
    }
    index = tempInd+1;
    if (this->table[tempInd].hot) { index = tempInd; }
    this->table[index].tag = tag;
  }
  
  int tempInd = 0;
  int temp = this->setSize;
  while (temp) {
    temp >>= 1;
    if (index > tempInd+temp) {
      tempInd += temp;
      this->table[tempInd].hot = 1;
    }
    else { this->table[tempInd+temp].hot = 0; }
  }
  this->table[index].hot = 0;
  return match;
}
