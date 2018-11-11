#ifndef COLORTRANSITIONLINEAR_H
#define COLORTRANSITIONLINEAR_H

#include "ColorTransition.h"

class ColorTransitionLinear : public ColorTransition {
  public:
    ColorTransitionLinear( ColorAnchorPoint startPoint);
    ColorTransition * makeCopy() override;
    void updateTransition( ColorAnchorPoint& otherPoint, CRGB * firstColorAnchorPoint, uint8_t numSteps) override;
    //CRGB colorAtPosition( ColorAnchorPoint& otherPoint, uint8_t position) override;
};


#endif
