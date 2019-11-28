#include "stdafx.h"

#include "Character2D.h"
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
  background_bitmap = photon.load_bitmap (L"Images/bg_layer3_test.bmp");

  player = Character2D (player_bitmap, 24, 40);
  player.set_position (100, 100);

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
    player.Update (keyboard.current_input, scroll);
    timer.update_step ();
    }
  }

void Krampus_Game_Engine::Render ()
  {
  photon.draw_bitmap (background_bitmap, photon.hdc_frame_buffer, scroll.x, scroll.y, graphics.pixel_scale);
  player.bitmap->render (photon.hdc_temp, photon.hdc_frame_buffer, 1, 1, player.width, player.height, scroll.x + player.render_rect.left, scroll.y + player.render_rect.top, graphics.pixel_scale);
  photon.draw_debug (photon.hdc_frame_buffer, timer);

  photon.Finish_Frame ();
  }
