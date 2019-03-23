#include "BimodalDoubleBit.h"

BimodalDoubleBit :: BimodalDoubleBit(int size) {
  this->mask = int(pow(2,size))-1;
  this->history = new int[this->mask+1];
  for (int i = 0; i < this->mask+1; i++) {
    this->history[i] = 1;
  }
}

BimodalDoubleBit :: ~BimodalDoubleBit() {
  delete[] this->history;
}

int BimodalDoubleBit :: predict(long long addr) {
  return this->history[this->mask&addr]/2;
}

void BimodalDoubleBit :: train(long long addr, int actual, int prediction) {
  int curr = this->mask&addr;
  if (actual == 0) {
    if (this->history[curr] > 0) {
      this->history[curr]--;
    }
  }
  else {
    if (this->history[curr] < 3) {
      this->history[curr]++;
    }
  }
}

