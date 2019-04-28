#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

#include "Cache.h"
#include "Direct.h"
#include "SetAssoc.h"
#include "FullyAssoc.h"
#include "LRUApprox.h"
#include "SetAssocNoWrite.h"
#include "SetAssocPrefetch.h"
#include "SetAssocPrefetchNoWrite.h"
#include "MultiTest.h"

using namespace std;

int main(int argc, char *argv[]) {
  if(argc != 3){
    perror("Correct Usage: ./cache-sim <input_file.txt> <output_file.txt> \n");
    exit(EXIT_FAILURE);
  }
  unsigned long long addr;
  string behavior, line;
  vector<Cache*> caches;
  int dirArr[4] = {10, 12, 14, 15};
  int setArr[4] = {1, 2, 3, 4}; //This is the log of the number of sets, so 1<<n is the number of sets
  caches.push_back(new MultiTest<Direct>(dirArr, 4));
  caches.push_back(new MultiTest<SetAssoc>(setArr, 4));
  caches.push_back(new FullyAssoc());
  caches.push_back(new LRUApprox());
  caches.push_back(new MultiTest<SetAssocNoWrite>(setArr, 4));
  caches.push_back(new MultiTest<SetAssocPrefetch>(setArr, 4));
  caches.push_back(new MultiTest<SetAssocPrefetchNoWrite>(setArr, 4));
  ifstream infile(argv[1]);
  ofstream outfile(argv[2]);
  while(getline(infile, line)) {
    stringstream s(line);
    s >> behavior >> std::hex >> addr;
    for (vector<Cache*>::iterator it = caches.begin(); it != caches.end(); ++it) {
      (*it)->update(addr, behavior);
    }
  }
  for (vector<Cache*>::iterator it = caches.begin(); it != caches.end(); ++it) {
    outfile << (*it)->to_string() << endl;
  }
  for (vector<Cache*>::iterator it = caches.begin(); it != caches.end(); ++it) {
    delete (*it);
  }
  infile.close();
  outfile.close();
  return 0;
}
