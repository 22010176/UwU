#include <iostream>
#include "./pixel.cpp"
using namespace std;

#if __INCLUDE_LEVEL__ == 0
int main() {
  PIXEL A(32, 3, 0);
  cout << A.updateProbs(42, 3, 0).render();
}
#endif