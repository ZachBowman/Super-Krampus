#pragma once

#include "Input_State.h"

class Menu
  {
  public:

  Menu ();
  ~Menu ();
  void handle_keyboard (Input_State input);

  bool exit = false;
  };
