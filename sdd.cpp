//  sdd.cpp

#include <windows.h>
#include <tchar.h>

HHOOK hHook;
LRESULT CALLBACK HookProc(int nCode, WPARAM wParam, LPARAM lParam){
    if(nCode >= 0){
        if(nCode == HCBT_ACTIVATE){
            SetDlgItemText((HWND)wParam, IDOK, _T("êiíªÇæÇﬂÇ≈Ç∑"));
        }
    }
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hCurInst, HINSTANCE hPrevInst, LPSTR lpsCmdLine, int nCmdShow){
    hHook = SetWindowsHookEx(WH_CBT, HookProc, NULL, GetCurrentThreadId());
    MessageBox(NULL, _T("êiíªÇ«Ç§Ç≈Ç∑Ç©ÅH"), _T("éøñ‚"),
        MB_ICONQUESTION | MB_SETFOREGROUND | MB_TOPMOST);
    //UnhookWindowsHookEx(hHook);
    return 0;
}
