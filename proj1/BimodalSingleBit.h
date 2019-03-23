#ifndef BIMODAL_SINGLE_BIT_H
#define BIMODAL_SINGLE_BIT_H

#include<string>
#include<math.h>
#include "Predictor.h"

using namespace std;

class BimodalSingleBit : public Predictor {
  public:
    BimodalSingleBit(int size);
    ~BimodalSingleBit();
    int predict(long long addr);
  private:
    int* history;
    int mask;
    void train(long long addr, int actual, int prediction);
};

#endif
