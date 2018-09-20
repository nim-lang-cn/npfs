/* nuklear - 1.32.0 - public domain */
#define COBJMACROS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <d3d11.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define MAX_VERTEX_BUFFER 512 * 1024
#define MAX_INDEX_BUFFER 128 * 1024

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_D3D11_IMPLEMENTATION
#include "../../nuklear.h"
#include "nuklear_d3d11.h"

/* ===============================================================
 *
 *                          EXAMPLE
 *
 * ===============================================================*/
/* This are some code examples to provide a small overview of what can be
 * done with this library. To try out an example uncomment the include
 * and the corresponding function. */
 #define UNUSED(a) (void)a
 #define MIN(a,b) ((a) < (b) ? (a) : (b))
 #define MAX(a,b) ((a) < (b) ? (b) : (a))
 #define LEN(a) (sizeof(a)/sizeof(a)[0])

/*#include "../style.c"*/
/*#include "../calculator.c"*/
/*#include "../overview.c"*/
/*#include "../node_editor.c"*/

/* ===============================================================
 *
 *                          DEMO
 *
 * ===============================================================*/
static IDXGISwapChain *swap_chain;
static ID3D11Device *device;
static ID3D11DeviceContext *context;
static ID3D11RenderTargetView* rt_view;

static void
set_swap_chain_size(int width, int height)
{
    ID3D11Texture2D *back_buffer;
    D3D11_RENDER_TARGET_VIEW_DESC desc;
    HRESULT hr;

    if (rt_view)
        ID3D11RenderTargetView_Release(rt_view);

    ID3D11DeviceContext_OMSetRenderTargets(context, 0, NULL, NULL);

    hr = IDXGISwapChain_ResizeBuffers(swap_chain, 0, width, height, DXGI_FORMAT_UNKNOWN, 0);
    if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET || hr == DXGI_ERROR_DRIVER_INTERNAL_ERROR)
    {
        /* to recover from this, you'll need to recreate device and all the resources */
        MessageBoxW(NULL, L"DXGI device is removed or reset!", L"Error", 0);
        exit(0);
    }
    assert(SUCCEEDED(hr));

    memset(&desc, 0, sizeof(desc));
    desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;

    hr = IDXGISwapChain_GetBuffer(swap_chain, 0, &IID_ID3D11Texture2D, &back_buffer);
    assert(SUCCEEDED(hr));

    hr = ID3D11Device_CreateRenderTargetView(device, (ID3D11Resource *)back_buffer, &desc, &rt_view);
    assert(SUCCEEDED(hr));

    ID3D11Texture2D_Release(back_buffer);
}

static LRESULT CALLBACK
WindowProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_SIZE:
        if (swap_chain)
        {
            int width = LOWORD(lparam);
            int height = HIWORD(lparam);
            set_swap_chain_size(width, height);
            nk_d3d11_resize(context, width, height);
        }
        break;
    }

    if (nk_d3d11_handle_event(wnd, msg, wparam, lparam))
        return 0;

    return DefWindowProcW(wnd, msg, wparam, lparam);
}

int main(void)
{
    struct nk_context *ctx;
    struct nk_color background;

    WNDCLASSW wc;
    RECT rect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    DWORD style = WS_OVERLAPPEDWINDOW;
    DWORD exstyle = WS_EX_APPWINDOW;
    HWND wnd;
    int running = 1;
    HRESULT hr;
    D3D_FEATURE_LEVEL feature_level;
    DXGI_SWAP_CHAIN_DESC swap_chain_desc;

    /* Win32 */
    memset(&wc, 0, sizeof(wc));
    wc.style = CS_DBLCLKS;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandleW(0);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = L"NuklearWindowClass";
    RegisterClassW(&wc);

    AdjustWindowRectEx(&rect, style, FALSE, exstyle);

    wnd = CreateWindowExW(exstyle, wc.lpszClassName, L"Nuklear Demo",
        style | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,
        rect.right - rect.left, rect.bottom - rect.top,
        NULL, NULL, wc.hInstance, NULL);

    /* D3D11 setup */
    memset(&swap_chain_desc, 0, sizeof(swap_chain_desc));
    swap_chain_desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swap_chain_desc.BufferDesc.RefreshRate.Numerator = 60;
    swap_chain_desc.BufferDesc.RefreshRate.Denominator = 1;
    swap_chain_desc.SampleDesc.Count = 1;
    swap_chain_desc.SampleDesc.Quality = 0;
    swap_chain_desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swap_chain_desc.BufferCount = 1;
    swap_chain_desc.OutputWindow = wnd;
    swap_chain_desc.Windowed = TRUE;
    swap_chain_desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    swap_chain_desc.Flags = 0;
    if (FAILED(D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE,
        NULL, 0, NULL, 0, D3D11_SDK_VERSION, &swap_chain_desc,
        &swap_chain, &device, &feature_level, &context)))
    {
        /* if hardware device fails, then try WARP high-performance
           software rasterizer, this is useful for RDP sessions */
        hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_WARP,
            NULL, 0, NULL, 0, D3D11_SDK_VERSION, &swap_chain_desc,
            &swap_chain, &device, &feature_level, &context);
        assert(SUCCEEDED(hr));
    }
    set_swap_chain_size(WINDOW_WIDTH, WINDOW_HEIGHT);

    /* GUI */
    ctx = nk_d3d11_init(device, WINDOW_WIDTH, WINDOW_HEIGHT, MAX_VERTEX_BUFFER, MAX_INDEX_BUFFER);
    /* Load Fonts: if none of these are loaded a default font will be used  */
    /* Load Cursor: if you uncomment cursor loading please hide the cursor */
    {struct nk_font_atlas *atlas;
    nk_d3d11_font_stash_begin(&atlas);
    /*struct nk_font *droid = nk_font_atlas_add_from_file(atlas, "../../extra_font/DroidSans.ttf", 14, 0);*/
    /*struct nk_font *robot = nk_font_atlas_add_from_file(atlas, "../../extra_font/Roboto-Regular.ttf", 14, 0);*/
    /*struct nk_font *future = nk_font_atlas_add_from_file(atlas, "../../extra_font/kenvector_future_thin.ttf", 13, 0);*/
    /*struct nk_font *clean = nk_font_atlas_add_from_file(atlas, "../../extra_font/ProggyClean.ttf", 12, 0);*/
    /*struct nk_font *tiny = nk_font_atlas_add_from_file(atlas, "../../extra_font/ProggyTiny.ttf", 10, 0);*/
    /*struct nk_font *cousine = nk_font_atlas_add_from_file(atlas, "../../extra_font/Cousine-Regular.ttf", 13, 0);*/
    nk_d3d11_font_stash_end();
    /*nk_style_load_all_cursors(ctx, atlas->cursors);*/
    /*nk_style_set_font(ctx, &droid->handle)*/;}

    /* style.c */
    /*set_style(ctx, THEME_WHITE);*/
    /*set_style(ctx, THEME_RED);*/
    /*set_style(ctx, THEME_BLUE);*/
    /*set_style(ctx, THEME_DARK);*/

    background = nk_rgb(28,48,62);
    while (running)
    {
        /* Input */
        MSG msg;
        nk_input_begin(ctx);
        while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                running = 0;
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
        nk_input_end(ctx);

        /* GUI */
        if (nk_begin(ctx, "Demo", nk_rect(50, 50, 230, 250),
            NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|
            NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
        {
            enum {EASY, HARD};
            static int op = EASY;
            static int property = 20;

            nk_layout_row_static(ctx, 30, 80, 1);
            if (nk_button_label(ctx, "button"))
                fprintf(stdout, "button pressed\n");
            nk_layout_row_dynamic(ctx, 30, 2);
            if (nk_option_label(ctx, "easy", op == EASY)) op = EASY;
            if (nk_option_label(ctx, "hard", op == HARD)) op = HARD;
            nk_layout_row_dynamic(ctx, 22, 1);
            nk_property_int(ctx, "Compression:", 0, &property, 100, 10, 1);

            nk_layout_row_dynamic(ctx, 20, 1);
            nk_label(ctx, "background:", NK_TEXT_LEFT);
            nk_layout_row_dynamic(ctx, 25, 1);
            if (nk_combo_begin_color(ctx, background, nk_vec2(nk_widget_width(ctx),400))) {
                nk_layout_row_dynamic(ctx, 120, 1);
                background = nk_color_picker(ctx, background, NK_RGBA);
                nk_layout_row_dynamic(ctx, 25, 1);
                background.r = (nk_byte)nk_propertyi(ctx, "#R:", 0, background.r, 255, 1,1);
                background.g = (nk_byte)nk_propertyi(ctx, "#G:", 0, background.g, 255, 1,1);
                background.b = (nk_byte)nk_propertyi(ctx, "#B:", 0, background.b, 255, 1,1);
                background.a = (nk_byte)nk_propertyi(ctx, "#A:", 0, background.a, 255, 1,1);
                nk_combo_end(ctx);
            }
        }
        nk_end(ctx);

        /* -------------- EXAMPLES ---------------- */
        /*calculator(ctx);*/
        /*overview(ctx);*/
        /*node_editor(ctx);*/
        /* ----------------------------------------- */

        {/* Draw */
        float bg[4];
        nk_color_fv(bg, background);
        ID3D11DeviceContext_ClearRenderTargetView(context, rt_view, bg);
        ID3D11DeviceContext_OMSetRenderTargets(context, 1, &rt_view, NULL);
        nk_d3d11_render(context, NK_ANTI_ALIASING_ON);
        hr = IDXGISwapChain_Present(swap_chain, 1, 0);
        if (hr == DXGI_ERROR_DEVICE_RESET || hr == DXGI_ERROR_DEVICE_REMOVED) {
            /* to recover from this, you'll need to recreate device and all the resources */
            MessageBoxW(NULL, L"D3D11 device is lost or removed!", L"Error", 0);
            break;
        } else if (hr == DXGI_STATUS_OCCLUDED) {
            /* window is not visible, so vsync won't work. Let's sleep a bit to reduce CPU usage */
            Sleep(10);
        }
        assert(SUCCEEDED(hr));}
    }

    ID3D11DeviceContext_ClearState(context);
    nk_d3d11_shutdown();
    ID3D11ShaderResourceView_Release(rt_view);
    ID3D11DeviceContext_Release(context);
    ID3D11Device_Release(device);
    IDXGISwapChain_Release(swap_chain);
    UnregisterClassW(wc.lpszClassName, wc.hInstance);
    return 0;
}
