
#include "ColorAnimationLinear.h"

ColorAnimationLinear::ColorAnimationLinear( ColorAnchorPoint * reference, ColorAnchorPoint target, unsigned long startTime, unsigned long endTime)
  : ColorAnimation( reference, target, startTime, endTime) {

}

void ColorAnimationLinear::update( unsigned long runTime) {

  if ( didEnd || (runTime < startTime)) {
    //Serial.println( "ColorAnimationLinear - not updating, runTime: " + String( runTime) + " startTime: " + String( startTime) + " didEnd: " + String( didEnd));
    return;
  } 
  
  if ( !didStart) {
    // first loop
    //Serial.println( "ColorAnimationLinear - did start");
    startPoint = ColorAnchorPoint( referencePoint->position, referencePoint->color);
    didStart = true;
  } 
  
  if (endTime < runTime) {
    // last loop
    //Serial.println( "ColorAnimationLinear - did end");
    runTime = endTime;
    didEnd = true;
  }

  float factor = (float)(runTime - startTime) / (float)(endTime - startTime);
  //Serial.println( "ColorAnimationLinear - factor: " + String( factor));

  referencePoint->position = (1 - factor) * startPoint.position + factor * targetPoint.position;

  for (uint8_t i=0; i<3; ++i) {
    referencePoint->color[i] = (1 - factor) * (int16_t)startPoint.color[i] + factor * (int16_t)targetPoint.color[i];  
  }
}

