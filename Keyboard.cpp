#include "stdafx.h"
#include "Keyboard.h"

Keyboard::Keyboard () {}

Keyboard::~Keyboard () {}

void Keyboard::get_state ()
  {
  // Check the high bit to see if the key is down or not.

  left = GetAsyncKeyState (VK_LEFT) & 0x8000;
  right = GetAsyncKeyState (VK_RIGHT) & 0x8000;
  up = GetAsyncKeyState (VK_UP) & 0x8000;
  down = GetAsyncKeyState (VK_DOWN) & 0x8000;

  escape = GetAsyncKeyState (VK_ESCAPE) & 0x8000;
  }
