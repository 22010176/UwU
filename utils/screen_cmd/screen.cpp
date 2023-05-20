#include <iostream>
#include <vector>
#include <cstdarg>
#include <cstdlib>
#include "./pixel.cpp"

#define SIZE 1000
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
  int* pos; PIXEL* pixel;
};
class LAYER {
public:
  static LAYER* CreateLayer(int height, int width) {
    int* rat = (int*)malloc(2 * sizeof(int));
    rat[0] = 1; rat[1] = 2;
    return (LAYER*)new LAYER((PIXEL*)new PIXEL(), rat, width, height);
  }
  ~LAYER() { cout << defPix->updateProbs().render(); }
  LAYER(PIXEL* def, int* ratio, int width = 100, int height = 100) {
    this->defPix = def; this->width = width; this->height = height; this->ratio = ratio;
    this->_screen = (Pixel***)malloc(height * sizeof(Pixel**));
    for (int i = 0; i < height;i++) this->_screen[i] = (Pixel**)calloc(width, sizeof(Pixel*));
  }
  string RenderGrey() {
    if (getChange(1) == 0) return this->_outGrey;
    this->trackChange(0, 1);
    this->_outGrey = "";
    for (int i = 0; i < height;i++) {
      string result_ = "";
      for (int j = 0; j < width; j++) {
        Pixel* pix = this->_screen[i][j];
        char pixel = GREYSCALE[(!pix ? this->defPix : this->_screen[i][j]->pixel)->getIntent()];
        for (int k = 0; k < this->ratio[1];k++) result_ += pixel;
      }
      for (int k = 0; k < this->ratio[0];k++) this->_outGrey += result_ + "\n";
    }
    return this->_outGrey;
  }
  string Render() {
    if (getChange(0) == 0) return this->_out;
    this->trackChange(0, 0);
    this->_out = "";
    for (int i = 0; i < height;i++) {
      string result_ = "";
      for (int j = 0; j < width; j++) {
        Pixel* pix = this->_screen[i][j];
        string pixel = (!pix ? this->defPix : this->_screen[i][j]->pixel)->render();
        for (int k = 0; k < this->ratio[1];k++) result_ += pixel;
      }
      for (int k = 0; k < this->ratio[0];k++) this->_out += result_ + "\n";
    }
    return this->_out;
  }
  void print() { cout << this->Render(); }
  void addPIXELS(int n, ...) {
    va_list ptr; va_start(ptr, n);
    for (int i = 0; i < n;i++) this->_addPixel(va_arg(ptr, Pixel*));
    va_end(ptr);
    reset(1);
  }
  void addPIXELS(int n, Pixel** A) {
    for (int i = 0; i < n;i++) this->_addPixel(A[i]);
    reset(1);
  }
  void addPIXELS(vector<Pixel*> A) {
    for (int i = 0; i < A.size();i++) this->_addPixel(A.at(i));
    reset(1);
  }
  Pixel* findPixel(int i, int j) {
    if (i >= height || j >= width) return nullptr;
    return this->_screen[i][j];
  }
  Pixel* findPixel(int* pos) {
    if (pos[0] >= height || pos[1] >= width) return nullptr;
    return this->_screen[pos[0]][pos[1]];
  }
private:
  int getChange(int code) { return this->_change[code]; }
  void trackChange(int i = 1, int code = 0) { this->_change[code] = i; }
  void reset(int value = 0) { for (int i = 0; i < this->_changeValue;i++) this->trackChange(value, i); }
  void _addPixel(Pixel* A) {
    if (A == nullptr) return;
    this->_screen[A->pos[0]][A->pos[1]] = (Pixel*)A;
    this->PIXELS.push_back(A);
  }
  string _out, _outGrey;
  int _changeValue = 2;
  int width, height, * ratio, * _change = new int[] {0, 0};
  vector<Pixel*> PIXELS;
  Pixel*** _screen;
  PIXEL* defPix;
};

#if __INCLUDE_LEVEL__ == 0
int main() {
  // srand((unsigned)time(NULL));

  int* rat = (int*)malloc(2 * sizeof(int));
  rat[0] = 1; rat[1] = 2;

  int height = 30, width = 30;
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
  LAYER C(&A, rat, width, height);
  // cout << "ed";
  C.addPIXELS(B);
  C.print();
  // scanf("%d");
}
#else
#pragma once
#endif
