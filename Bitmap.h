#pragma once

class Bitmap
  {
  public:

  Bitmap ();
  Bitmap (LPCWSTR sprite_path);
  Bitmap (LPCWSTR sprite_path, LPCWSTR mask_path);
    ~Bitmap ();
  void render (HDC temp_hdc, HDC dest_hdc, int source_x, int source_y, int dest_x, int dest_y);
  void get_size (int &width, int &height);
  HBITMAP sprite;
  HBITMAP mask;
  bool is_transparent = false;
  bool is_spritesheet = false;
  int sprite_width, sprite_height;
  };
