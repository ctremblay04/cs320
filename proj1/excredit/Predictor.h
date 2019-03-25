#ifndef PREDICTOR_H
#define PREDICTOR_H

#include <string>
#include <iostream>

using namespace std;

class Predictor {
  public:
    Predictor(void);
    virtual ~Predictor(){};
    virtual int predict(long long addr){ return 0; };
    virtual void update(long long addr, string p);
    virtual void update(long long addr, int p);
    virtual string to_string();
  private:
    virtual void train(long long addr, int actual, int prediction){};
  protected:
    int total = 0;
    int correct = 0;
};

#endif
