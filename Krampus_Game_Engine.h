#pragma once

#include "Character2D.h"
#include "Character_Controller.h"
#include "Character_Input_System.h"
#include "Graphics_Info.h"
#include "Keyboard.h"
#include "Linked_List.h"
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

  Linked_List<Character2D> characters;
  Character_Controller character_controller;
  Character_Input_System character_input_system;

  Scroller scroll;
  Keyboard keyboard;
  Graphics_Info graphics;

  HBITMAP background_bitmap;
  Bitmap player_bitmap;
  Bitmap badguy_test_bitmap;

  int screen_width, screen_height;
  };
