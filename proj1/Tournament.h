#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include<math.h>
#include "Predictor.h"
#include "BimodalDoubleBit.h"
#include "Gshare.h"

class Tournament : public Predictor {
  public:
    Tournament();
    ~Tournament();
    int predict(long long addr);
  private:
    Gshare* gsh = new Gshare(11);
    BimodalDoubleBit* bim = new BimodalDoubleBit(11);
    int* history;
    int mask;
    void train(long long addr, int actual, int prediction);
};

#endif
