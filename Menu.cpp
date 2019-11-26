#include "stdafx.h"
#include "Input_State.h"
#include "Menu.h"

Menu::Menu () {}

Menu::~Menu () {}

void Menu::handle_keyboard (Input_State input)
  {
  if (input.escape) exit = true;
  }

