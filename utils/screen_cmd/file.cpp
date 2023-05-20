#include <iostream>
#include <fstream>
#include "screen.cpp"
#include <vector>
#include <string>
#include <math.h>
using namespace std;

void WriteFile(string path, string data) {
  ofstream file(path);
  file << data;
  file.close();
}
void RenderFile(LAYER* A, string path) {
  ofstream file(path);
  file << A->RenderGrey();
  file.close();
}

#if __INCLUDE_LEVEL__ == 0
int main() {
  int* rat = (int*)malloc(2 * sizeof(int));
  rat[0] = 1; rat[1] = 3;

  int height = 300, width = 300;
  PIXEL A(33, 4);
  vector<Pixel*> B;
  for (int i = 0; i < height;i++) {
    for (int j = 0;j < width;j++) {
      int* pos = (int*)malloc(2 * sizeof(int));
      pos[0] = i; pos[1] = j;
      PIXEL* B_ = (PIXEL*) new PIXEL(0, (int)(i * j * 0.001) % 94);
      Pixel* A_ = (Pixel*) new Pixel(pos, B_);
      B.push_back(A_);
    }
  }
  LAYER C(&A, rat, width, height);
  // cout << "ed";
  C.addPIXELS(B);
  // cout << C.Render();
  RenderFile(&C, "te.txt");

}
#else
#pragma once
#endif