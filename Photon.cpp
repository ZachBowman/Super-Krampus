// Photon

#include "stdafx.h"

#include <assert.h>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>

#include "Debug.h"
#include "Keyboard.h"
#include "Photon.h"
#include "Character2D.h"
#include "Scroller.h"
#include "Timing.h"
#include "Bitmap.h"

Photon::Photon () {}

void Photon::Init (HWND Window)
  {
  get_client_screen_size (Window, screen_width, screen_height);

  hdc = GetDC (Window);

  hdc_frame_buffer = CreateCompatibleDC (hdc);
  bitmap_frame_buffer = CreateCompatibleBitmap (hdc, screen_width, screen_height);
  SelectObject (hdc_frame_buffer, bitmap_frame_buffer);

  hdc_temp = CreateCompatibleDC (hdc);

  //hdc_layers = Linked_List<HDC> ();

  hdc_layer0 = CreateCompatibleDC (hdc);
  bitmap_layer0 = CreateCompatibleBitmap (hdc, screen_width, screen_height);
  SelectObject (hdc_layer0, bitmap_layer0);

  hdc_layer1 = CreateCompatibleDC (hdc);
  bitmap_layer1 = CreateCompatibleBitmap (hdc, screen_width, screen_height);
  SelectObject (hdc_layer1, bitmap_layer1);
  }

void Photon::load_bitmap (HBITMAP &bitmap, LPCWSTR path)
  {
  bitmap = (HBITMAP) LoadImage (NULL, path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
  assert (bitmap != NULL);
  }

HBITMAP Photon::load_bitmap (LPCWSTR path)
  {
  HBITMAP bitmap = (HBITMAP) LoadImage (NULL, path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
  assert (bitmap != NULL);
  return bitmap;
  }

void Photon::draw_rectangle (HDC destination, int x1, int y1, int x2, int y2, HBRUSH brush)
  {
  RECT rect;
  SetRect (&rect, x1, y1, x2, y2);
  FillRect (destination, &rect, brush);
  }

void Photon::draw_debug (HDC destination, Timing timer)
  {
  int w = screen_width;
  Debug::text (destination, w - 120, 5, color_blue, "FPS: ", timer.frames_per_second);
  Debug::text (destination, w - 120, 25, color_blue, "MSPF: ", timer.milliseconds_per_frame);
  }

void Photon::draw_bitmap (HBITMAP bitmap, HDC destination, int x, int y, int width, int height)
  {
  BITMAP temp_bitmap;
  GetObject (bitmap, sizeof (temp_bitmap), &temp_bitmap);
  SelectObject (hdc_temp, bitmap);
  BitBlt (destination, x, y, temp_bitmap.bmWidth, temp_bitmap.bmHeight, hdc_temp, 0, 0, SRCCOPY);
  }

void Photon::Finish_Frame ()
  {
  BitBlt (hdc, 0, 0, screen_width, screen_height, hdc_frame_buffer, 0, 0, SRCCOPY);
  }

void Photon::get_client_screen_size (HWND Window, int &width, int &height)
  {
  RECT rect;
  GetClientRect (Window, &rect);
  width = rect.right - rect.left;
  height = rect.bottom - rect.top;
  }
