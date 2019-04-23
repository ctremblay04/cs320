#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include<math.h>
#include "Predictor.h"
#include<string>

using namespace std;

class Perceptron : public Predictor {
  public:
    Perceptron(int size);
    ~Perceptron();
    int getTheta();
    int predict(long long addr);
    void update(long long addr, int p);
  private:
    int size;
    int** perceptrons;
    int theta;
    int mask;
    int gmask;
    int ghr = 0;
    void train(long long addr, int actual, int prediction);
};

#endif
