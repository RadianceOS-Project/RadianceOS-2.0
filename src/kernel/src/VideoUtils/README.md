# RadianceOS 2.0 folder structure

- [RadianceOS 2.0 folder structure](#radianceos-20-folder-structure)
  - [videoutils.cpp](#videoutilscpp)
    - [`void SetFrameBuffer(limine_framebuffer framebuff)`](#void-setframebufferlimine_framebuffer-framebuff)
    - [`void ClearScreen(unsigned int color)`](#void-clearscreenunsigned-int-color)
    - [`void DrawFilledRectangle(int x, int y, int width, int height, unsigned int color)`](#void-drawfilledrectangleint-x-int-y-int-width-int-height-unsigned-int-color)
    - [`void DrawPoint(int x, int y, unsigned int color)`](#void-drawpointint-x-int-y-unsigned-int-color)
    - [`void drawLine(int x1, int y1, int x2, int y2, unsigned int color)`](#void-drawlineint-x1-int-y1-int-x2-int-y2-unsigned-int-color)
  - [videoutils.h](#videoutilsh)

## videoutils.cpp
The video utils file.

Includes:
- `<limine/limine.h>`
- `<VideoUtils/videoutils.h>`

Variables:
- `limine_framebuffer framebuffer` - The limine frame buffer (For drawing stuff basically)

### `void SetFrameBuffer(limine_framebuffer framebuff)`
This literally just sets the frame buffer.
- `limine_framebuffer framebuff` - The limine frame buffer

### `void ClearScreen(unsigned int color)`
This clears the screen with a specific color.
- `unsigned int color` - The color to clear the screen with

### `void DrawFilledRectangle(int x, int y, int width, int height, unsigned int color)`
This draws a filled rectangle to the limine frame buffer.
- `int x`              - The starting X position of the rectangle
- `int y`              - The starting Y position of the rectangle
- `int width`          - The width of the rectangle
- `int height`         - The height of the rectangle
- `unsigned int color` - The color to fill it with

### `void DrawPoint(int x, int y, unsigned int color)`
This draws a single point to the screen.
- `int x`              - The X position of the pixel to draw
- `int y`              - The Y position of the pixel to draw
- `unsigned int color` - The color of the single pixel to draw

### `void drawLine(int x1, int y1, int x2, int y2, unsigned int color)`
This draws a line from one point to another.
- `int x1`                 - The X position of the first point
- `int y1`                 - The Y position of the first point
- `int x2`                 - The X position of the second point
- `int y2`                 - The Y position of the second point
- `int unsigned int color` - The color to draw the line in

## videoutils.h
The header file for videoutils.cpp

Includes:
- `<limine/limine.h>`

Definitions:
- `void SetFrameBuffer(limine_framebuffer framebuff)`                                 - [Usage](#void-setframebufferlimine_framebuffer-framebuff)
- `void ClearScreen(unsigned int color)`                                              - [Usage](#void-clearscreenunsigned-int-color)
- `void DrawFilledRectangle(int x, int y, int width, int height, unsigned int color)` - [Usage](#void-drawfilledrectangleint-x-int-y-int-width-int-height-unsigned-int-color)
- `void DrawPoint(int x, int y, unsigned int color)`                                  - [Usage](#void-drawpointint-x-int-y-unsigned-int-color)
- `void DrawLine(int x1, in y1, int x2, int y2, unsigned int color)`                  - [Usage](#void-drawlineint-x1-int-y1-int-x2-int-y2-unsigned-int-color)