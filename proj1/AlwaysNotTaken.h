#ifndef ALWAYS_NOT_TAKEN_H
#define ALWAYS_NOT_TAKEN_H

#include "Predictor.h"

using namespace std;

class AlwaysNotTaken : public Predictor {
  public:
    AlwaysNotTaken();
    int predict(long long addr);
};

#endif
