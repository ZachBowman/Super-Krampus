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

Character2D::Character2D (int player_width, int player_height)
  {
  Set_Defaults ();
  width = player_width;
  height = player_height;
  }

Character2D::Character2D (Bitmap loaded_bitmap)
  {
  Set_Defaults ();
  bitmap = &loaded_bitmap;
  bitmap->get_size (bitmap->sprite, width, height);
  }

Character2D::Character2D (Bitmap &loaded_bitmap, int player_width, int player_height)
  {
  Set_Defaults ();
  bitmap = &loaded_bitmap;
  width = player_width;
  height = player_height;
  }

Character2D::~Character2D () {}

void Character2D::Set_Defaults ()
  {
  x = 200;
  y = 200;
  move_speed = 1;
  }

void Character2D::Update (Input_State input, Scroller &scroll)
  {
  handle_keyboard (input, scroll);
  position_rect ();
  }

void Character2D::position_rect ()
  {
  render_rect.left = x - width / 2;
  render_rect.right = x + width / 2;
  render_rect.top = y - height;
  render_rect.bottom = y;
  }

void Character2D::handle_keyboard (Input_State input, Scroller &scroll)
  {
  if (input.left) move_left (scroll);
  if (input.right) move_right (scroll);
  if (input.up) move_up (scroll);
  if (input.down) move_down (scroll);
  }

void Character2D::move_left (Scroller &scroll)
  {
  x -= move_speed;

  // update scroll
  if (scroll.x + render_rect.left < scroll.margin)
    {
    scroll.x += move_speed;
    if (scroll.x > scroll.max_scroll_x) scroll.x = scroll.max_scroll_x;
    }

  // collision detection
  if (scroll.x + x - (width / 2) < 0) x = width / 2;
  }

void Character2D::move_right (Scroller &scroll)
  {
  x += move_speed;

  // update scroll
  if (scroll.x + render_rect.right > scroll.game_view_width - scroll.margin)
    {
    scroll.x -= move_speed;
    if (scroll.x < scroll.min_scroll_x) scroll.x = scroll.min_scroll_x;
    }

  // collision detection
  if (x + (width / 2) > scroll.game_world_width) x = scroll.game_world_width - (width / 2);
  }

void Character2D::move_up (Scroller &scroll)
  {
  y -= move_speed;

  // update scroll
  if (scroll.y + render_rect.top < scroll.margin)
    {
    scroll.y += move_speed;
    if (scroll.y > scroll.max_scroll_y) scroll.y = scroll.max_scroll_y;
    }

  // collision detection
  if (y - height < 0) y = height;
  }

void Character2D::move_down (Scroller &scroll)
  {
  y += move_speed;

  // update scroll
  if (scroll.y + render_rect.bottom > scroll.game_view_height - scroll.margin)
    {
    scroll.y -= move_speed;
    if (scroll.y < scroll.min_scroll_y) scroll.y = scroll.min_scroll_y;
    }

  // collision detection
  if (y > scroll.game_world_height) y = scroll.game_world_height;
  }

void Character2D::set_position (int X, int Y)
  {
  x = X;
  y = Y;
  }
