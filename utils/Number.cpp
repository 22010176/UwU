#include "header.h"
#include "./String.cpp"




int RealNum(int);
string IntToBaseN(int, string);
int BaseNToInt(string, string);
int GetNum(vector<int>);

#if __INCLUDE_LEVEL__ == 0
int main() {}
#else
#pragma once
#endif
int GetNum(vector<int> _x, int base) {
  int res = 0;
  for (int i = 0;i < _x.size();i++) res += (int)pow(base, _x.size() - 1 - i) * _x.at(i);
  return res;
}
string IntToBaseN(int _number, string _n) {
  if (!_number) return "0";
  int n = _n.length(), x = _number;
  string result;
  while (x) {
    result += _n[x % n];
    x /= n;
  }
  return Reverse(result);
}
int RealNum(int _num) { return BaseNToInt(bitset<8>(_num).to_string(), BIN); }
int BaseNToInt(string _num, string _base) {
  int n = _base.length(), res = 0;
  for (int i = 0, x; i < _num.length();i++) {
    x = _base.find(_num[i]);
    if (x > _base.length()) return -1;
    res += (int)pow(n, _num.length() - 1 - i) * x;
  }
  return res;
}