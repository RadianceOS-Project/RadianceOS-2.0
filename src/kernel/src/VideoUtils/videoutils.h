#include <limine/limine.h>
void Setframebuffer(limine_framebuffer framebuff);
void ClearScreen(unsigned int color);
void DrawFilledRectangle(int x, int y, int width, int height, unsigned int color);
void DrawPoint(int x, int y, unsigned int color);
void DrawLine(int x1, int y1, int x2, int y2, unsigned int color);
