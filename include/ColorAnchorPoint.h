#pragma once

#include <FastLED.h>

class ColorAnchorPoint
{
public:
  ColorAnchorPoint(uint8_t position, CRGB color);

  uint8_t position;
  CRGB color;
};