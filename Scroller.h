#pragma once

class Scroller
  {
  public:
    Scroller ();
    Scroller (int screen_width, int screen_height);
    Scroller (int screen_width, int screen_height, HBITMAP background);
    ~Scroller ();

    int x, y;

    // Min and max offsets for visually scrolling the world.
    int min_scroll_x, max_scroll_x;
    int min_scroll_y, max_scroll_y;

    int screen_width, screen_height;

    int margin = 100;
  };

