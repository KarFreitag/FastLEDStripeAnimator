
#include "ColorTransitionConst.h"

ColorTransitionConst::ColorTransitionConst(ColorAnchorPoint *startPoint) : ColorTransition(startPoint) {}

void ColorTransitionConst::updateTransition(CRGB * leds, uint8_t numLeds, uint8_t start, uint8_t numSteps)
{
  for (unsigned int i = 0; i < numSteps; ++i)
  {
    unsigned int pos = (start + i) % numLeds;
    leds[pos] = startPoint->color;
  }
}
