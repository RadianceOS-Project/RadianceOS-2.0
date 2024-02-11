#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <limine.h>
#include <flanterm/flanterm.h>
#include <flanterm/backends/fb.h>

#include <hardware/hardwareutils.h>
#include <io/serial.h>

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

// Halt and catch fire function.
static void hcf(void) {
    asm ("cli");
    for (;;) {
        asm ("hlt");
    }
}

bool debug = false;
bool debug__COM1 = true;

void debug_write(void* ft_ctx, const char msg[]) {
    if(debug) {
        flanterm_write(ft_ctx, msg, strlen(msg));
    }

    if(debug__COM1) {
        if(COM1Init()) {
            SerialWriteString(COM1, msg);
        }
    }
}

// The following will be our kernel's entry point.
// If renaming _start() to something else, make sure to change the
// linker script accordingly.
void _start(void) {
    // Ensure the bootloader actually understands our base revision (see spec).
    if (!LIMINE_BASE_REVISION_SUPPORTED) {
        hcf();
    }

    // Ensure we got a framebuffer.
    if (framebuffer_request.response == NULL
     || framebuffer_request.response->framebuffer_count < 1) {
        hcf();
    }

    // Fetch the first framebuffer.
    struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];

    struct flanterm_context *ft_ctx = flanterm_fb_simple_init(
        framebuffer->address, framebuffer->width, framebuffer->height, framebuffer->pitch
    );

    const char msg[] = "Hello, world!\nThis is a test of the flanterm terminal emulator.\n";

    flanterm_write(ft_ctx, msg, sizeof(msg));

    ft_ctx->clear(ft_ctx, true);

    debug_write(ft_ctx, "RadianceOS 2.0 - Boot Manager\n\n");

    debug_write(ft_ctx, "[Info] Initialising...\n");

    if (SerialInit(COM1, BAUDDIV_38400) == OKAY)
    {
        SerialWriteString(COM1, "(COM1) [Info] RadianceOS 2.0 on COM1.\r\n");

        debug_write(ft_ctx, "[Info] COM1 available\n");
    }
    else
    {
        debug_write(ft_ctx, "[Warn] Serial port COM1 could not be initialised.\n");
    }

    InitialiseSMP();

    debug_write(ft_ctx, "[Good] Initialised SMP\n");

    debug_write(ft_ctx, "[Info] Checking COM ports\n[Info] Ports available: ");

    if(COM1Init()) debug_write(ft_ctx, "COM1 ");
    if(COM2Init()) debug_write(ft_ctx, "COM2 ");
    if(COM3Init()) debug_write(ft_ctx, "COM3 ");
    if(COM4Init()) debug_write(ft_ctx, "COM4 ");
    if(COM5Init()) debug_write(ft_ctx, "COM5 ");
    if(COM6Init()) debug_write(ft_ctx, "COM6 ");
    if(COM7Init()) debug_write(ft_ctx, "COM7 ");
    if(COM8Init()) debug_write(ft_ctx, "COM8 ");

    debug_write(ft_ctx, "\n");

    // We're done, just hang...
    hcf();
}