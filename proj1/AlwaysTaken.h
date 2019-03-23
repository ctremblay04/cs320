#ifndef ALWAYS_TAKEN_H
#define ALWAYS_TAKEN_H

#include "Predictor.h"

using namespace std;

class AlwaysTaken : public Predictor {
  public:
    AlwaysTaken();
    int predict(long long addr);
};

#endif
