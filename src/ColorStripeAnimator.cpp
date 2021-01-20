
#include "ColorStripeAnimator.h"

ColorStripeAnimator::ColorStripeAnimator(uint8_t numLeds) : numLeds(numLeds) {}

ColorStripeAnimator::~ColorStripeAnimator() {}

void ColorStripeAnimator::animateLeds(CRGB *leds, unsigned long runtime)
{
  // reset animations if new loop started
  animTime = runtime % animDuration;

  // update anchor points by animations
  for (int i = 0; i < animations.size(); ++i)
  {
    animations[i]->update(animTime);
  }

  // update stripe by transitions
  for (uint8_t i = 0; i < transitions.size(); ++i)
  {
    auto trans = transitions[i];
    auto nextTrans = transitions[(i + 1) % transitions.size()];

    int firstPointPos = trans->startPoint->position;
    int numSteps;

    if (trans != nextTrans)
    {
      int nextPointPos = nextTrans->startPoint->position;
      numSteps = nextPointPos - firstPointPos;
      numSteps = (numSteps + numLeds) % numLeds;
    }
    else
    {
      numSteps = numLeds;
    }
    
    trans->updateTransition(leds, numLeds, (uint8_t)firstPointPos, numSteps);
  }
}

void ColorStripeAnimator::addColorTransition(ColorTransition *transition)
{
  transitions.push_back(transition);
  std::sort(transitions.begin(), transitions.end(), ColorTransitionPtrCompare());
}

void ColorStripeAnimator::addColorAnimation(ColorAnimation *animation)
{
  animations.push_back(animation);
  animDuration = max(animation->endTime, animDuration);
}