#include <algorithm>
#include "../screen_cmd/screen.cpp"
using namespace std;

#if __INCLUDE_LEVEL__ == 0
int main() {
  LAYER* A = LAYER::CreateLayer(100, 100);
  A->print();
}
#else
#pragma once
#endif