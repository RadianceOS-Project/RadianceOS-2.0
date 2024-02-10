#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <limine.h>
#include <flanterm/flanterm.h>
#include <flanterm/backends/fb.h>

#include <hardware/hardwareutils.h>

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

void debug_write(void* ft_ctx, const char msg[]) {
    flanterm_write(ft_ctx, msg, sizeof(msg));
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

    //ft_ctx->clear(ft_ctx, true);

    debug_write(ft_ctx, "RadianceOS 2.0 - Boot Manager\n\n");

    debug_write(ft_ctx, "Initialising...\n");

    InitialiseSMP();

    for (size_t i = 0; i < 100000; i++)
    {
        const char msgf[] = "Line";

        flanterm_write(ft_ctx, msgf, sizeof(msgf));
    }

    const char msgg[] = "End\n";

    flanterm_write(ft_ctx, msgg, sizeof(msgg));

    debug_write(ft_ctx, "Initialised SMP\n");

    // We're done, just hang...
    hcf();
}