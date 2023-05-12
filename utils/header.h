struct Pixel {
    int color;
    int mode;
    int intensity;
};

struct Screen {
    Pixel*** screen;
    int width;
    int heigth;
    int p_ratio;
};

class Vector2 {
public:
    float x;
    float y;
    float length = NULL;
    Vector2(float x_, float y_) {
        x = x_;
        y = y_;
    }
    float Len() {
        if (length == NULL)length = sqrt(x * x + y * y);
        return length;
    }
};