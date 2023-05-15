#include <iostream>
#include <vector>
#include "./pixel.cpp"
#include <cstdarg>

#pragma once

using namespace std;

struct Pixel { int* pos;  PIXEL* A; };
class LAYER {
public:
  LAYER(PIXEL* def, int width = 100, int height = 100) {
    this->defPix = def;
  }
  void print() {
    Pixel* p;
  }
  void addPIXELS(int n, ...) {
    va_list ptr;
    va_start(ptr, n);
    for (int i = 0; i < n;i++) {
      Pixel* A = va_arg(ptr, Pixel*);
      this->PIXELS.push_back(A);
    }
    va_end(ptr);
  };
  void addPIXELS(int n, Pixel** A) {
    for (int i = 0; i < n;i++) this->PIXELS.push_back(A[i]);
  };
  Pixel* findPixel(int i, int j) {
    for (int i = 0; i < PIXELS.size();i++) {
      Pixel* p = PIXELS.at(i);
      if (p->pos[0] == i && p->pos[1] == j) return p;
    }
    return nullptr;
  }
private:
  int width, height;
  vector<int> X, Y;
  vector<Pixel*> PIXELS;

  PIXEL* defPix;
};

#if __INCLUDE_LEVEL__ == 0
int main() {


}
#endif