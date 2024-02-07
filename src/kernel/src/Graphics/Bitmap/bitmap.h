#include <list>

using std::list;

class Bitmap {
public:
    list<BitmapPixel> pixels;

    void RenderBitmap(void);
};

class BitmapPixel {
public:
    unsigned int x;
    unsigned int y;
    unsigned int color;
};