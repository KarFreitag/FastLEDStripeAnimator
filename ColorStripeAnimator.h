
#ifndef COLORSTRIPEANIMATOR_H
#define COLORSTRIPEANIMATOR_H

#include <set>
#include <FastLED.h>

#include "ColorAnchorPoint.h"
#include "ColorTransition.h"

class ColorStripeAnimator {
  public:
    ColorStripeAnimator( uint8_t numLeds);
    ~ColorStripeAnimator();

    void animateLeds( CRGB* leds);
    void addColorTransition( ColorTransition * transition);

  private:
    uint8_t numLeds;
    std::set< ColorTransition *> transitions;
};

#endif
