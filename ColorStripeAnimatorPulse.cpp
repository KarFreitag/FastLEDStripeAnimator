
#include "ColorStripeAnimatorPulse.h"

#include "ColorTransitionLinear.h"
#include "ColorAnimationLinear.h"

ColorStripeAnimatorPulse::ColorStripeAnimatorPulse( uint8_t numLeds) : ColorStripeAnimator( numLeds) {
  setupAnimations();
}

ColorStripeAnimatorPulse::~ColorStripeAnimatorPulse() {
  reset();
}

void ColorStripeAnimatorPulse::setPulseColor( CRGB color) {
  pulseColor = color;
  reset();
  setupAnimations();
}

CRGB ColorStripeAnimatorPulse::getPulseColor() {
  return pulseColor;
}

void ColorStripeAnimatorPulse::setPulseDuration( unsigned long milliSeconds) {
  pulseDuration = milliSeconds;
  reset();
  setupAnimations();
}

unsigned long ColorStripeAnimatorPulse::getPulseDuration() {
  return pulseDuration;
}

void ColorStripeAnimatorPulse::setupAnimations() {
  addColorTransition( &ColorTransitionLinear( ColorAnchorPoint( 0, pulseColor)));

  std::vector< ColorAnchorPoint *> anchors = getAnchorPoints();

  unsigned long halfPulseDuration = pulseDuration / 2;

  addColorAnimation( new ColorAnimationLinear( anchors[0], ColorAnchorPoint( anchors[0]->position, CRGB::Black), 0, halfPulseDuration));
  addColorAnimation( new ColorAnimationLinear( anchors[0], ColorAnchorPoint( anchors[0]->position, pulseColor), halfPulseDuration, pulseDuration));
}

void ColorStripeAnimatorPulse::reset() {
  for (ColorAnimation * animation : animations) {
    delete animation;
  }
  ColorStripeAnimator::reset();
}

