#include <iostream>
#include <vector>
#include <cstdarg>
#include <cstdlib>
#include "./pixel.cpp"

#pragma once

using namespace std;

struct Pixel {
  int* pos;  PIXEL* pixel;
};
class LAYER {
public:
  LAYER(PIXEL* def, int width = 100, int height = 100) {
    this->defPix = def;
    this->width = width;
    this->height = height;
  }
  void print() {
    cout << this->width << " " << this->height;
  }
  void addPIXELS(int n, ...) {
    va_list ptr;
    va_start(ptr, n);
    for (int i = 0; i < n;i++) {
      Pixel* A = va_arg(ptr, Pixel*);
      this->PIXELS.push_back(A);
    }
    va_end(ptr);
  }
  void addPIXELS(int n, Pixel** A) {
    for (int i = 0; i < n;i++) this->PIXELS.push_back(A[i]);
  }
  void addPIXELS(vector<Pixel*> A) {
    cout << 33;
    for (int i = 0; i < A.size();i++) this->PIXELS.push_back(A.at(i));
  }
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
  srand((unsigned)time(NULL));
  PIXEL A;
  vector<Pixel*> B;
  for (int i = 0; i < 100;i++) {
    Pixel* D;
    PIXEL d(30 + i % 7, i % 93);
    int* vec = (int*)malloc(2 * sizeof(int));
    vec[0] = rand() % 100;
    vec[1] = rand() % 100;
    D->pixel = &d;
    cout << 333;
    D->pos = vec;
    B.push_back(D);
  }
  for (int i = 0; i < B.size();i++) {

  }
  LAYER C(&A);
  C.addPIXELS(B);
  C.print();
}
#endif