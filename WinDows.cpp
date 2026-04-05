#include<windows.h> //thu vien WindowAPI

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg,WPARAM wParam, LPARAM lParam){
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd,uMsg,wParam,lParam);
}
int WINAPI WinMain(HINSTANCE hInstanse, HINSTANCE, LPSTR, int nCmdShow){
    const char CLASS_NAME[] = "LibraryManager";
    WNDCLASSA wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstanse;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClassA(&wc);

    HWND hwnd = CreateWindowA(
        CLASS_NAME,
        "LibraryManager",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 500, NULL, NULL, hInstanse, NULL
    );

    if(hwnd == NULL){
        return 0;
    }
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}