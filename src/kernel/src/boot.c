// The boot manager

#include <limine.h>
#include <stdbool.h>
#include <stddef.h>

#include <hardware/hardwareutils.h>

void __bootmgr_boot(bool debug, struct flanterm_context *ft_ctx, void* framebuffer) {
    if(ft_ctx == NULL && framebuffer == NULL);
    else {
        ft_ctx->clear(ft_ctx, true); // Clear screen
    }
}