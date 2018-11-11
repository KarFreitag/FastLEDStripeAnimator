
#include "ColorStripeAnimator.h"

ColorStripeAnimator::ColorStripeAnimator() {}

ColorStripeAnimator::~ColorStripeAnimator() {
  }

void ColorStripeAnimator::animateLeds( CRGB* leds, uint8_t numLeds) {

}

void ColorStripeAnimator::addColorTransition( ColorTransition& transition) {

  auto transitionSetIt = transitions.find( &transition);
  if ( transitionSetIt != transitions.end()){
    // anchorPoint already set -> remove transition to keep uniqueness 
    delete * transitionSetIt;
    transitions.erase( transitionSetIt);
  }

  transitions.insert( transition.makeCopy());
}



