
#include "ColorAnimation.h"

ColorAnimation::ColorAnimation(ColorAnchorPoint *reference, ColorAnchorPoint start, ColorAnchorPoint target, unsigned long startTime, unsigned long endTime)
    : referencePoint(reference),
      startPoint(start),
      targetPoint(target),
      startTime(startTime),
      endTime(endTime)
{
}
