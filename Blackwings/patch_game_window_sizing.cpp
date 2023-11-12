#include "pch.h"
#include <iostream>

#define WINDOW_THIN_BORDER_SIZE 8
#define WINDOW_TOP_BORDER_SIZE 30

#define WINDOW_LR_BORDER_PADDING (WINDOW_THIN_BORDER_SIZE * 2)
#define WINDOW_TB_BORDER_PADDING (WINDOW_TOP_BORDER_SIZE + WINDOW_THIN_BORDER_SIZE + 1)

#define LOWRES_W	800
#define LOWRES_H	600
#define MIDRES_W	1024
#define MIDRES_H	768
#define MIDRES2_W	1366
#define MIDRES2_H	768
#define HIRES_W		1440
#define HIRES_H		900
#define HIRES2_W	1600
#define HIRES2_H	900
#define ULTRARES_W	1680
#define ULTRARES_H	1050

typedef INT(CALLBACK* _CWvsApp__WindowProc_t)(
    HWND hWnd, 
    UINT uMsg, 
    WPARAM wParam, 
    LPARAM lParam
);

typedef VOID(__fastcall* _CWvsContext__SetScreenResolution_t)(
    void* pThis, 
    void* edx, 
    BOOL bLargeScreen, 
    BOOL bSave
);

INT nCurrentWidth = 800;
INT nCurrentHeight = 600;
BOOL bAllowResize = FALSE;
_CWvsApp__WindowProc_t              orig_CWvsApp__WindowProc                = reinterpret_cast<_CWvsApp__WindowProc_t>(0x009CC2B0);
_CWvsContext__SetScreenResolution_t orig_CWvsContext__SetScreenResolution   = reinterpret_cast<_CWvsContext__SetScreenResolution_t>(0x009CD0C0);;

INT hook_CWvsApp__WindowProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam
)
{
    switch (uMsg)
    {
        case WM_NCHITTEST:
        {
            LRESULT hit = DefWindowProc(hWnd, uMsg, wParam, lParam);
            if (hit == HTBOTTOMRIGHT) return hit;
            break;
        }
        case WM_SIZING:
        {
            LPRECT lpRect = reinterpret_cast<LPRECT>(lParam);

            INT nNewWidth = lpRect->right - lpRect->left - WINDOW_LR_BORDER_PADDING;
            INT nNewHeight = lpRect->bottom - lpRect->top - WINDOW_TB_BORDER_PADDING;

            if (!bAllowResize || nNewWidth < MIDRES_W - 25 || nNewHeight < MIDRES_H - 75)
            {
                lpRect->right = lpRect->left + LOWRES_W + WINDOW_LR_BORDER_PADDING;
                lpRect->bottom = lpRect->top + LOWRES_H + WINDOW_TB_BORDER_PADDING;
            }
            else if (nNewWidth < MIDRES2_W - 25 || nNewHeight < MIDRES2_H - 75)
            {
                lpRect->right = lpRect->left + MIDRES_W + WINDOW_LR_BORDER_PADDING;
                lpRect->bottom = lpRect->top + MIDRES_H + WINDOW_TB_BORDER_PADDING;
            }
            else if (nNewWidth < HIRES_W - 25 || nNewHeight < HIRES_H - 75)
            {
                lpRect->right = lpRect->left + MIDRES2_W + WINDOW_LR_BORDER_PADDING;
                lpRect->bottom = lpRect->top + MIDRES2_H + WINDOW_TB_BORDER_PADDING;
            }
            else if (nNewWidth < HIRES2_W - 25 || nNewHeight < HIRES2_H - 75)
            {
                lpRect->right = lpRect->left + HIRES_W + WINDOW_LR_BORDER_PADDING;
                lpRect->bottom = lpRect->top + HIRES_H + WINDOW_TB_BORDER_PADDING;
            }
            else if (nNewWidth < ULTRARES_W - 25 || nNewHeight < ULTRARES_H - 75)
            {
                lpRect->right = lpRect->left + HIRES2_W + WINDOW_LR_BORDER_PADDING;
                lpRect->bottom = lpRect->top + HIRES2_H + WINDOW_TB_BORDER_PADDING;
            }
            else
            {
                lpRect->right = lpRect->left + ULTRARES_W + WINDOW_LR_BORDER_PADDING;
                lpRect->bottom = lpRect->top + ULTRARES_H + WINDOW_TB_BORDER_PADDING;
            }

            nNewWidth = lpRect->right - lpRect->left - WINDOW_LR_BORDER_PADDING;
            nNewHeight = lpRect->bottom - lpRect->top - WINDOW_TB_BORDER_PADDING;

            if (!bAllowResize) {
                nNewWidth = 800;
                nNewHeight = 600;
            }

            if (nCurrentWidth != nNewWidth || nCurrentHeight != nNewHeight)
            {
                nCurrentWidth = nNewWidth;
                nCurrentHeight = nNewHeight;

                Game::SetGameResolution(nCurrentWidth, nCurrentHeight);
            }
            break;
        }
    }

    return orig_CWvsApp__WindowProc(hWnd, uMsg, wParam, lParam);
}

VOID __fastcall hook_CWvsContext__SetScreenResolution(
    void* pThis,
    void* edx,
    BOOL bLargeScreen,
    BOOL bSave
) 
{
    bAllowResize = bLargeScreen;
    orig_CWvsContext__SetScreenResolution(pThis, edx, bLargeScreen, bSave);
}

VOID Game::SetGameResolution(INT nWidth, INT nHeight)
{
    *(BOOL*)(CWvsContext::GetInstance() + 0x41C4) = FALSE;

    Memory::Write<INT>(0x009CD138 + 1, nWidth);
    Memory::Write<INT>(0x009CD13D + 1, nHeight);

    hook_CWvsContext__SetScreenResolution(CWvsContext::GetInstance(), NULL, TRUE, TRUE);
}

VOID Patches::PatchGameWindowSizing()
{
    DetourAttach((PVOID*)&orig_CWvsApp__WindowProc, (PVOID)hook_CWvsApp__WindowProc);
    DetourAttach((PVOID*)&orig_CWvsContext__SetScreenResolution, (PVOID)hook_CWvsContext__SetScreenResolution);
}
