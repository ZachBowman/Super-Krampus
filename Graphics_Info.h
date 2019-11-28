#pragma once
#ifndef GRAPHICS_INFO_H
#define GRAPHICS_INFO_H

#include <assert.h>

class Graphics_Info
  {
  public:

  void calculate_scale_and_window_size ();
  void get_client_window_size (HWND Window);

  // Size of currently loaded and explorable game world in pixel units not including scale
  int game_world_width = 0;
  int game_world_height = 0;

  // Size of currently visible game in pixel units not including scale
  int game_view_width = 0;
  int game_view_height = 0;

  // Size of the window the game is running in
  int window_width = 0;
  int window_height = 0;

  // Size of the window's drawing area minus borders and menus
  int client_width = 0;
  int client_height = 0;

  // The ratio by which the game view will be stretched to fit the window
  float pixel_scale = 0;

  // The approximate amount of space the border and title of the window are expected to take up
  int expected_border_width = 16;
  int expected_border_height = 39;
  };

#endif
