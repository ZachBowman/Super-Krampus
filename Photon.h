#pragma once

#include "Bitmap.h"
#include "Linked_List.h"
#include "Player2D.h"
#include "resource.h"
#include "Scroller.h"
#include "Timing.h"

class Photon
  {
  public:
  
  Photon ();
  void Init (HWND Window);
  void Finish_Frame ();
  void load_bitmap (HBITMAP &bitmap, LPCWSTR path);
  HBITMAP load_bitmap (LPCWSTR path);
  void draw_rectangle (HDC, int, int, int, int, HBRUSH);
  void draw_debug (HDC destination, Timing timer);
  void draw_bitmap (HBITMAP bitmap, HDC destination, int x, int y, int width, int height);
  void get_client_screen_size (HWND Window, int &width, int &height);

  int window_width;
  int window_height;
  int screen_width;
  int screen_height;
  int small_width;
  int small_height;
  int background_width;
  int background_height;

  HDC hdc;

  HDC hdc_frame_buffer;  // Source buffer for entire frame blitting
  HBITMAP bitmap_frame_buffer;

  HDC hdc_temp;          // Source buffer for individual sprite blitting
  //Linked_List<HDC> hdc_layers;  // Buffers for the various sprite layers

  HDC hdc_layer0, hdc_layer1;
  HBITMAP bitmap_layer0, bitmap_layer1;
    
  private:

  COLORREF color_red = RGB (192, 0, 0);
  COLORREF color_yellow = RGB (224, 224, 0);
  COLORREF color_green = RGB (0, 192, 0);
  COLORREF color_blue = RGB (0, 0, 192);
  COLORREF color_black = RGB (0, 0, 0);
  COLORREF color_white = RGB (255, 255, 255);
  COLORREF color_light_grey = RGB (192, 192, 192);

  HBRUSH brush_red = CreateSolidBrush (color_red);
  HBRUSH brush_yellow = CreateSolidBrush (color_yellow);
  HBRUSH brush_green = CreateSolidBrush (color_green);
  HBRUSH brush_blue = CreateSolidBrush (color_blue);
  HBRUSH brush_black = CreateSolidBrush (color_black);
  HBRUSH brush_white = CreateSolidBrush (color_white);
  HBRUSH brush_light_grey = CreateSolidBrush (color_light_grey);
  };
