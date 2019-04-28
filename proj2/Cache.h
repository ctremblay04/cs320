#ifndef CACHE_H
#define CACHE_H

#include <string>
#include <iostream>

using namespace std;

class Cache {
  public:
    Cache(void);
    Cache(unsigned long long size);
    virtual ~Cache(){};
    virtual int updateCache(unsigned long long addr, int inst){ return 0; };
    virtual void update(unsigned long long addr, string p);
    virtual string to_string();
    virtual unsigned long long getInd(unsigned long long addr)
      {return (addr&this->indMask)>>this->LINE_BITS;};
    virtual unsigned long long getTag(unsigned long long addr)
      {return (addr&this->tagMask)>>this->shift;};
    
    int shift;
    unsigned long long indMask;
    unsigned long long tagMask;
    
    static const int LINE_BITS = 5; //Number of bits to index the line, size of line is 2**LINE_BITS
  private:
    int total = 0;
    int correct = 0;
};

#endif
