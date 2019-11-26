#include "stdafx.h"
//#include "Character2D.h"
#include "Input_State.h"
#include "Keyboard.h"

Keyboard::Keyboard () {}

Keyboard::~Keyboard () {}

void Keyboard::get_state ()
  {
  // Check the high bit to see if the key is down or not.

  current_input.left = GetAsyncKeyState (VK_LEFT) & 0x8000;
  current_input.right = GetAsyncKeyState (VK_RIGHT) & 0x8000;
  current_input.up = GetAsyncKeyState (VK_UP) & 0x8000;
  current_input.down = GetAsyncKeyState (VK_DOWN) & 0x8000;

  current_input.escape = GetAsyncKeyState (VK_ESCAPE) & 0x8000;
  }
