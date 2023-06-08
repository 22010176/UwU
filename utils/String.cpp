#include "header.h"
string Reverse(string _src) {
  string _dest;
  for (int i = 0;i < _src.length();i++) _dest += _src[_src.length() - 1 - i];
  return _dest;
}
string fillStart(string x, int times, string A = "") {
  string a;
  for (int i = 0; i < times - A.length();a += x, i++);
  return a + A;
}
string fillEnd(string x, int times, string A = "") {
  string a;
  for (int i = 0; i < times - A.length();a += x, i++);
  return  A + a;
};
string SpareDataInt(vector<int> data, int space = 4) {
  string res;
  for (int i : data) res += fillEnd(" ", space, to_string(i));
  return res;
}
string SparseDataString(vector<int> data) {
  char x[data.size()];
  for (int i = 0; i < data.size();i++) x[i] = data.at(i);
  x[data.size()] = '\0';
  return x;
}

#if __INCLUDE_LEVEL__ == 0
#include <string.h>
int main() {
  string A = "JKEED", res = "DEEKJ", res2 = "  DEEKJ";
  vector<int> B = { 73, 72, 68, 82 };
  cout << SparseDataString(B) << endl;
  cout << SpareDataInt(B) << endl;
  cout << "Reverse is " << ((Reverse(A) == res) ? "Good" : "No") << endl;
  // cout << "fillStart is " << ((strcmp(fillStart(" ", 2, A).c_str(), res2.c_str())) ? "Good" : "No");
}
#else
#pragma once
#endif