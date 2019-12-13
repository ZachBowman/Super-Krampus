#include "stdafx.h"

#include "Character2D.h"
#include "Character_Controller.h"
#include "Character_Input_System.h"
#include "Graphics_Info.h"
#include "Input_State.h"
#include "Keyboard.h"
#include "Linked_List.h"
#include "Photon.h"
#include "Scroller.h"

Character_Controller::Character_Controller () {}

Character_Controller::~Character_Controller () {}

void Character_Controller::add (int x, int y, Bitmap &loaded_bitmap, bool Controllable)
  {
  Character2D character (next_id, loaded_bitmap, true);
  character.set_position (x, y);
  characters.add (character);
  next_id += 1;
  }

void Character_Controller::add (int x, int y, Bitmap &loaded_bitmap, int width, int height, bool Controllable)
  {
  Character2D character (next_id, loaded_bitmap, width, height, Controllable);
  character.set_position (x, y);
  characters.add (character);
  next_id += 1;
  }

void Character_Controller::Update (Input_State input, Scroller &scroll)
  {
  // TODO: remove this eventually
  Character2D character;
  for (int c = 0; c < characters.count; c += 1)
    {
    character = characters.get_data (c);
    character.Update (input, scroll);
    characters.set_data (c, character);
    }

  // TODO: add systems here
  input_system.Update_All (characters, scroll);
  }

void Character_Controller::Render (Photon photon, Scroller scroll, Graphics_Info graphics)
  {
  Character2D character;
  for (int c = 0; c < characters.count; c += 1)
    {
    character = characters.get_data (c);
    character.bitmap->render (photon.hdc_temp, photon.hdc_frame_buffer, 1, 1, character.width, character.height, scroll.x + character.render_rect.left, scroll.y + character.render_rect.top, graphics.pixel_scale);
    }
  }

void Character_Controller::create_components ()
  {
  // TODO: do I need this?
  }
