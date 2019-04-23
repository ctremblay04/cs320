#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include "Predictor.h"
#include "Perceptron.h"

using namespace std;

int main(int argc, char *argv[]) {
  if(argc != 3){
    perror("Correct Usage: ./predictors <input_file.txt> <output_file.txt> \n");
    exit(EXIT_FAILURE);
  }
  unsigned long long addr;
  string behavior, line;
  vector<Predictor*> predictors;
  predictors.push_back(new Perceptron(30));

  ifstream infile(argv[1]);
  ofstream outfile(argv[2]);
  while(getline(infile, line)) {
    stringstream s(line);
    s >> std::hex >> addr >> behavior;
    for (vector<Predictor*>::iterator it = predictors.begin(); it != predictors.end(); ++it) {
      (*it)->update(addr, behavior);
    }
  }
  for (vector<Predictor*>::iterator it = predictors.begin(); it != predictors.end(); ++it) {
    outfile << (*it)->to_string() << endl;
  }
  for (vector<Predictor*>::iterator it = predictors.begin(); it != predictors.end(); ++it) {
    delete (*it);
  }
  infile.close();
  outfile.close();
  return 0;
}
