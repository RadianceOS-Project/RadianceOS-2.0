#include <limine/limine.h>
#include <VideoUtils/videoutils.h>
#include <VideoUtils/videospecs.h>
#include <KernelUtils/KernelUtils.h>

struct limine_framebuffer *framebuffer;

struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

/*void Setframebuffer(struct limine_framebuffer *framebuff)
{
	framebuffer = framebuff;
}*/

void InitialiseFrameBuffer() {
    if(framebuffer_request.response == NULL || framebuffer_request.response->framebuffer_count < 1) {
        //hcf(); // Halt the CPU if something isn't right // Or not lol
    }

    framebuffer = framebuffer_request.response->framebuffers[0]; // Somehow we could have multiple?

    // Also initialise some screen specifications
    //ScreenbufferWidth = framebuffer->width;
    //ScreenbufferHeight = framebuffer->height;
}

int GetWidth(void) { return framebuffer->width; }
int GetHeight(void) { return framebuffer->height; }

void ClearScreen(unsigned int color)
{
    // Note: we assume the framebuffer model is RGB with 32-bit pixels.
    /*for (uint64_t i = 0; i < framebuffer->width; i++) {
        volatile uint32_t* fb_ptr = framebuffer->address;
        fb_ptr[i * (framebuffer->pitch / 4) + i] = color;
    }*/

    for (uint64_t y = 0; y < framebuffer->height; y++) {
        // Working from top to bottom
        
        for(uint64_t x = 0; x < framebuffer->width; x++) {
            // Working from left to right

            DrawPoint(x, y, color);
        }
    }
}

void DrawFilledRectangle(int x, int y, int width, int height, unsigned int color)
{
    // This is not a rectangle lmao
    /*
    volatile uint32_t* fb_ptr = framebuffer->address;
    for (uint64_t i = x; i < framebuffer->width + x; i++)
    {
        for (uint64_t j = 0; j < framebuffer->height + y; j++)
        {
            fb_ptr[i+j*framebuffer->width] = color;
        }
    }
    */

   volatile uint32_t* fb_ptr = framebuffer->address;

   // Work out every pixel we need
   for (uint64_t _y = 0; _y < height; _y++) {
        // Work from top to bottom, makes it easier
        uint64_t posY = _y + y;

        for (uint64_t _x = 0; _x < width; _x++) {
            // Now work from left to right
            uint64_t posX = _x + x;

            fb_ptr[posX + posY * framebuffer->width] = color; // Draw the position on the screen
        }
   }
}

void DrawPoint(int x, int y, unsigned int color)
{

    volatile uint32_t* fb_ptr = framebuffer->address;
    fb_ptr[x + y * framebuffer->width] = color;

}

void drawLine(int x1, int y1, int x2, int y2, unsigned int color) 
{
    int dx, dy, p, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    x = x1;
    y = y1;

    p = 2 * dy - dx;

    for (int i = 0; i < dx; i++) {
        if (p < 0) {
            DrawPoint(x, y, color);
            y = y + 1;
            p = p + 2 * dy;
        }
        else {
            DrawPoint(x, y, color);
            x = x + 1;
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
    }
}