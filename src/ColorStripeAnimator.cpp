
#include "ColorStripeAnimator.h"

ColorStripeAnimator::ColorStripeAnimator( uint8_t numLeds) : numLeds( numLeds) {}

ColorStripeAnimator::~ColorStripeAnimator() {
  reset();
}

void ColorStripeAnimator::animateLeds( CRGB* leds, unsigned long runtime) {

  // reset animations if new loop started
  unsigned long newAnimTime = runtime % animDuration;

  if (newAnimTime < animTime) {
    for (ColorAnimation* animation : animations) {
      animation->reset();
    }
  }

  // update anchor points by animations
  animTime = newAnimTime;
  
  for (ColorAnimation* animation : animations) {
    animation->update( animTime);
  }

  // update stripe by transitions
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

    for (uint8_t j = 0; j < numSteps; ++j) {
      uint8_t writePos = ( firstPointPos + j) % numLeds;
      leds[ writePos] = newVals[ j];
    }

    ++trans;
    ++nextTrans;

    delete[] newVals;
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

void ColorStripeAnimator::addColorAnimation( ColorAnimation * animation) {
  animations.push_back( animation);
  animDuration = max( animation->endTime, animDuration);
}

std::vector< ColorAnchorPoint *> ColorStripeAnimator::getAnchorPoints() {
  std::vector< ColorAnchorPoint *> anchorPoints( transitions.size());

  auto it = transitions.begin();
  for ( uint8_t i = 0; i < transitions.size(); ++i) {
    anchorPoints[i] = &( (*it)->startPoint);
    ++it;
  }
  
  return anchorPoints;
}

void ColorStripeAnimator::reset() {
  for (ColorTransition * transition : transitions) {
    delete transition;
  }
  transitions.clear();
  animations.clear();
  animDuration = 1;
}

