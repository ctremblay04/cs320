#include "Gshare.h"

Gshare :: Gshare(int size) {
  this->mask = (1<<11)-1;
  this->history = new int[this->mask+1];
  for (int i = 0; i < this->mask+1; i++) {
    this->history[i] = 1;
  }
  this->gmask = (1<<size)-1;
}

Gshare :: ~Gshare() {
  delete[] this->history;
}

int Gshare :: predict(long long addr) {
  int curr = (this->mask&addr)^this->ghr;
  return this->history[curr]/2;
}

void Gshare :: train(long long addr, int actual, int prediction) {
  int curr = (this->mask&addr)^this->ghr;
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
  this->ghr = ((this->ghr<<1)&this->gmask)+actual;
}

