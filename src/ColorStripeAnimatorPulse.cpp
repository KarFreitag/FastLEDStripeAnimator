
#include "ColorStripeAnimatorPulse.h"

#include "ColorTransitionConst.h"
#include "ColorAnimationLinear.h"

ColorStripeAnimatorPulse::ColorStripeAnimatorPulse( uint8_t numLeds) : ColorStripeAnimator( numLeds) {
  setupAnimations();
}

ColorStripeAnimatorPulse::~ColorStripeAnimatorPulse() {}

void ColorStripeAnimatorPulse::setPulseColor( CRGB color) {
  pulseColor = color;
  setupAnimations();
}

void ColorStripeAnimatorPulse::setPulseDuration( unsigned long milliSeconds) {
  pulseDuration = milliSeconds;
  setupAnimations();
}

void ColorStripeAnimatorPulse::setupAnimations() {
  for (auto transPtr: transitions) {
    delete transPtr->startPoint;
    delete transPtr;
  }

  animations.clear();
  transitions.clear();

  ColorAnchorPoint * anchor = new ColorAnchorPoint(0, pulseColor);
  ColorTransition * transition = new ColorTransitionConst( anchor);

  addColorTransition( transition);

  unsigned long halfPulseDuration = pulseDuration / 2;

  addColorAnimation( new ColorAnimationLinear( anchor, ColorAnchorPoint( anchor->position, pulseColor), ColorAnchorPoint( anchor->position, CRGB::Black), 0, halfPulseDuration));
  addColorAnimation( new ColorAnimationLinear( anchor, ColorAnchorPoint( anchor->position, CRGB::Black), ColorAnchorPoint( anchor->position, pulseColor), halfPulseDuration, pulseDuration));
}