#include <string>
#pragma once
using namespace std;

string reverse(string A);
string NumToString(int n);
static string _A1(int i);

#if __INCLUDE_LEVEL__ == 0
int main() {

}
#endif

string reverse(string A) {
  string B = "";
  for (int i = A.length() - 1; i >= 0; i--) B += A[i];
  return B;
}
string NumToString(int n) {
  int x = n;
  string A = "";
  do {
    A += _A1(x % 10);
    x /= 10;
  } while (x != 0);

  return reverse(A);
}
string _A1(int i) {
  switch (i) {
  case 1: return "1";
  case 2: return "2";
  case 3: return "3";
  case 4: return "4";
  case 5: return "5";
  case 6: return "6";
  case 7: return "7";
  case 8: return "8";
  case 9: return "9";
  case 0: return "0";
  }
  return "";
}