#include <bits/stdc++.h>
#include "utils/pixels.cpp"
using namespace std;

int main()
{
    Pixel *A = GeneratePixel(32, 7, 1);
    Pixel *B = GeneratePixel(36, 7, 1);
    cout << CreatePixel(A) << CreatePixel(B);
}