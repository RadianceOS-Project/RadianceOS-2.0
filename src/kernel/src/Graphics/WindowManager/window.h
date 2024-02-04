#include <processes/process.h> 
class WindowManager {
public:
    class Window {
    public:
        int GetAssociatedProcess();
        char* GetWindowTitle();
        int GetX();
        int GetY();
        int GetWidth();
        int GetHeight();
        int GetMinWidth();
        int GetMinHeight();
        int GetMaxWidth();
        int GetMaxHeight();
        int GetWindowId();

        void AssignProcess(int process);
        void DeAssignProces();
        void Initialise(int id, char* WindowTitle, int x, int y, int width, int height);
        void RedrawWindowFrame();
        void MoveWindow(int x, int y);
        void ResizeWindow(int width, int height);
    };
};