
#include <ArduinoSTL.h>

#include "ColorAnimationLinear.h"

ColorAnimationLinear::ColorAnimationLinear(ColorAnchorPoint *reference, ColorAnchorPoint start, ColorAnchorPoint target, unsigned long startTime, unsigned long endTime)
    : ColorAnimation(reference, start, target, startTime, endTime)
{
}

void ColorAnimationLinear::update(unsigned long runTime)
{
  if ((runTime < startTime) || (runTime > endTime))
  {
    return;
  }

  float factor = (float)(runTime - startTime) / (float)(endTime - startTime);

  referencePoint->position = (uint8_t) ((1 - factor) * startPoint.position + factor * targetPoint.position);
  
  referencePoint->color.r = (1 - factor) * startPoint.color.r + factor * targetPoint.color.r;
  referencePoint->color.g = (1 - factor) * startPoint.color.g + factor * targetPoint.color.g;
  referencePoint->color.b = (1 - factor) * startPoint.color.b + factor * targetPoint.color.b;
}
