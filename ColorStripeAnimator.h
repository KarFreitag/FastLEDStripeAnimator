
#ifndef COLORSTRIPEANIMATOR_H
#define COLORSTRIPEANIMATOR_H

#include <set>
#include <FastLED.h>

#include "ColorAnchorPoint.h"
#include "ColorTransition.h"

class ColorStripeAnimator {
  public:
    ColorStripeAnimator();
    ~ColorStripeAnimator();

    void animateLeds( CRGB* leds, uint8_t numLeds);
    void addColorTransition( ColorTransition& transition);

  private:
    std::set< ColorTransition *> transitions;
};

#endif
