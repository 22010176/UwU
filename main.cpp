#include <bits/stdc++.h>
using namespace std;

struct A { int x; };
int main() {
  A* a = (A*)malloc(sizeof(A) * 1000);
  a[0] = { 5 };
  a[1] = { 2 };
  for (int i = 0; i < 10;i++) {
    cout << &a[i] << endl;
  }
}