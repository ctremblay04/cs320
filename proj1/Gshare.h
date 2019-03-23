#ifndef GSHARE
#define GSHARE

#include<math.h>
#include "Predictor.h"

class Gshare : public Predictor {
  public:
    Gshare(int size);
    ~Gshare();
    int predict(long long addr);
  private:
    int* history;
    int mask;
    int gmask;
    int ghr = 0;
    void train(long long addr, int actual, int prediction);
};

#endif
