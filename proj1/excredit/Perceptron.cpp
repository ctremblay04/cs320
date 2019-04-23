#include "Perceptron.h"

Perceptron :: Perceptron(int size) {
  this->size = size;
  this->mask = (1<<20)-1;
  this->perceptrons = new int*[this->mask+1];
  this->gmask = (1<<size)-1;
  this->theta = int(1.93*size+14);
  for (int i = 0; i < this->mask+1; i++) {
    this->perceptrons[i] = new int[size+1];
    for (int j = 0; j < size+1; j++) {
      this->perceptrons[i][j] = 0;
    }
  }
}

Perceptron :: ~Perceptron() {
  for (int i = 0; i < this->mask+1; i++) {
    delete[] this->perceptrons[i];
  }
  delete[] this->perceptrons;
}

int Perceptron :: getTheta() {
  return this->theta;
}

void Perceptron :: update(long long addr, int p) {
  int prediction = this->predict(addr);
  this->train(addr, p, prediction);
  if (p == (prediction >= 0)) { this->correct++; }
  this->total++;
}

int Perceptron :: predict(long long addr) {
  int* curr = this->perceptrons[addr&this->mask];
  int ret = curr[0]; //bias weight is always one
  for (int i = 0; i < this->size; i++) {
    int t = ((this->ghr&(1<<i))>>i) ? 1 : -1;
    ret += t*curr[i+1]; //curr[0] is the bias so index plus 1
  }
  return ret;
}

void Perceptron :: train(long long addr, int actual, int prediction) {
  int* curr = this->perceptrons[addr&this->mask];
  if ((prediction >= 0) != actual || abs(prediction) <= this->theta) {
    int t = actual ? 1 : -1;
    curr[0] += t;
    for (int i = 0; i < this->size; i++) {
      int x = ((this->ghr&(1<<i))>>i) ? 1 : -1;
      curr[i+1] += x*t;
    }
  }
  this->ghr = ((this->ghr<<1)&this->gmask)+((prediction >= 0) == actual);
}


