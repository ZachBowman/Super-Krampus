#pragma once

#include "Bitmap.h"
#include "Input_State.h"
#include "Keyboard.h"
#include "Scroller.h"

class Character2D
  {
  public:

  Character2D ();
  Character2D (int player_width, int player_height);
  Character2D (Bitmap loaded_bitmap);
  Character2D (Bitmap &loaded_bitmap, int player_width, int player_height);
  ~Character2D ();
  void Set_Defaults ();
  void Update (Input_State input, Scroller &scroll);
  void set_position (int X, int Y);

  RECT render_rect;
  Bitmap *bitmap;

  int x;
  int y;
  int width;
  int height;
    
  private:

  void position_rect ();
  void handle_keyboard (Input_State input, Scroller &scroll);
  void move_left (Scroller &scroll);
  void move_right (Scroller &scroll);
  void move_up (Scroller &scroll);
  void move_down (Scroller &scroll);

  Keyboard keyboard;

  int move_speed;
  };
