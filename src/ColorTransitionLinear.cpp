
#include "ColorTransitionLinear.h"

ColorTransitionLinear::ColorTransitionLinear( ColorAnchorPoint *startPoint, ColorAnchorPoint *otherPoint) : ColorTransition( startPoint), otherPoint(otherPoint) {}

void ColorTransitionLinear::updateTransition(CRGB * leds, uint8_t numLeds, uint8_t start, uint8_t numSteps) {

  int16_t colorDiff[3];
  for (uint8_t i=0; i<3; ++i) {
    colorDiff[i] = (int16_t)otherPoint->color[i] - (int16_t)startPoint->color[i];  
  }

  for (uint8_t i = 0; i < numSteps; ++i) {
    float ratio = (float)i / (float)numSteps;
    unsigned int pos = (start + i) % numLeds;
    
    for (uint8_t j=0; j<3; ++j) {
      leds[ pos][ j] = (int16_t)startPoint->color[j] + ratio * colorDiff[j];  
    }
  }
}
