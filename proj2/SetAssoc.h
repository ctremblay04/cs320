#ifndef SETASSOC_H
#define SETASSOC_H

#include "Cache.h"
#include <iostream>

using namespace std;

class SetAssoc : public Cache {
  public:
    SetAssoc(int setSize);
    ~SetAssoc();
    static const int SIZE = 14; //16kb cache, 16kb addressed by 14 bits

  private:
    struct Entry {
      int counter = 0;
      unsigned long long tag = 0;
    };
    int numSets;
    int setSize;
    virtual int updateCache(unsigned long long addr, int inst);
    Entry** table;
};
#endif
