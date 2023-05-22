#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include "screen.cpp"
#include <string.h>
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
string _10to16(int i) {
  if (!i) return " 00";
  char a_[] = "0123456789ABCDEF";
  int b = abs(i);

  string a = i > 0 ? " " : "-";
  a += b < 16 ? "0" : "";
  while (b != 0) {
    a += a_[b % 16];
    b = int(b / 16);
  }
  return a;
}
#if __INCLUDE_LEVEL__ == 0
int main() {
  // Open the file for writing in binary mode
  fstream outfile("a/1e3f8eef208159258bb8136391e68605.png", ios::binary | ios::out | ios::in);
  int size = (int)pow(2, sizeof(char) * 8);
  char a[size], a_;

  char b; int i = 0, c;
  string B;
  while (outfile.read(&b, 1)) {
    B += _10to16(b) + " ";
    if (++i % 16 == 0) B += '\n';
  }
  WriteFile("Data.txt", B);

  outfile.close();

  return 0;
}
#else
#pragma once
#endif