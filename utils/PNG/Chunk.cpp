#include "./Data.cpp"
#include <string>
#pragma once
using namespace std;

class Chunk {
private:
public:
  string name;
  size_t pos, length;
  vector<int> CRC;
  vector<Data> data;
  Chunk() {}
  Chunk(string _name, size_t _pos, size_t _length, vector<Data>_data) {
    this->name = _name;
    this->pos = _pos;
    this->length = _length;
    this->data.assign(_data.begin(), _data.end());
  }
  Chunk(string _name, size_t _pos, size_t _length, vector<Data>_data, vector<int> _CRC) {
    this->name = _name;
    this->pos = _pos;
    this->length = _length;
    this->data.assign(_data.begin(), _data.end());
    this->CRC.assign(_CRC.begin(), _CRC.end());
  }
  ~Chunk() {
    this->data.~vector();
    this->name.~basic_string();
    this->CRC.~vector();
  }
  int GetDataIndex(string name) {
    for (int i = 0;i < this->data.size();i++) {
      Data* current = &this->data.at(i);
      if (current->getName() == name) return i;
    }
    return -1;
  }
  vector<int> GetData(string name) {
    for (int i = 0;i < this->data.size();i++) {
      Data* current = &this->data.at(i);
      if (current->getName() == name) return current->getData();
    }
    return vector<int>();
  }
};
#if __INCLUDE_LEVEL__ == 0
int main() {}
#else
#pragma once
#endif