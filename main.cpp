#include <fstream>
#include <iterator>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

class Test {
public:
  int x; char b[40];
  Test(string b, int x) {
    this->x = x;
    strcpy(this->b, b.c_str());
  }
  Test() {}
  void info() { cout << x << '\n' << b << '\n'; }
};
void Write(Test Data) {
  ofstream file("data.dat", ios::binary | ios::app);
  file.write((char*)(&Data), sizeof(Data));
  file.close();
}

void Read() {
  ifstream file("data.dat", ios::binary);
  Test data;
  while (file.read((char*)&data, sizeof(data))) {
    data.info();
    cout << file.tellg() << endl;
    cout << "__________________\n";
  }
  file.close();
}
int main() {
  // Test B("abc", 6);
  // Test C("abdc", 3334);
  // Write(B);
  // Write(C);
  Read();
}