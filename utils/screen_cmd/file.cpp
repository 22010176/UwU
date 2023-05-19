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
  string a = to_string(time(0));
  WriteFile("./samples/"+a+".txt",a);

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