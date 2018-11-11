
#ifndef COLORTRANSITION_H
#define COLORTRANSITION_H

#include <FastLED.h>

#include "ColorAnchorPoint.h"

class ColorTransition {
  public:
    ColorTransition( ColorAnchorPoint startPoint);
    virtual ColorTransition * makeCopy() = 0;
    virtual void updateTransition( ColorAnchorPoint& otherPoint, CRGB * firstColorAnchorPoint, uint8_t numSteps) = 0;
    //virtual CRGB colorAtPosition( ColorAnchorPoint& otherPoint, uint8_t position) = 0;

    ColorAnchorPoint startPoint;
};

#endif
