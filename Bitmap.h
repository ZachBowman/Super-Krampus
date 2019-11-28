#pragma once

class Bitmap
  {
  public:

  Bitmap ();
  Bitmap (LPCWSTR sprite_path);
  Bitmap (LPCWSTR sprite_path, LPCWSTR mask_path);
  ~Bitmap ();
  void render (HDC temp_hdc, HDC dest_hdc, int dest_x, int dest_y);
  void render (HDC temp_hdc, HDC dest_hdc, int dest_x, int dest_y, float scale);
  void render (HDC temp_hdc, HDC dest_hdc, int source_x, int source_y, int source_width, int source_height, int dest_x, int dest_y, float scale);
  void get_size (HBITMAP hbitmap, int &width, int &height);
  HBITMAP sprite;
  HBITMAP mask;
  bool is_transparent = false;
  bool is_spritesheet = false;
  int sprite_width, sprite_height;
  };
