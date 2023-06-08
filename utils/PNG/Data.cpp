#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include "../Number.cpp"

#pragma once
using namespace std;

class Data {
private:
  vector<int> data;
  int pos, size;
  string name;
  static vector<int> _ParseData(ifstream& file, int len, size_t pos) {
    file.seekg(pos);
    char a[len];
    file.read(a, len);
    vector<int> res;
    for (int i = 0; i < len;i++) res.push_back(RealNum((int)a[i]));
    file.close();
    return res;
  }
public:
  static vector<int> GetData(string path, size_t pos, size_t len) {
    ifstream file(path, ios::binary);
    return _ParseData(file, len, pos);
  }
  static vector<int> GetData(ifstream& file, size_t pos, size_t len) {
    return _ParseData(file, len, pos);
  }
  Data(vector<int> data, int pos, int size, string name) {
    this->data.assign(data.begin(), data.end());
    this->pos = pos;
    this->size = size; // in byte
    this->name = name;
  };
  ~Data() { data.~vector(); };
  vector<int> getData() { return this->data; }
  int getSize() { return this->size; }
  int getPos() { return this->pos; }
  string getName() { return this->name; }
};
