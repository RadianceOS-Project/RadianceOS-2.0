#include <limine/limine.h>
#include <VideoUtils/videoutils.h>

/*limine_framebuffer* framebuffer;

void Setframebuffer(limine_framebuffer* framebuff)
{
	framebuffer = framebuff;
}
void ClearScreen(unsigned int color)
{
    // Note: we assume the framebuffer model is RGB with 32-bit pixels.
    for (uint64_t i = 0; i < framebuffer->width; i++) {
        volatile uint32_t* fb_ptr = framebuffer->address;
        fb_ptr[i * (framebuffer->pitch / 4) + i] = color;
    }
}
void DrawFilledRectangle(int x,int y,int widht,int height,unsigned int color)
{

    volatile uint32_t* fb_ptr = framebuffer->address;
    for (uint64_t i = x; i < framebuffer->width + x; i++)
    {
        for (uint64_t j = 0; j < framebuffer->height + y; j++)
        {
            fb_ptr[i+j*framebuffer->width] = color;
        }
    }

}
void DrawPoint(int x, int y, unsigned int color)
{

    volatile uint32_t* fb_ptr = framebuffer->address;
    fb_ptr[x + y * framebuffer->width] = color;

}
void drawLine(int x1, int y1, int x2, int y2,unsigned int color) 
{
    int dx, dy, p, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    x = x1;
    y = y1;

    p = 2 * dy - dx;

    for (int i = 0; i < dx; i++) {
        if (p < 0) {
            DrawPoint(x, y, 7);
            y = y + 1;
            p = p + 2 * dy;
        }
        else {
            DrawPoint(x, y, 7);
            x = x + 1;
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
    }
}*/