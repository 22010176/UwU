#include <iostream>
#include <vector>
#include <cstdarg>
#include <cstdlib>
#include "./pixel.cpp"
#pragma once

using namespace std;

struct Pixel { int* pos;  PIXEL* pixel; };
class LAYER {
public:
  ~LAYER() { cout << defPix->updateProbs().render(); }
  LAYER(PIXEL* def, int width = 100, int height = 100) {
    this->defPix = def;
    this->width = width;
    this->height = height;
  }
  void print() {
    for (int i = 0; i < PIXELS.size();i++) {
      PIXEL* A = this->PIXELS.at(i)->pixel;
      cout << A << endl;
      cout << A->getIntent() << endl;
    }
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
  PIXEL A(33, 4);
  vector<Pixel*> B;
  for (int i = 0; i < 100;i++) {
    int* pos = (int*)malloc(2 * sizeof(int));
    pos[0] = rand() & 100;
    pos[1] = rand() % 100;

    PIXEL* B_ = (PIXEL*)malloc(sizeof(PIXEL));


    Pixel* A_ = (Pixel*)malloc(sizeof(Pixel));
    A_->pos = pos;
    A_->pixel = B_;
    B.push_back(A_);
  }
  LAYER C(&A, 150, 20);
  C.addPIXELS(B);
  C.print();
}
#endif
