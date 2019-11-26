#include "stdafx.h"

#include "Krampus_Game_Engine.h"
#include "Photon.h"
#include "Player2D.h"
#include "Scroller.h"
#include "Timing.h"

Krampus_Game_Engine::Krampus_Game_Engine () {}

Krampus_Game_Engine::Krampus_Game_Engine (int screen_width, int screen_height)
  {
  timer = Timing (60);
  }

Krampus_Game_Engine::~Krampus_Game_Engine () {}

void Krampus_Game_Engine::Init (HWND Window)
  {
  photon.Init (Window);

  photon.get_client_screen_size (Window, screen_width, screen_height);

  player_bitmap = Bitmap (L"Images/test_player.bmp", L"Images/test_player_mask1.bmp");
  background_bitmap = photon.load_bitmap (L"Images/bg_layer3_test.bmp");

  player = Player2D (player_bitmap);// (24, 40);
  player.set_position (100, 100);

  scroll = Scroller (screen_width, screen_height, background_bitmap);
  }

void Krampus_Game_Engine::Main_Loop ()
  {
  timer.Update ();

  // execute all functions for frames (unlimited speed)
  player.Get_Input ();
  Render ();

  // execute all functions for steps (limited speed)
  if (timer.is_step_ready ())
    {
    player.Update (scroll);
    timer.update_step ();
    }
  }

void Krampus_Game_Engine::Render ()
  {
  photon.draw_bitmap (background_bitmap, photon.hdc_frame_buffer, scroll.x, scroll.y, screen_width, screen_height);
  player_bitmap.render (photon.hdc_temp, photon.hdc_frame_buffer, 0, 0, scroll.x + player.render_rect.left, scroll.y + player.render_rect.top);
  photon.draw_debug (photon.hdc_frame_buffer, timer);

  photon.Finish_Frame ();
  }
