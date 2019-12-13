#pragma once

#include "Character2D.h"
#include "Keyboard.h"
#include "Linked_List.h"
#include "Scroller.h"

class Character_Input_System
  {
  public:

  Character_Input_System ();
  ~Character_Input_System ();

  void Update_All (Linked_List<Character2D> &characters, Scroller &scroll);
  void update_character (Character2D &character, Input_State input, Scroller &scroll);

  void move_left (Character2D &character, Scroller &scroll);
  void move_right (Character2D &character, Scroller &scroll);
  void move_up (Character2D &character, Scroller &scroll);
  void move_down (Character2D &character, Scroller &scroll);

  private:

  Keyboard keyboard;
  };
