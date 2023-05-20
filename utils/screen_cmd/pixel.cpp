#include <iostream>
#include "../others/stringFormat.cpp"

using namespace std;
#define GREYSCALE "@MBHENR#KWXDFPQASUZbdehx*8Gm&04LOVYkpq5Tagns69owz$CIu23Jcfry%1v7l+it[]{}?j|()=~!-/<>\"^_';,:`. "

/*
          foreground background
black        30         40
red          31         41
green        32         42
yellow       33         43
blue         34         44
magenta      35         45
cyan         36         46
white        37         47

intensity 0 - 93 94
foreground 30 - 37
background 40 - 47
*/

class PIXEL {
public:
  ~PIXEL() {}
  PIXEL(int _color = 0, int _intent = 94, int _mode = 0) {
    this->updateProbs(_color, _intent, _mode);
  }
  PIXEL updateProbs(int _color = 0, int _intent = 93, int _mode = 0) {
    this->color = _color;
    this->mode = _mode;
    this->intent = _intent;
    this->_change = 1;
    return *this;
  }
  int getColor() { return this->color; }
  int getMode() { return this->mode; }
  int getIntent() { return this->intent; }
  string render() {
    if (!_change) return this->_A;
    string B = "\033[";
    B += NumToString(this->mode) + ";" + NumToString(this->color) + "m" + GREYSCALE[this->intent];
    this->_change = 0;
    return B;
  }
private:
  int color, mode, intent, _change;
  string _A;
};

#if __INCLUDE_LEVEL__ == 0
int main() {
  int A = NULL ? 1 : 0;
  cout << A << "ASDFASFD"[4];
}
#else
#pragma once
#endif