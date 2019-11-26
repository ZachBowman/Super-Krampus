#include "stdafx.h"

#include "Bitmap.h"
#include "Keyboard.h"
#include "Character2D.h"
#include "Scroller.h"

Character2D::Character2D ()
  {
  Set_Defaults ();
  }

Character2D::Character2D (int player_width, int player_height)
  {
  Set_Defaults ();
  width = player_width;
  height = player_height;
  }

Character2D::Character2D (Bitmap loaded_bitmap)//(LPCWSTR sprite_path)
  {
  Set_Defaults ();
  //bitmap = Bitmap (sprite_path);
  bitmap = &loaded_bitmap;
  bitmap->get_size (width, height);
  }

Character2D::~Character2D () {}

void Character2D::Set_Defaults ()
  {
  x = 150;
  y = 150;
  move_speed = 2;
  }

// per frame
void Character2D::Get_Input ()
  {
  keyboard.get_state ();
  }

// per step
void Character2D::Update (Scroller &scroll)
  {
  handle_keyboard (scroll);
  position_rect ();
  }

void Character2D::position_rect ()
  {
  render_rect.left = x - width / 2;
  render_rect.right = x + width / 2;
  render_rect.top = y - height;
  render_rect.bottom = y;
  }

void Character2D::handle_keyboard (Scroller &scroll)
  {
  if (keyboard.left) move_left (scroll);
  if (keyboard.right) move_right (scroll);
  if (keyboard.up) move_up (scroll);
  if (keyboard.down) move_down (scroll);
  }

bool Character2D::check_for_exit ()
  {
  return keyboard.escape;
  }

void Character2D::move_left (Scroller &scroll)
  {
  x -= move_speed;

  // update scroll
  if (scroll.x + x < scroll.margin && scroll.x < scroll.max_scroll_x) scroll.x += move_speed;

  // collision detection
  if (scroll.x + x - (width / 2) < 0) x = width / 2;
  }

void Character2D::move_right (Scroller &scroll)
  {
  x += move_speed;

  // update scroll
  if (scroll.x + x > scroll.screen_width - scroll.margin && scroll.x > scroll.min_scroll_x) scroll.x -= move_speed;

  // collision detection
  if (scroll.x + x + (width / 2) > scroll.screen_width) x = scroll.screen_width - (width / 2) - scroll.x;
  }

void Character2D::move_up (Scroller &scroll)
  {
  y -= move_speed;

  // update scroll
  if (scroll.y + y - (height / 2) < scroll.margin && scroll.y < scroll.max_scroll_y) scroll.y += move_speed;

  // collision detection
  if (scroll.y + y - height < 0) y = height;
  }

void Character2D::move_down (Scroller &scroll)
  {
  y += move_speed;

  // update scroll
  if (scroll.y + y - (height / 2) > scroll.screen_height - scroll.margin && scroll.y > scroll.min_scroll_y) scroll.y -= move_speed;

  // collision detection
  if (scroll.y + y > scroll.screen_height) y = scroll.screen_height - scroll.y;
  }

void Character2D::set_position (int X, int Y)
  {
  x = X;
  y = Y;
  }