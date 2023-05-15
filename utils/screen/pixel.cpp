#include <iostream>
#include "../others/stringFormat.cpp"
#pragma once

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

intensity 0 - 93
foreground 30 - 37
background 40 - 47
*/



class PIXEL {
public:
  ~PIXEL() {}
  PIXEL(int _color, int _intent, int _mode) {
    this->updateProbs(_color, _mode, _intent);
  }
  PIXEL updateProbs(int _color, int _mode, int _intent) {
    this->color = _color ? _color : 0;
    this->mode = _mode ? _mode : 0;
    this->intent = _intent ? _intent : 0;
    return *this;
  }
  int getColor() { return this->color; }
  int getMode() { return this->mode; }
  int getIntent() { return this->intent; }
  string render() {
    string B = "\033[";
    B += NumToString(this->mode) + ";" + NumToString(this->color) + "m" + GREYSCALE[this->intent];
    return B;
  }
private:
  int color, mode, intent;
};

#if __INCLUDE_LEVEL__ == 0
int main() {
  int A = NULL ? 1 : 0;
  cout << A << "ASDFASFD"[4];
}
#endif