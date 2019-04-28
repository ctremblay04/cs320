#include "FullyAssoc.h"

FullyAssoc :: FullyAssoc() {}

FullyAssoc :: ~FullyAssoc() {
  delete this->cache;
}

void FullyAssoc :: update(unsigned long long addr, string p) {
  this->cache->update(addr, p);
}

string FullyAssoc :: to_string() {
  return this->cache->to_string();
}
