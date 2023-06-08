#include "../header.h"
#include "../Number.cpp"
#include "../writeFile.cpp"
#include "Chunk.cpp"


template <typename T> void checkData(vector<int> z);
Chunk GetHead(string path, vector<Data>(*func)(string));
Chunk GetChunk(string path, size_t pos, vector<Data>(*func)(string, size_t, size_t));
Data InsertData(string _path, size_t _pos, size_t _length, string _name);
// Chunk GetChunk(string path, size_t pos) {
//   size_t size = GetNum(Data::GetData(path, pos, 4));
//   string type = SparseDataString(Data::GetData(path, pos + 4, 4));
// }
// 0 -> 7
vector<Data> GetHeadData(string _path);
// 16 -> 28
vector<Data> GetIHDRData(string _path, size_t pos, size_t len);
vector<Data> getGeneralChunk(string path, size_t pos, size_t len) {
  return vector<Data> {InsertData(path, pos, len, "data")};
}
#if __INCLUDE_LEVEL__ == 0
int main() {
  string path = "../../data/png/sample.png";
  string result = "../../data/txt/dat.txt";
  int size = getFileSize(path);
  Chunk Head = GetHead(path, GetHeadData); // 0 -> 7
  Chunk IHDR = GetChunk(path, 8, GetIHDRData); // 8 -> 28
  for (int i = 8;i < size;) {
    vector<int> size2 = Data::GetData(path, i, 4);
    i += 4;
    vector<int> type = Data::GetData(path, i, 4);
    i += 4;
    vector<int> data = Data::GetData(path, i, GetNum(size2, 16));
    i += GetNum(size2, 16);
    vector <int> CRC = Data::GetData(path, i, 4);
    i += 4;
    cout << fillEnd(" ", 6, to_string(GetNum(size2, 16)));
    cout << fillEnd(" ", 6, SpareDataInt(type));
    cout << endl;
  }
}
#else
#pragma once
#endif
template <typename T> void checkData(vector<int> z) {
  for (int i : z)  cout << (T)i << " ";
  cout << endl;
}
Chunk GetHead(string path, vector<Data>(*func)(string)) {
  return Chunk("Head", 0, 8, func(path));
}
Chunk GetChunk(string path, size_t pos, vector<Data>(*func)(string, size_t, size_t)) {
  int size = GetNum(Data::GetData(path, pos, 4), 16);
  string type = SparseDataString(Data::GetData(path, pos + 4, 4));
  return Chunk(type, pos, size, func(path, pos + 8, size), Data::GetData(path, pos + 8 + size, 4));
}
Data InsertData(string _path, size_t _pos, size_t _length, string _name) {
  return Data(Data::GetData(_path, _pos, _length), _pos, _length, _name);
}
vector<Data> GetHeadData(string path) {
  vector<Data> dat;
  dat.push_back(InsertData(path, 0, 1, "8bit_support"));
  dat.push_back(InsertData(path, 1, 3, "PNG"));
  dat.push_back(InsertData(path, 4, 2, "DOS_ending"));
  dat.push_back(InsertData(path, 6, 1, "DOS_end_file"));
  dat.push_back(InsertData(path, 7, 1, "UNIX_endl"));
  return dat;
}
vector<Data> GetIHDRData(string path, size_t pos, size_t len) {
  vector<Data> dat;
  dat.push_back(InsertData(path, 16, 4, "width"));
  dat.push_back(InsertData(path, 20, 4, "height"));
  dat.push_back(InsertData(path, 24, 1, "bitdepth"));
  dat.push_back(InsertData(path, 25, 1, "color_type"));
  dat.push_back(InsertData(path, 26, 1, "compress_method"));
  dat.push_back(InsertData(path, 27, 1, "filter_method"));
  dat.push_back(InsertData(path, 28, 1, "interlance_method"));
  return dat;
}