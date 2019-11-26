#include "stdafx.h"
#include <assert.h>
#include "Bitmap.h"

Bitmap::Bitmap () {}

Bitmap::Bitmap (LPCWSTR sprite_path)
  {
  sprite = (HBITMAP) LoadImage (NULL, sprite_path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
  assert (sprite != NULL);
  }

Bitmap::Bitmap (LPCWSTR sprite_path, LPCWSTR mask_path)
  {
  sprite = (HBITMAP) LoadImage (NULL, sprite_path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
  mask = (HBITMAP) LoadImage (NULL, mask_path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

  assert (sprite != NULL);
  assert (mask != NULL);

  is_transparent = true;
  }

Bitmap::~Bitmap () {}

void Bitmap::render (HDC temp_hdc, HDC dest_hdc, int source_x, int source_y, int dest_x, int dest_y)
  {
  BITMAP temp_bitmap;
  GetObject (sprite, sizeof (temp_bitmap), &temp_bitmap);
  SelectObject (temp_hdc, sprite);
  BitBlt (dest_hdc, dest_x, dest_y, temp_bitmap.bmWidth, temp_bitmap.bmHeight, temp_hdc, 0, 0, SRCINVERT);
  SelectObject (temp_hdc, mask);
  BitBlt (dest_hdc, dest_x, dest_y, temp_bitmap.bmWidth, temp_bitmap.bmHeight, temp_hdc, 0, 0, SRCAND);
  SelectObject (temp_hdc, sprite);
  BitBlt (dest_hdc, dest_x, dest_y, temp_bitmap.bmWidth, temp_bitmap.bmHeight, temp_hdc, 0, 0, SRCINVERT);
  }

void Bitmap::get_size (int &width, int &height)
  {
  BITMAP temp_bitmap;
  GetObject (sprite, sizeof (temp_bitmap), &temp_bitmap);
  width = temp_bitmap.bmWidth;
  height = temp_bitmap.bmHeight;
  }
