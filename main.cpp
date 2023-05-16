#include <bits/stdc++.h>

using namespace std;
class A {
public:
  string he = "asdf";
};
struct B { A* test; };
int main() {
  A j;
  B d;
  d.test = &j;
  cout << d.test->he;
}