#include "stdafx.h"

#include "Character2D.h"
#include "Character_Controller.h"
#include "Character_Input_Component.h"
//#include "Character_Input_System.h"
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
  Character2D character (next_id, loaded_bitmap, Controllable);
  character.set_position (x, y);
  characters.add (character);
  if (Controllable)
    {
    Character_Input_Component input (next_id);
    input_components.add (input);
    }
  next_id += 1;
  }

void Character_Controller::add (int x, int y, Bitmap &loaded_bitmap, int width, int height, bool Controllable)
  {
  Character2D character (next_id, loaded_bitmap, width, height, Controllable);
  character.set_position (x, y);
  characters.add (character);
  if (Controllable)
    {
    Character_Input_Component input (next_id);
    input_components.add (input);
    }
  next_id += 1;
  }

void Character_Controller::Update ()
  {
  // TODO: remove this eventually
  Character2D character;
  for (int c = 0; c < characters.count; c += 1)
    {
    character = characters.get_data (c);
    character.Update ();
    characters.set_data (c, character);
    }
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

// Return the input component with matching id
Character_Input_Component & Character_Controller::get_input_component (int id)
  {
  Character_Input_Component input;
  for (int i = 0; i < input_components.count; i += 1)
    {
    input = input_components.get_data (i);
    if (input.character_id == id) return input;
    }
  //return NULL;
  }
