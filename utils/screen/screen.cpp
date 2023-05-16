#include <iostream>
#include <vector>
#include <cstdarg>
#include <cstdlib>
#include "./pixel.cpp"
#include "cmath"

#if __INCLUDE_LEVEL__  != 0
#pragma once
#endif

using namespace std;

struct Pixel {
  Pixel(int* pos, PIXEL* pixel) {
    this->pos = pos;
    this->pixel = pixel;
  }
  ~Pixel() {
    pixel->~PIXEL();
    free(this->pos);
  }
  int* pos;
  PIXEL* pixel;
};
class LAYER {
public:
  ~LAYER() { cout << defPix->updateProbs().render(); }
  LAYER(PIXEL* def, int width = 100, int height = 100, int* ratio = nullptr) {
    this->defPix = def; this->width = width; this->height = height; this->ratio = ratio;
    this->_screen = (Pixel***)malloc(height * sizeof(Pixel**));
    for (int i = 0; i < height;i++) this->_screen[i] = (Pixel**)calloc(width, sizeof(Pixel*));
  }
  void print() {
    for (int i = 0; i < height;i++) {
      string result = "";
      for (int j = 0; j < width; j++) {
        Pixel* pix = this->_screen[i][j];
        string pixel = !pix ? this->defPix->render() : this->_screen[i][j]->pixel->render();
        for (int k = 0; k < this->ratio[1];k++) result += pixel;
      }
      for (int k = 0; k < this->ratio[0];k++) cout << result << endl;
    }
  }

  void addPIXELS(int n, ...) {
    va_list ptr; va_start(ptr, n);
    for (int i = 0; i < n;i++) this->_addPixel(va_arg(ptr, Pixel*));
    va_end(ptr);
  }
  void addPIXELS(int n, Pixel** A) { for (int i = 0; i < n;i++) this->_addPixel(A[i]); }
  void addPIXELS(vector<Pixel*> A) {
    for (int i = 0; i < A.size();i++) {
      this->_addPixel(A.at(i));
    }
  }
  Pixel* findPixel(int i, int j) {
    for (int i = 0; i < PIXELS.size();i++) {
      Pixel* p = PIXELS.at(i);
      if (p->pos[0] == i && p->pos[1] == j) return p;
    }
    return nullptr;
  }
private:
  inline void _addPixel(Pixel* A) {
    if (A == nullptr) return;
    this->_screen[A->pos[0]][A->pos[1]] = (Pixel*)A;
    this->PIXELS.push_back(A);
  }
  int width, height, * ratio;
  vector<Pixel*> PIXELS;
  Pixel*** _screen;
  PIXEL* defPix;
};

#if __INCLUDE_LEVEL__ == 0
int main() {
  srand((unsigned)time(NULL));

  int* rat = (int*)malloc(2 * sizeof(int));
  rat[0] = 3; rat[1] = 5;

  int height = 10, width = 10;
  PIXEL A(33, 4);
  vector<Pixel*> B;
  for (int i = 0; i < height;i++) {
    for (int j = 0;j < width;j++) {
      int* pos = (int*)malloc(2 * sizeof(int));
      pos[0] = i; pos[1] = j;
      PIXEL* B_ = (PIXEL*) new PIXEL(30 + (i * j) % 7, (i * j) % 97);
      Pixel* A_ = (Pixel*) new Pixel(pos, B_);
      B.push_back(A_);
    }
  }
  LAYER C(&A, width, height, rat);
  // cout << "ed";
  C.addPIXELS(B);
  C.print();
}
#endif
