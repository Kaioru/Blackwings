#include "pch.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(
    HWND hWnd, 
    UINT msg, 
    WPARAM wParam, 
    LPARAM lParam
);

typedef HRESULT(APIENTRY* _IDirect3DDevice9__Reset_t)(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
typedef HRESULT(APIENTRY* _IDirect3DDevice9__Present_t)(IDirect3DDevice9* pDevice, const RECT *pSourceRect, const RECT *pDestRect, HWND hDestWindowOverride, const RGNDATA *pDirtyRegion);
typedef HRESULT(APIENTRY* _IDirect3DDevice9__BeginScene_t)(IDirect3DDevice9* pDevice);
typedef HRESULT(APIENTRY* _IDirect3DDevice9__EndScene_t)(IDirect3DDevice9* pDevice);

BOOL bInitUI = FALSE;
HWND hWindow;

WNDPROC orig_WndProc;
_IDirect3DDevice9__Reset_t      orig_IDirect3DDevice9__Reset;
_IDirect3DDevice9__Present_t    orig_IDirect3DDevice9__Present;
_IDirect3DDevice9__BeginScene_t orig_IDirect3DDevice9__BeginScene;
_IDirect3DDevice9__EndScene_t   orig_IDirect3DDevice9__EndScene;

LRESULT WINAPI hook_WndProc(
    const HWND hWnd, 
    const UINT msg, 
    const WPARAM wParam,
    const LPARAM lParam
) {
    if (bInitUI && ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return TRUE;

    return CallWindowProc(orig_WndProc, hWnd, msg, wParam, lParam);
}

HRESULT APIENTRY hook_IDirect3DDevice9__Reset(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    if (bInitUI) {
        ImGui_ImplDX9_Shutdown();
        ImGui_ImplWin32_Shutdown();
        ImGui::DestroyContext();

        SetWindowLongPtr(hWindow, GWLP_WNDPROC, (LONG_PTR)orig_WndProc);
        bInitUI = FALSE;
        hWindow = NULL;
    }

    return orig_IDirect3DDevice9__Reset(pDevice, pPresentationParameters);
}


HRESULT APIENTRY hook_IDirect3DDevice9__Present(
    IDirect3DDevice9* pDevice, 
    const RECT* pSourceRect, 
    const RECT* pDestRect, 
    HWND hDestWindowOverride, 
    const RGNDATA* pDirtyRegion
)
{
    if (!bInitUI) {
        D3DDEVICE_CREATION_PARAMETERS params = {};

        pDevice->GetCreationParameters(&params);

        if (params.hFocusWindow) {
            hWindow = params.hFocusWindow;

            ImGui::CreateContext();
            ImGui::StyleColorsDark();

            ImGuiIO& io = ImGui::GetIO(); (void)io;

            io.IniFilename = nullptr;
            io.Fonts->AddFontDefault();

            ImGui_ImplWin32_Init(hWindow);
            ImGui_ImplDX9_Init(pDevice);

            orig_WndProc = (WNDPROC)SetWindowLongPtr(hWindow, GWLP_WNDPROC, (LONG_PTR)hook_WndProc);
            bInitUI = TRUE;
        }
    }

    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    // TODO
    // ImGui::ShowDemoWindow();

    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

    return orig_IDirect3DDevice9__Present(pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT APIENTRY hook_IDirect3DDevice9__BeginScene(IDirect3DDevice9* pDevice)
{
    return orig_IDirect3DDevice9__BeginScene(pDevice);
}

HRESULT APIENTRY hook_IDirect3DDevice9__EndScene(IDirect3DDevice9* pDevice)
{
    return orig_IDirect3DDevice9__EndScene(pDevice);
}

VOID Patches::PatchGameWindowUI()
{
    IDirect3D9* pD3D9 = Direct3DCreate9(D3D_SDK_VERSION);
    D3DPRESENT_PARAMETERS d3dParams = {};

    d3dParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dParams.hDeviceWindow = GetForegroundWindow();
    d3dParams.Windowed = (GetWindowLongPtr(d3dParams.hDeviceWindow, GWL_STYLE) & WS_POPUP) != 0 
        ? FALSE 
        : TRUE;

    IDirect3DDevice9* pDevice = nullptr;

    pD3D9->CreateDevice(
        D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        d3dParams.hDeviceWindow,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dParams,
        &pDevice
    );

    void** pTable = *reinterpret_cast<void***>(pDevice);

    orig_IDirect3DDevice9__Reset = (_IDirect3DDevice9__Reset_t)pTable[16];
    orig_IDirect3DDevice9__Present = (_IDirect3DDevice9__Present_t)pTable[17];
    //orig_IDirect3DDevice9__BeginScene = (_IDirect3DDevice9__BeginScene_t)pTable[41];
    orig_IDirect3DDevice9__EndScene = (_IDirect3DDevice9__EndScene_t)pTable[42];

    DetourAttach((PVOID*)&orig_IDirect3DDevice9__Reset, (PVOID)hook_IDirect3DDevice9__Reset);
    DetourAttach((PVOID*)&orig_IDirect3DDevice9__Present, (PVOID)hook_IDirect3DDevice9__Present);
    //DetourAttach((PVOID*)&orig_IDirect3DDevice9__BeginScene, (PVOID)hook_IDirect3DDevice9__BeginScene);
    DetourAttach((PVOID*)&orig_IDirect3DDevice9__EndScene, (PVOID)hook_IDirect3DDevice9__EndScene);

    pDevice->Release();
    pD3D9->Release();
}
