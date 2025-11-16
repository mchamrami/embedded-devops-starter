#ifdef _WIN32
#include <windows.h>

extern int main(int argc, char** argv);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nShow) {
    return main(__argc, __argv);
}
#endif
