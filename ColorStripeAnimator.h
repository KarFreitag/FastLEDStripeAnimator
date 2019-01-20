
#ifndef COLORSTRIPEANIMATOR_H
#define COLORSTRIPEANIMATOR_H

#include <set>
#include <FastLED.h>

#include "ColorAnchorPoint.h"
#include "ColorTransition.h"
#include "ColorAnimation.h"

struct ColorTransitionPtrCompare {
  bool operator() (ColorTransition* lhs, ColorTransition* rhs) {
    //Serial.println( "comparison: " + String( lhs.startPoint.position < rhs.startPoint.position));
    return lhs->startPoint.position < rhs->startPoint.position;
  }
};

class ColorStripeAnimator {
  public:
    ColorStripeAnimator( uint8_t numLeds);
    ~ColorStripeAnimator();

    void animateLeds( CRGB* leds, unsigned long runtime);
    void addColorTransition( ColorTransition * transition);
    void addColorAnimation( ColorAnimation * animation);
    std::vector< ColorAnchorPoint *> getAnchorPoints();

  private:
    uint8_t numLeds;
    unsigned long animDuration = 1;
    unsigned long animTime;
    std::set< ColorTransition *, ColorTransitionPtrCompare> transitions;
    std::vector< ColorAnimation *> animations;
    

};

#endif
