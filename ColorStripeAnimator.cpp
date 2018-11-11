
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

  for ( uint8_t i = 0; i < transitions.size(); ++i) {
    if ( i == transitions.size() - 1) {
      nextTrans = transitions.begin();
    }

    uint8_t firstPointPos = (*trans)->startPoint.position;
    uint8_t nextPointPos = (*nextTrans)->startPoint.position;

    uint8_t numSteps;
    if ( i == transitions.size() - 1) {
      numSteps = numLeds - firstPointPos + nextPointPos;
    } else {
      numSteps = ( nextPointPos - firstPointPos);
    }

    CRGB * newVals = new CRGB[ numSteps];
    (*trans)->updateTransition( (*nextTrans)->startPoint, newVals, numSteps);

    Serial.println( "transition " + String( i));

    for (uint8_t j = 0; j < numSteps; ++j) {
      uint8_t writePos = ( firstPointPos + j) % numLeds;
      leds[ writePos] = newVals[ j];
    }

    ++trans;
    ++nextTrans;

    delete[] newVals;
    //    Serial.println( "leds ");
    //    for (uint8_t i=0; i<numLeds; ++i) {
    //      Serial.println( String( leds[ i][0]) + " " + String( leds[i][1]) + " " + String( leds[ i][2]));
    //    }
  }
}

void ColorStripeAnimator::addColorTransition( ColorTransition * transition) {

  auto transitionSetIt = transitions.find( transition);
  if ( transitionSetIt != transitions.end()) {
    // anchorPoint already set -> remove transition to keep uniqueness
    delete * transitionSetIt;
    transitions.erase( transitionSetIt);
  }

  transitions.insert( transition->makeCopy());
}



