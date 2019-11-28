#pragma once

class Scroller
  {
  public:

  Scroller ();
  Scroller (int new_game_width, int new_game_height, int scroll_margin);
  Scroller (int new_game_width, int new_game_height, int scroll_margin, HBITMAP background);
  ~Scroller ();

  int x, y;

  // Min and max offsets for visually scrolling the world.
  int min_scroll_x, max_scroll_x;
  int min_scroll_y, max_scroll_y;

  // TODO: game world size should not be part of the scroller.  Where should it go?
  int game_world_width, game_world_height;
  int game_view_width, game_view_height;

  int margin;
  };
