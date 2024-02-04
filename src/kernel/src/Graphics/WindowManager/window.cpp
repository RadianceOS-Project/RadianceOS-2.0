#include "window.h"
class WindowManager::Window {
public:
    int associated_process = -1;
    char* WindowTitle = "";

    int x = 0;
    int y = 0;

    int width = 800;
    int height = 400;

    int minwidth = 800;
    int minheight = 400;
    int maxwidth = -1;
    int maxheight = -1;

    int id = 0;

    int Window::GetAssociatedProcess() { return this->associated_process; }
    char* Window::GetWindowTitle() { return this->WindowTitle; }
    int Window::GetX() { return this->x; }
    int Window::GetY() { return this->y; }
    int Window::GetWidth() { return this->width; }
    int Window::GetHeight() { return this->height; }
    int Window::GetMinWidth() { return this->minwidth; }
    int Window::GetMinHeight() { return this->minheight; }
    int Window::GetMaxWidth() { return this->maxwidth; }
    int Window::GetMaxHeight() { return this->maxheight; }
    int Window::GetWindowId() { return this->id; }

    void Window::AssignProcess(int process) {
        // Don't reassign
        if(associated_process == -1)  associated_process = process;
    }

    void Window::DeAssignProcess() {
        // Simply remove the assigned process (So it lets you reassign)
        associated_process = -1;
    }

    void Window::Initialise(int id, char* WindowTitle, int x, int y, int width, int height) {
        // Since no process needs to be instantly assigned, there is no point.

        this->WindowTitle = WindowTitle;
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    void Window::RedrawWindowFrame() {
        // This is for redrawing the window frame, for moving and stuff,
        // but we need to redraw what's behind it first.
    }

    void Window::MoveWindow(int x, int y) {
        if(x < 0) x = 0;
        if(y < 0) y = 0;

        // Some checks for if it's out side of the biggest part
        // x + width = Relative ending x position
        // y + height = Relative ending y position

        this->x = x;
        this->y = y;

        RedrawWindowFrame();
    }

    void Window::ResizeWindow(int width, int height) {
        if(width < minwidth) width = minwidth;
        if(height < minheight) height = minheight;

        if(width > maxwidth && maxwidth != -1) width = maxwidth;
        if(width > maxheight && maxheight != -1) height = maxheight;

        this->width = width;
        this->height = height;

        MoveWindow(x, y); // This usualy triggers a re-render and will move the window if it goes out view
    }
};