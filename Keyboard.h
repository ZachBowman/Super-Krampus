#pragma once

//#include "Character2D.h"
#include "Input_State.h"

class Keyboard
  {
  public:

  Keyboard ();
  ~Keyboard ();
  void get_state();

  //Character2D *controlled_character;
  Input_State current_input, last_input;

  //bool left;
  //bool right;
  //bool up;
  //bool down;
  //bool escape;
  };
