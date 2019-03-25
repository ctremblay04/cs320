#include "Predictor.h"

Predictor :: Predictor(void){}

void Predictor :: update(long long addr, string p) {
  this->update(addr, p == "T" ? 1 : 0); 
}

void Predictor :: update(long long addr, int p) {
  int prediction = this->predict(addr);
  this->train(addr, p, prediction);
  if (p == prediction) { this->correct++; }
  this->total++;  
}

string Predictor :: to_string() {
  return std::to_string(this->correct)+","+std::to_string(this->total)+";";
}
