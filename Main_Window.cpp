// Main Window

#include "stdafx.h"

#include <sstream>
#include <string>
#include <vector>
#include <windows.h>

#include "Debug.h"
#include "Keyboard.h"
#include "Krampus_Game_Engine.h"
#include "Photon.h"
#include "Character2D.h"
#include "Timing.h"
#include "Bitmap.h"

#define MAX_LOADSTRING 100

int window_width = 396;
int window_height = 224;
bool Exit = false;

HWND Window;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

Krampus_Game_Engine game_engine (window_width, window_height);

ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
  {
  UNREFERENCED_PARAMETER (hPrevInstance);
  UNREFERENCED_PARAMETER (lpCmdLine);

  // Initialize global strings
  LoadStringW (hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
  LoadStringW (hInstance, IDC_PHOTON, szWindowClass, MAX_LOADSTRING);
  MyRegisterClass (hInstance);

  // Perform application initialization:
  if (!InitInstance (hInstance, nCmdShow))
    {
    return FALSE;
    }

  HACCEL hAccelTable = LoadAccelerators (hInstance, MAKEINTRESOURCE (IDC_PHOTON));
  MSG msg;

  game_engine.Init (Window);
  
  // Main message loop:
  while (!Exit)
    {
    while (PeekMessage (&msg, nullptr, 0, 0, PM_REMOVE))
      {
      DispatchMessage (&msg);
      }
    game_engine.Main_Loop ();
    }

  return TRUE;
  }

// Registers the window class.
ATOM MyRegisterClass (HINSTANCE hInstance)
  {
  WNDCLASSEXW wcex;

  wcex.cbSize = sizeof (WNDCLASSEX);
  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = WndProc;
  wcex.cbClsExtra = 0;
  wcex.cbWndExtra = 0;
  wcex.hInstance = hInstance;
  wcex.hIcon = LoadIcon (hInstance, MAKEINTRESOURCE (IDI_PHOTON));
  wcex.hCursor = LoadCursor (nullptr, IDC_ARROW);
  wcex.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
  wcex.lpszMenuName = MAKEINTRESOURCEW (IDC_PHOTON);
  wcex.lpszClassName = szWindowClass;
  wcex.hIconSm = LoadIcon (wcex.hInstance, MAKEINTRESOURCE (IDI_SMALL));

  return RegisterClassExW (&wcex);
  }

BOOL InitInstance (HINSTANCE hInstance, int nCmdShow)
  {
  Window = CreateWindowW (szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, 0, window_width, window_height, nullptr, nullptr, hInstance, nullptr);

  if (!Window) return FALSE;

  SetMenu (Window, NULL);
  ShowWindow (Window, nCmdShow);
  UpdateWindow (Window);

  return TRUE;
  }

// Processes messages for the main window.
LRESULT CALLBACK WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
  {
  switch (message)
    {
      case WM_DESTROY:
        Exit = true;
        PostQuitMessage (0);
        break;

      default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
  return 0;
  }
