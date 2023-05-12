#include <iostream>
#include "header.h"
using namespace std;
#define GREYSCALE "@MBHENR#KWXDFPQASUZbdehx*8Gm&04LOVYkpq5Tagns69owz$CIu23Jcfry%1v7l+it[]{}?j|()=~!-/<>\"^_';,:`. "
#define RED 31
// foreground 30 - 37
// background 40 - 47
const string INTENSITY = GREYSCALE;

// https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal

/*
          foreground background
black        30         40
red          31         41
green        32         42
yellow       33         43
blue         34         44
magenta      35         45
cyan         36         46
white        37         47
intensity 0 - 93
*/
Pixel* GeneratePixel(int color, int intensity, int mode);
string CreatePixel(Pixel* A);
string NumToString(int n);
string _A1(int i);

#if __INCLUDE_LEVEL__ == 0
int main()
{
    Pixel* A;
    for (int j = 30; j < 38; j++)
    {
        for (int i = 0; i < 96; i++)
        {
            A = GeneratePixel(j, i, 4);
            cout << CreatePixel(A);
        }
        cout << endl;
    }
    cout << endl;
    // Pixel *A = GeneratePixel(34, 100);
    // string C = CreatePixel(A);
    // cout << C;
    // cout << NumToString(8689);
}
#endif

Pixel* GeneratePixel(int color, int intensity, int mode)
{
    Pixel* A = (Pixel*)malloc(sizeof(Pixel));
    A->color = color;
    A->intensity = intensity;
    A->mode = mode;
    return A;
}
string reverse(string A)
{
    string B = "";
    for (int i = A.length() - 1; i >= 0; i--)
        B += A[i];
    return B;
}
string NumToString(int n)
{
    int x = n;
    string A = "";
    do
    {
        A += _A1(x % 10);
        x /= 10;

    } while (x != 0);

    return reverse(A);
}
string _A1(int i)
{
    switch (i)
    {
    case 1:
        return "1";
    case 2:
        return "2";
    case 3:
        return "3";
    case 4:
        return "4";
    case 5:
        return "5";
    case 6:
        return "6";
    case 7:
        return "7";
    case 8:
        return "8";
    case 9:
        return "9";
    case 0:
        return "0";
    }
    return "";
}
string CreatePixel(Pixel* A)
{
    string B = "\033[";
    B += NumToString(A->mode) + ";" + NumToString(A->color) + "m" + INTENSITY[A->intensity];
    return B;
}