#include "stdafx.h"
#include "Graphics_Info.h"

void Graphics_Info::calculate_scale_and_window_size ()
  {
  assert (game_view_width > 0);
  assert (game_view_height > 0);
  assert (pixel_scale > 0 || (window_width > 0 && window_height > 0));

  if (pixel_scale == 0) pixel_scale = window_height / game_view_height;
  if (window_width == 0) window_width = (game_view_width * pixel_scale) + expected_border_width;
  if (window_height == 0) window_height = (game_view_height * pixel_scale) + expected_border_height;
  }

void Graphics_Info::get_client_window_size (HWND Window)
  {
  RECT rect;
  GetClientRect (Window, &rect);
  client_width = rect.right - rect.left;
  client_height = rect.bottom - rect.top;
  }
