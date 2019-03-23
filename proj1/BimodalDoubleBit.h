#ifndef BIMODAL_DOUBLE_BIT_H
#define BIMODAL_DOUBLE_BIT_H

#include<math.h>
#include "Predictor.h"

class BimodalDoubleBit : public Predictor {
  public:
    BimodalDoubleBit(int size);
    ~BimodalDoubleBit();
    int predict(long long addr);
  private:
    int* history;
    int mask;
    void train(long long addr, int actual, int prediction);
};

#endif
