#include "stdafx.h"

#include "Character_Input_System.h"
#include "Character2D.h"
#include "Keyboard.h"
#include "Linked_List.h"
#include "Scroller.h"

Character_Input_System::Character_Input_System () {}

Character_Input_System::~Character_Input_System () {}

void Character_Input_System::Update_All (Linked_List<Character2D> &characters, Scroller &scroll)
  {
  keyboard.get_state ();
  Input_State input = keyboard.current_input;

  for (int c = 0; c < characters.count; c += 1)
    {
    Character2D &character = characters.get_data (c);

    if (character.controllable)
      {
      update_character (character, input, scroll);
      }
    }
  }

void Character_Input_System::update_character (Character2D &character, Input_State input, Scroller &scroll)
  {
  if (input.left) move_left (character, scroll);
  if (input.right) move_right (character, scroll);
  if (input.up) move_up (character, scroll);
  if (input.down) move_down (character, scroll);
  }

void Character_Input_System::move_left (Character2D &character, Scroller &scroll)
  {
  character.x -= character.move_speed;

  // update scroll
  if (character.controllable && scroll.x + character.render_rect.left < scroll.margin)
    {
    scroll.x += character.move_speed;
    if (scroll.x > scroll.max_scroll_x) scroll.x = scroll.max_scroll_x;
    }

  // collision detection
  if (scroll.x + character.x - (character.width / 2) < 0) character.x = character.width / 2;
  }

void Character_Input_System::move_right (Character2D &character, Scroller &scroll)
  {
  character.x += character.move_speed;

  // update scroll
  if (character.controllable && scroll.x + character.render_rect.right > scroll.game_view_width - scroll.margin)
    {
    scroll.x -= character.move_speed;
    if (scroll.x < scroll.min_scroll_x) scroll.x = scroll.min_scroll_x;
    }

  // collision detection
  if (character.x + (character.width / 2) > scroll.game_world_width) character.x = scroll.game_world_width - (character.width / 2);
  }

void Character_Input_System::move_up (Character2D &character, Scroller &scroll)
  {
  character.y -= character.move_speed;

  // update scroll
  if (character.controllable && scroll.y + character.render_rect.top < scroll.margin)
    {
    scroll.y += character.move_speed;
    if (scroll.y > scroll.max_scroll_y) scroll.y = scroll.max_scroll_y;
    }

  // collision detection
  if (character.y - character.height < 0) character.y = character.height;
  }

void Character_Input_System::move_down (Character2D &character, Scroller &scroll)
  {
  character.y += character.move_speed;

  // update scroll
  if (character.controllable && scroll.y + character.render_rect.bottom > scroll.game_view_height - scroll.margin)
    {
    scroll.y -= character.move_speed;
    if (scroll.y < scroll.min_scroll_y) scroll.y = scroll.min_scroll_y;
    }

  // collision detection
  if (character.y > scroll.game_world_height) character.y = scroll.game_world_height;
  }
