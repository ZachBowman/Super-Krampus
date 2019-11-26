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
  Character2D (Bitmap loaded_bitmap);//(LPCWSTR sprite_path);
  ~Character2D ();
  void Set_Defaults ();
  void Update (Input_State input, Scroller &scroll);
  //void Get_Input ();
  void set_position (int X, int Y);

  RECT render_rect;
  Bitmap *bitmap;

  private:

  void position_rect ();
  void handle_keyboard (Input_State input, Scroller &scroll);
  //bool check_for_exit ();
  void move_left (Scroller &scroll);
  void move_right (Scroller &scroll);
  void move_up (Scroller &scroll);
  void move_down (Scroller &scroll);

  Keyboard keyboard;

  int x;
  int y;
  int width;
  int height;
  int move_speed;
  };
