
// #ifdef
struct Pixel
{
    int color;
    int mode;
    int intensity;
};

struct Screen
{
    Pixel ***screen;
    int width;
    int heigth;
    int p_ratio;
};
// #endif