#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include "Predictor.h"
#include "AlwaysTaken.h"
#include "AlwaysNotTaken.h"
#include "BimodalSingleBit.h"
#include "BimodalDoubleBit.h"
#include "MultiTest.h"
#include "Gshare.h"
#include "Tournament.h"

using namespace std;

int main(int argc, char *argv[]) {
  if(argc != 3){
    perror("Correct Usage: ./predictors <input_file.txt> <output_file.txt> \n");
    exit(EXIT_FAILURE);
  }
  unsigned long long addr;
  string behavior, line;
  vector<Predictor*> predictors;
  predictors.push_back(new AlwaysTaken());
  predictors.push_back(new AlwaysNotTaken());
  int bimOpts[7] = {4,5,7,8,9,10,11};
  int gOpts[9] = {3,4,5,6,7,8,9,10,11};
  predictors.push_back(new MultiTest<BimodalSingleBit>(bimOpts, 7));
  predictors.push_back(new MultiTest<BimodalDoubleBit>(bimOpts, 7));
  predictors.push_back(new MultiTest<Gshare>(gOpts, 9));
  predictors.push_back(new Tournament());
  
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
