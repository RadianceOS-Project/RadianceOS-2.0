#include <Graphics/ConsoleMode/ConsoleMode.h>
#include <VideoUtils/videoutils.h>

unsigned loop = 0;
int PromptFullRerender = 0;

void _ConsoleMode_loop(void) {
    loop++;

    if(PromptFullRerender == 1 || loop == 1) __Rerender_Base(); PromptFullRerender = 0;
}

void __Rerender_Base(void) {
    // Obviously we want to give them some indication of to what to do and other info
    // such as the time and date, so we can reserve the bottom line and colour it
    // with a grey colour.

    DrawFilledRectangle(0, GetHeight() - 30, GetWidth(), 30, 0x9F9F9F);
    DrawFilledRectangle(GetWidth() - 100, GetHeight() - 30, 100, 30, 0x7F7F7F);
}