#pragma once

#include "Bitmap.h"
#include "Input_State.h"
#include "Keyboard.h"
#include "Scroller.h"

class Character2D
  {
  public:

  Character2D ();
  Character2D (int ID, int character_width, int character_height, bool Controllable);
  Character2D (int ID, Bitmap loaded_bitmap, bool Controllable);
  Character2D (int ID, Bitmap &loaded_bitmap, int character_width, int character_height, bool Controllable);
  ~Character2D ();
  void Set_Defaults ();
  void Update (Input_State input, Scroller &scroll);
  void set_position (int X, int Y);

  int id;

  RECT render_rect;
  Bitmap *bitmap;

  int x;
  int y;
  int width;
  int height;

  bool controllable;
  bool spritesheet;
    
  int move_speed;
  
  private:

  void position_rect ();
  //void handle_keyboard (Input_State input, Scroller &scroll);

  Keyboard keyboard;
  };
