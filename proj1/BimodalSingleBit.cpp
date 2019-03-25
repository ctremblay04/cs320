#include "BimodalSingleBit.h"

BimodalSingleBit :: BimodalSingleBit(int size) {
  this->mask = (1<<size)-1;
  this->history = new int[this->mask+1];
  for (int i = 0; i < this->mask+1; ++i) {
    this->history[i] = 0;
  }
}

BimodalSingleBit :: ~BimodalSingleBit() {
  delete[] this->history;
}

int BimodalSingleBit :: predict(long long addr) {
  return this->history[this->mask&addr];
}

void BimodalSingleBit :: train(long long addr, int actual, int prediction) {
  this->history[this->mask&addr] = actual;
}

