#include "utils/header.h"
#include "./utils/Number.cpp"
#include "./utils/writeFile.cpp"
#include "./utils/PNG/Chunk.cpp"

template <typename T> void checkData(vector<int> z) {
  for (int i : z)  cout << (T)i << " ";
  cout << endl;
}

int main() {
  string path = "data/png/sample.png";
}