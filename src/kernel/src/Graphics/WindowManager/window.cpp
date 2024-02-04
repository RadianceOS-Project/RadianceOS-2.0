#include <window.h>
class WindowManager::Window {
public:
    int associated_process = -1;
    void AssignProcess(int process) {
        // Don't reassign
        if(associated_process == -1)  associated_process = process;
    };
}