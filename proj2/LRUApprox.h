#ifndef LRUAPPROX_H
#define LRUAPPROX_H

#include "Cache.h"
#include <iostream>

using namespace std;

class LRUApprox : public Cache {
  public:
    LRUApprox();
    ~LRUApprox();
    static const int SIZE = 14; //16kb cache, 16kb addressed by 14 bits

  private:
    struct Entry {
      int hot = 0;
      unsigned long long tag = 0;
    };
    int setSize;
    virtual int updateCache(unsigned long long addr, int inst);
    Entry* table;
};
#endif
