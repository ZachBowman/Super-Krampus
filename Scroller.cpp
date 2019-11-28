#include "stdafx.h"
#include "Scroller.h"

Scroller::Scroller () {}

Scroller::Scroller (int view_width, int view_height, int scroll_margin)
  {
  min_scroll_x = view_width;
  min_scroll_y = view_height;

  max_scroll_x = 0;
  max_scroll_y = 0;

  game_view_width = view_width;
  game_view_height = view_height;

  x = 0;
  y = 0;

  margin = scroll_margin;
  }

Scroller::Scroller (int view_width, int view_height, int scroll_margin, HBITMAP background)
  {
  game_view_width = view_width;
  game_view_height = view_height;

  // TODO: Change world size to user-defined instead of background-defined
  BITMAP temp_bitmap;
  GetObject (background, sizeof (temp_bitmap), &temp_bitmap);
  game_world_width = temp_bitmap.bmWidth;
  game_world_height = temp_bitmap.bmHeight;

  min_scroll_x = game_view_width > game_world_width ? 0 : game_view_width - game_world_width;
  min_scroll_y = game_view_height > game_world_height ? 0 : game_view_height - game_world_height;

  max_scroll_x = 0;
  max_scroll_y = 0;

  x = 0;
  y = 0;

  margin = scroll_margin;
  }

Scroller::~Scroller () {}
