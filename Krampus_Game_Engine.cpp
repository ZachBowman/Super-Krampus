#include "stdafx.h"

#include "Character2D.h"
#include "Character_Controller.h"
#include "Character_Input_System.h"
#include "Graphics_Info.h"
#include "Keyboard.h"
#include "Krampus_Game_Engine.h"
#include "Photon.h"
#include "Scroller.h"
#include "Timing.h"

Krampus_Game_Engine::Krampus_Game_Engine () {}

Krampus_Game_Engine::Krampus_Game_Engine (int screen_width, int screen_height)
  {
  timer = Timing (60);
  }

Krampus_Game_Engine::~Krampus_Game_Engine () {}

void Krampus_Game_Engine::Init (HWND Window, Graphics_Info Graphics)
  {
  photon.Init (Window, Graphics);
  graphics = Graphics;

  player_bitmap = Bitmap (L"Images/krampus_test.bmp", L"Images/krampus_mask_test.bmp");
  badguy_test_bitmap = Bitmap (L"Images/badguy_test.bmp", L"Images/badguy_test_mask.bmp");
  background_bitmap = photon.load_bitmap (L"Images/bg_layer3_test.bmp");

  character_controller.add (100, 100, player_bitmap, 24, 40, true);
  character_controller.add (200, 100, badguy_test_bitmap, 24, 40, false);
  character_controller.add (100, 150, badguy_test_bitmap, 24, 40, true);
  character_controller.add (200, 150, player_bitmap, 24, 40, false);

  scroll = Scroller (graphics.game_view_width, graphics.game_view_height, 30, background_bitmap);
  }

void Krampus_Game_Engine::Main_Loop ()
  {
  timer.Update ();

  // execute all functions for frames (unlimited speed)
  keyboard.get_state ();
  menu.handle_keyboard (keyboard.current_input);
  Render ();

  // execute all functions for steps (limited speed)
  if (timer.is_step_ready ())
    {
    character_controller.Update ();
    Update_Character_Systems ();

    timer.update_step ();
    }
  }

void Krampus_Game_Engine::Render ()
  {
  photon.draw_bitmap (background_bitmap, photon.hdc_frame_buffer, scroll.x, scroll.y, graphics.pixel_scale);
  character_controller.Render (photon, scroll, graphics);
  photon.draw_debug (photon.hdc_frame_buffer, timer);
  photon.Finish_Frame ();
  }

void Krampus_Game_Engine::Update_Character_Systems ()
  {
  character_input_system.Update (character_controller.characters, scroll);
  }
