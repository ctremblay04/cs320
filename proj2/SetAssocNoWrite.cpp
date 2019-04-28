#include "SetAssocNoWrite.h"

SetAssocNoWrite :: SetAssocNoWrite(int setSize) : Cache(SIZE-setSize) {
  this->setSize = 1<<setSize;
  this-> numSets = 1<<(SIZE-LINE_BITS-setSize);
  this->table = new Entry*[this->numSets];
  for (int i = 0; i < numSets; i++) {
    this->table[i] = new Entry[this->setSize];
  }
}

SetAssocNoWrite :: ~SetAssocNoWrite() {
  for (int i = 0; i < this->numSets; i++) {
    delete[] this->table[i];
  }
  delete[] this->table;
}

int SetAssocNoWrite :: updateCache(unsigned long long addr, int inst) {
  unsigned long long ind = getInd(addr);
  unsigned long long tag = getTag(addr);
  int max = 0;
  int lru = 0;
  int match = 0;
  for (int i = 0; i < this->setSize; i++) {
    if (this->table[ind][i].tag == tag) { 
      match = 1;
      this->table[ind][i].counter = 0;
    }
    else {
      if (this->table[ind][i].counter > max) {
        max = this->table[ind][i].counter;
        lru = i;
      }
      this->table[ind][i].counter++;
    }
  }
  if (not match and inst) {
    this->table[ind][lru].tag = tag;
    this->table[ind][lru].counter = 0;
  }
  return match;
}
