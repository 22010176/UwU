#include <iostream>
#include <fstream>
#include "screen.cpp"
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
using namespace std;
void WriteFile(string path,string data){
  ofstream file(path);
  file << data;
  file.close();
}
int main() {
  
    auto start = std::chrono::system_clock::now();
    // Some computation here
    auto end = std::chrono::system_clock::now();
    cout << start << " " << end;
  WriteFile("./samples/data.txt","asdfasf");

  // string myText;

  // // Read from the text file
  // ifstream MyReadFile("filename.txt");

  // // Use a while loop together with the getline() function to read the file line by line
  // while (getline(MyReadFile, myText)) {
  //   // Output the text from the file
  //   cout << myText << endl;
  // }

  // // Close the file
  // MyReadFile.close();
}