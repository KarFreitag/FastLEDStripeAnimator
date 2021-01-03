
#include "ColorTransitionLinear.h"

ColorTransitionLinear::ColorTransitionLinear( ColorAnchorPoint startPoint) : ColorTransition( startPoint) {}

ColorTransition * ColorTransitionLinear::makeCopy() {
  return new ColorTransitionLinear( startPoint);
}

void ColorTransitionLinear::updateTransition( ColorAnchorPoint& otherPoint, CRGB * firstColorAnchorPoint, uint8_t numSteps) {

  int16_t colorDiff[3];
  for (uint8_t i=0; i<3; ++i) {
    colorDiff[i] = (int16_t)otherPoint.color[i] - (int16_t)startPoint.color[i];  
  }

  for (uint8_t i = 0; i < numSteps; ++i) {
    float ratio = (float)i / (float)numSteps;
    
    for (uint8_t j=0; j<3; ++j) {
      firstColorAnchorPoint[ i][j] = (int16_t)startPoint.color[j] + ratio * colorDiff[j];  
    }
  }
}
