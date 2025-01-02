#include <vector>
#include <windows.h>
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) { //mwindow handle, what type of message is being sent, wparam and lparam are message specific info(like width/height)
    switch (uMsg) {
        case WM_DESTROY: //if destroy message sent, destroy
            PostQuitMessage(0);
            return 0;
        default: //all other cases
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    // register window class, setup
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"MainWindowClass";
    RegisterClass(&wc);
    // create window
    HWND hwnd = CreateWindowEx(0, L"MainWindowClass",L"Win32 API GUI",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,nullptr,nullptr,hInstance,nullptr);
    if (hwnd == nullptr) { //check for failure
        return 0;
    }


    //show, update window
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    //message loop
    MSG msg = {};
    while (GetMessage(&msg,nullptr,0,0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg); //send to windowproc
    }

    //return exit code if successful
    return (int) msg.wParam;
}
