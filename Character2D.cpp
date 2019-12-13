#include "stdafx.h"

#include "Bitmap.h"
#include "Character2D.h"
#include "Input_State.h"
#include "Keyboard.h"
#include "Scroller.h"

Character2D::Character2D ()
  {
  Set_Defaults ();
  }

Character2D::Character2D (int ID, int character_width, int character_height, bool Controllable)
  {
  Set_Defaults ();
  width = character_width;
  height = character_height;
  controllable = Controllable;
  }

Character2D::Character2D (int ID, Bitmap loaded_bitmap, bool Controllable)
  {
  Set_Defaults ();
  bitmap = &loaded_bitmap;
  bitmap->get_size (bitmap->sprite, width, height);
  controllable = Controllable;
  }

Character2D::Character2D (int ID, Bitmap &loaded_bitmap, int character_width, int character_height, bool Controllable)
  {
  Set_Defaults ();
  bitmap = &loaded_bitmap;
  width = character_width;
  height = character_height;
  controllable = Controllable;
  spritesheet = true;
  }

Character2D::~Character2D () {}

void Character2D::Set_Defaults ()
  {
  x = 200;
  y = 200;
  move_speed = 1;
  spritesheet = false;
  }

void Character2D::Update (Input_State input, Scroller &scroll)
  {
  //if (controllable) handle_keyboard (input, scroll);
  position_rect ();
  }

void Character2D::position_rect ()
  {
  render_rect.left = x - width / 2;
  render_rect.right = x + width / 2;
  render_rect.top = y - height;
  render_rect.bottom = y;
  }

//void Character2D::handle_keyboard (Input_State input, Scroller &scroll)
//  {
//  }

void Character2D::set_position (int X, int Y)
  {
  x = X;
  y = Y;
  }
