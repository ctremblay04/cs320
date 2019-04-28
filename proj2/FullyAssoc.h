#ifndef FULLYASSOC_H
#define FULLYASSOC_H

#include "Cache.h"
#include "SetAssoc.h"
#include <iostream>

using namespace std;

class FullyAssoc : public Cache {
  public:
    FullyAssoc();
    ~FullyAssoc();
    virtual string to_string();
    static const int SIZE = 14; //16kb cache, 16kb addressed by 14 bits

  private:
    virtual void update(unsigned long long addr, string p);
    SetAssoc* cache = new SetAssoc(SIZE-LINE_BITS);
};
#endif
