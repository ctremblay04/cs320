#include "Predictor.h"

Predictor :: Predictor(void){}

void Predictor :: update(long long addr, string p) {
  int actual;
  if (p == "T") { actual = 1; }
  else { actual = 0; }
  int prediction = this->predict(addr);
  this->train(addr, actual, prediction);
  if (actual == prediction) { this->correct++; }
  this->total++;  
}

void Predictor :: update(long long addr, int p) {
  int actual = p;
  int prediction = this->predict(addr);
  this->train(addr, actual, prediction);
  if (actual == prediction) { this->correct++; }
  this->total++;  
}

string Predictor :: to_string() {
  return std::to_string(this->correct)+","+std::to_string(this->total)+";";
}
