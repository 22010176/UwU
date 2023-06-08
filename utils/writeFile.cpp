#include <fstream>
#include "./Number.cpp"
#include "./String.cpp"
#pragma once
using namespace std;
void WriteFile(ifstream& _f1, ofstream& _f2, int space = 2, string div = " ") {
  char x; int i = 0;
  while (_f1.read(&x, 1)) {
    _f2 << fillStart("0", space, IntToBaseN(RealNum(x), HEX)) << div;
    if (++i % 8 == 0) _f2 << endl;
  }
}
int getFileSize(string path) {
  ifstream f(path, ios::binary | ios::out);
  f.seekg(0, ios::end);
  return f.tellg();
}