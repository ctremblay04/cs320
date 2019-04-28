#ifndef DIRECT_H
#define DIRECT_H

#include "Cache.h"
#include <iostream>

using namespace std;

class Direct : public Cache {
  public:
    Direct(int size);
    ~Direct();

  private:
    virtual int updateCache(unsigned long long addr, int inst);
    unsigned long long* table;
};
#endif
