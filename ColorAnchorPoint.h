
#ifndef COLORANCHORPOINT_H
#define COLORANCHORPOINT_H

#include <FastLED.h>


class ColorAnchorPoint {
  public:
    ColorAnchorPoint( uint8_t position, CRGB color);
    
    uint8_t position;
    CRGB color;
};

#endif
