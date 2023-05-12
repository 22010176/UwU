#include <iostream>
#include "./pixels.cpp"
using namespace std;

Screen* CreateScreen(int height, int width, int p_ratio) {
    Screen* A = (Screen*)malloc(sizeof(Screen));
    A->screen = (Pixel***)malloc(height * sizeof(Pixel*));
    int realWidth = p_ratio * width;
    for (int i = 0; i < height; i++) {
        A->screen[i] = (Pixel**)malloc(realWidth * sizeof(Pixel));
        for (int j = 0; j < realWidth; j++)
            A->screen[i][j] = GeneratePixel(0, 0, 0);
    }
    A->width = width;
    A->heigth = height;
    A->p_ratio = p_ratio;
    return A;
}
void Out(Screen* A)
{
    int width = A->width, height = A->heigth, r = A->p_ratio;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width * r; j++)
            cout << CreatePixel(A->screen[i][j]);
        cout << endl;
    }
}
#if __INCLUDE_LEVEL__ == 0
int main() {
    Screen* A = CreateScreen(30, 55, 2);
    Out(A);
}
#endif
