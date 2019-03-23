#include "Tournament.h"

Tournament :: Tournament() {
  this->mask = int(pow(2,11))-1;
  this->history = new int[this->mask+1];
  for (int i = 0; i < this->mask+1; i++) {
    this->history[i] = 2;
  }
}

Tournament :: ~Tournament() {
  delete this->gsh;
  delete this->bim;
  delete[] this->history;
}

int Tournament :: predict(long long addr) {
  if (this->history[this->mask&addr]/2) {
    return bim->predict(addr);
  }
  else {
    return gsh->predict(addr);
  }
}

void Tournament :: train(long long addr, int actual, int prediction) {
  int gshPredict = this->gsh->predict(addr);
  int bimPredict = this->bim->predict(addr);
  int curr = this->mask&addr;
  if (gshPredict != bimPredict) {
    if (gshPredict == actual && this->history[curr] > 0) {
      this->history[curr]--;
    }
    else if (bimPredict == actual && this->history[curr] < 3) {
      this->history[curr]++;
    }
  }
  this->gsh->update(addr, actual);
  this->bim->update(addr, actual);
}
