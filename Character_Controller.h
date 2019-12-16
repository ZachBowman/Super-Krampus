#pragma once

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

class Character_Controller
  {
  public:

  Character_Controller ();
  ~Character_Controller ();
  void add (int x, int y, Bitmap &loaded_bitmap, bool Controllable);
  void add (int x, int y, Bitmap &loaded_bitmap, int width, int height, bool Controllable);
  void Update ();
  void Render (Photon photon, Scroller scroll, Graphics_Info graphics);
  void create_components ();
  Character_Input_Component & get_input_component (int id);

  Linked_List<Character2D> characters;
  Linked_List<Character_Input_Component> input_components;
  //Character_Input_System input_system;

  private:

  int next_id = 0;
  };
