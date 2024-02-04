#include <processes/process.h> 
class WindowManager {
public:
    class Window {
    public:
        void AssignProcess(int process);
        void DeAssignProces();
        void Initialise(int id, char* WindowTitle, int x, int y, int width, int height);
        void RedrawWindowFrame();
    };
};