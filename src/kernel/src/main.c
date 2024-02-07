#include <limine/limine.h>
#include <KernelUtils/KernelUtils.h>
#include <VideoUtils/videoutils.h>
#include <VideoUtils/colors.h>
#include <VideoUtils/videospecs.h>

// Set the base revision to 1, this is recommended as this is the latest
// base revision described by the Limine boot protocol specification.
// See specification for further info.

LIMINE_BASE_REVISION(1)

// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, in C, they should
// NOT be made "static".

/*struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};*/

bool Running = true;
//struct limine_framebuffer* framebuffer;
// The following will be our kernel's entry point.
// If renaming _start() to something else, make sure to change the
// linker script accordingly.

// Temp
static void _hcf(void) {
    asm("cli");
    for (;;) {
        asm("hlt");
    }
}

void _loop(void); // Forward declaration

void _start(void) {
    // Ensure the bootloader actually understands our base revision (see spec).
    if (LIMINE_BASE_REVISION_SUPPORTED == false) {
        _hcf();
    }

    //prints the test hello message
    //printf("Hello from radiace 2.0"); // ISO C++ doesn't support it lmao

    // Ensure we got a framebuffer.
    /*if (framebuffer_request.response == NULL
     || framebuffer_request.response->framebuffer_count < 1) {
        _hcf();
    }*/
    
    // Fetch the first framebuffer.
    //struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];
    //Setframebuffer(framebuffer);
    InitialiseFrameBuffer();
    //framebuffer = framebuffer_request.response->framebuffers[0];
    //Setframebuffer(framebuffer); // Temp

    ClearScreen(0x0);

    while (Running)
    {
        _loop();
    }

    // We're done, just hang...
    _hcf();
}

unsigned int colorA = 0x0; // 1
unsigned int colorB = 0x0; // 2
unsigned int colorC = 0x0; // 3
unsigned int colorD = 0x0; // 4
unsigned int colorE = 0x0; // 5
unsigned int colorF = 0x0; // 6
unsigned int colorG = 0x0; // 7
unsigned int colorH = 0x0; // 8

unsigned int colorA1 = 0x0; // 1
unsigned int colorB1 = 0x0; // 2
unsigned int colorC1 = 0x0; // 3
unsigned int colorD1 = 0x0; // 4
unsigned int colorE1 = 0x0; // 5
unsigned int colorF1 = 0x0; // 6
unsigned int colorG1 = 0x0; // 7
unsigned int colorH1 = 0x0; // 8

unsigned int frame = 0;

unsigned int bgc = 0x0;

void _loop(void)
{
    frame++;

    if(frame % 4 == 0) {
        colorA += 0x001F;
        colorB += 0x002F;
        colorC += 0x003F;
        colorD += 0x004F;
        colorE += 0x005F;
        colorF += 0x006F;
        colorG += 0x007F;
        colorH += 0x008F;

        colorA1 += 0x01F;
        colorB1 += 0x02F;
        colorC1 += 0x03F;
        colorD1 += 0x04F;
        colorE1 += 0x05F;
        colorF1 += 0x06F;
        colorG1 += 0x07F;
        colorH1 += 0x08F;
    }

    //ClearScreen(0xffffff);
    //ClearScreen(0x171717); // Clear it with a matte black screen (Because it looks nice lol)
    //DrawFilledRectangle(10,10,100,100,0xffffff); // 0x141414

    DrawFilledRectangle(25, 25, 100, 100, colorA);
    DrawFilledRectangle(25 + 100 + 25, 25, 100, 100, colorB);
    DrawFilledRectangle(25 + ((100 + 25) * 2), 25, 100, 100, colorC);
    DrawFilledRectangle(25 + ((100 + 25) * 3), 25, 100, 100, colorD);
    DrawFilledRectangle(25 + ((100 + 25) * 4), 25, 100, 100, colorE);
    DrawFilledRectangle(25 + ((100 + 25) * 5), 25, 100, 100, colorF);
    DrawFilledRectangle(25 + ((100 + 25) * 6), 25, 100, 100, colorG);
    DrawFilledRectangle(25 + ((100 + 25) * 7), 25, 100, 100, colorH);

    // 2nd line I guess

    DrawFilledRectangle(25, 25 + 100 + 25, 100, 100, colorA1);
    DrawFilledRectangle(25 + 100 + 25, 25 + 100 + 25, 100, 100, colorB1);
    DrawFilledRectangle(25 + ((100 + 25) * 2), 25 + 100 + 25, 100, 100, colorC1);
    DrawFilledRectangle(25 + ((100 + 25) * 3), 25 + 100 + 25, 100, 100, colorD1);
    DrawFilledRectangle(25 + ((100 + 25) * 4), 25 + 100 + 25, 100, 100, colorE1);
    DrawFilledRectangle(25 + ((100 + 25) * 5), 25 + 100 + 25, 100, 100, colorF1);
    DrawFilledRectangle(25 + ((100 + 25) * 6), 25 + 100 + 25, 100, 100, colorG1);
    DrawFilledRectangle(25 + ((100 + 25) * 7), 25 + 100 + 25, 100, 100, colorH1);

    //DrawFilledRectangle(25, 25, GetWidth() - 50, GetHeight() - 50, colorB); // 0xffffff

    // Now display boxes going up depending on the frames
    
    unsigned int f = frame / 100; // Makes it easier to draw
    unsigned int dh = 0; // Display height

    for (size_t i = 0; i < f; i++)
    {
        if(i % GetWidth() == 0) dh++;

        DrawFilledRectangle(i, 25 + 100 + 25 + 100 + 25 + dh, 1, 1, 0xffffff);
    }

    if(frame % 5000 == 0)
    {
        if(bgc == 0x0) bgc = 0x3f3f3f;
        else if(bgc == 0x3f3f3f) bgc = 0x0;

        ClearScreen(bgc);
    }
}