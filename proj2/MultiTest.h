#ifndef MULTI_TEST_H
#define MULTI_TEST_H

#include<string>
#include<math.h>
#include "Cache.h"

using namespace std;

template <typename T>
class MultiTest : public Cache {
  public:
    MultiTest(int* options, int size) {
      for (int i = 0; i < size; ++i) {
        this->tests.push_back(new T(options[i]));
      }
    }
    ~MultiTest() {
      for (typename vector<T*>::iterator it = this->tests.begin(); it != this->tests.end(); it++) {
        delete (*it);
      }
    }
    void update(unsigned long long addr, string p) {
      for (typename vector<T*>::iterator it = this->tests.begin(); it != this->tests.end(); it++) {
        (*it)->update(addr, p);
      }
    }
    string to_string() {
      string ret = "";
      for (typename vector<T*>::iterator it = this->tests.begin(); it != this->tests.end(); it++) {
        if (it != this->tests.begin()) { ret += ' '; }
        ret += (*it)->to_string();
      }
      return ret;
    }
  private:
    vector<T*> tests;
};

#endif
