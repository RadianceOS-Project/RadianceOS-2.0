#include <window.h>
class WindowManager::Window {
public:
    int associated_process = -1;
    char* WindowTitle = "";

    int x = 0;
    int y = 0;

    int width = 0;
    int height = 0;

    int id = 0;

    void Window::AssignProcess(int process) {
        // Don't reassign
        if(associated_process == -1)  associated_process = process;
    };

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
};