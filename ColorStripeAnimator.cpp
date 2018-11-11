
#include "ColorStripeAnimator.h"

ColorStripeAnimator::ColorStripeAnimator( uint8_t numLeds) : numLeds( numLeds) {}

ColorStripeAnimator::~ColorStripeAnimator() {
  for (auto it = transitions.begin(); it != transitions.end(); ++it) {
    delete *it;
  }
}

void ColorStripeAnimator::animateLeds( CRGB* leds) {
  auto trans = transitions.begin();
  auto nextTrans = ++transitions.begin();
  
  for ( int i = 0; i < transitions.size() - 1; ++i) {
    uint8_t firstPointPos = (*trans)->startPoint.position;
    uint8_t nextPointPos = (*nextTrans)->startPoint.position;

    uint8_t numSteps = ( nextPointPos - firstPointPos);
    CRGB * newVals = new CRGB[ numSteps];
    (*trans)->updateTransition( (*nextTrans)->startPoint, newVals, numSteps);

    if (i < transitions.size() - 1) {
      memcpy( &( leds[ firstPointPos]), newVals, numSteps);
      
    } else {
      uint8_t numLedsTillEnd = numLeds - firstPointPos;
      memcpy( &( leds[ firstPointPos]), newVals, numLedsTillEnd);
      memcpy( &( leds[ 0]), &( newVals[ numLedsTillEnd]), firstPointPos);
    }

  }
}

void ColorStripeAnimator::addColorTransition( ColorTransition& transition) {

  auto transitionSetIt = transitions.find( &transition);
  if ( transitionSetIt != transitions.end()) {
    // anchorPoint already set -> remove transition to keep uniqueness
    delete * transitionSetIt;
    transitions.erase( transitionSetIt);
  }

  transitions.insert( transition.makeCopy());
}



