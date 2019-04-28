#include "Cache.h"

Cache :: Cache(void){}

Cache :: Cache(unsigned long long size) {
  int shift = size-LINE_BITS;
  this->indMask = ((1<<shift)-1)<<this->LINE_BITS;
  this->tagMask = (~((1<<shift)-1))<<this->LINE_BITS;
  this->shift = size;
}

void Cache :: update(unsigned long long addr, string p) {
  this->correct += this->updateCache(addr, p == "L");
  this->total++;
}

string Cache :: to_string() {
  return std::to_string(this->correct)+","+std::to_string(this->total)+";";
}
