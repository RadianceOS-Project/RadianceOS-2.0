#include <limine/limine.h>
#include <KernelUtils/KernelUtils.h>
#include <VideoUtils/videoutils.h>

// Set the base revision to 1, this is recommended as this is the latest
// base revision described by the Limine boot protocol specification.
// See specification for further info.

LIMINE_BASE_REVISION(1)

// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, in C, they should
// NOT be made "static".

struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

bool Running = true;
struct limine_framebuffer* framebuffer;
// The following will be our kernel's entry point.
// If renaming _start() to something else, make sure to change the
// linker script accordingly.

void _loop(void); // Forward declaration

void _start(void) {
    // Ensure the bootloader actually understands our base revision (see spec).
    if (LIMINE_BASE_REVISION_SUPPORTED == false) {
        //hcf(); // Temp
    }

    //prints the test hello message
    //printf("Hello from radiace 2.0"); // ISO C++ doesn't support it lmao

    // Ensure we got a framebuffer.
    if (framebuffer_request.response == NULL
     || framebuffer_request.response->framebuffer_count < 1) {
        //hcf(); // Temp
    }
    
    // Fetch the first framebuffer.
    framebuffer = framebuffer_request.response->framebuffers[0];
    //Setframebuffer(framebuffer); // Temp

    while (Running)
    {
        //_loop();
    }
    // We're done, just hang...
    //hcf(); // Temp

    asm("cli");
    for (;;) {
        asm("hlt");
    }
}

void _loop(void)
{

    //ClearScreen(0xffffff);
    //DrawFilledRectangle(10,10,100,100,0x141414);

}