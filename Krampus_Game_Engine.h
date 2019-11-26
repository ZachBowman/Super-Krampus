#pragma once

#include "Photon.h"
#include "Player2D.h"
#include "Scroller.h"
#include "Timing.h"

class Krampus_Game_Engine
  {
  public:

  Krampus_Game_Engine ();
  Krampus_Game_Engine (int screen_width, int screen_height);
  ~Krampus_Game_Engine ();
  void Init (HWND Window);
  void Main_Loop ();
  void Render ();

  private:

  HWND Window;
  Photon photon;
  Timing timer;
  Player2D player;
  Scroller scroll;

  HBITMAP background_bitmap;
  Bitmap player_bitmap;

  int screen_width, screen_height;
  };
