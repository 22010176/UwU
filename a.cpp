#include <typeinfo>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
  vector<int> a;
  cout << sizeof(a) << endl;
  cout << sizeof(vector<int>) << endl;
  cout << sizeof(vector<int>*) << endl;
  cout << sizeof(int*) << endl;
  cout << sizeof(string) << endl;
  cout << sizeof(string*) << endl;
  string af = typeid(a).name();
  string b = typeid(vector<int>).name();
  cout << b << endl << af;
}