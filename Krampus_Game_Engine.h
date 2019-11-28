#pragma once

#include "Character2D.h"
#include "Graphics_Info.h"
#include "Keyboard.h"
#include "Menu.h"
#include "Photon.h"
#include "Scroller.h"
#include "Timing.h"

class Krampus_Game_Engine
  {
  public:

  Krampus_Game_Engine ();
  Krampus_Game_Engine (int screen_width, int screen_height);
  ~Krampus_Game_Engine ();
  void Init (HWND Window, Graphics_Info graphics);
  void Main_Loop ();
  void Render ();

  Menu menu;
    
  private:

  HWND Window;
  Photon photon;
  Timing timer;
  Character2D player;
  Scroller scroll;
  Keyboard keyboard;
  Graphics_Info graphics;

  HBITMAP background_bitmap;
  Bitmap player_bitmap;

  int screen_width, screen_height;
  };
