#include "Windows.h"

#include "resource.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    switch (Msg)
    {
    case WM_CLOSE:
        DestroyWindow(hWnd);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return (DefWindowProc(hWnd, Msg, wParam, lParam));
    }
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0; // Can be bitwise ORed later
    wc.lpfnWndProc = (WNDPROC)WndProc;
    wc.cbClsExtra = 0; // Usually there is no need in these two
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_NOTEPADICON));
    wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_NOTEPADICON));
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = MAKEINTRESOURCE(IDR_NOTEPADMENU);
    wc.lpszClassName = "MainClass";
    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Failed to register the window class.", "Error", MB_OK | MB_ICONERROR);
        return 0;
    }

    HWND hWnd;
    hWnd = CreateWindowEx(WS_EX_CLIENTEDGE, "MainClass", "Windows Notepad", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
                          CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);
    if (hWnd == NULL)
    {
        MessageBox(NULL, "Failed to create a window.", "Error", MB_OK | MB_ICONERROR);
        return 0;
    }
    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

    MSG Msg;
    while (GetMessage(&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}