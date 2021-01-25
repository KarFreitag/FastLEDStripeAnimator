
#include "ColorTransitionHue.h"

#include "ArduinoSTL.h"

ColorTransitionHue::ColorTransitionHue(ColorAnchorPoint *startPoint, ColorAnchorPoint *otherPoint, TGradientDirectionCode direction)
    : ColorTransition(startPoint), otherPoint(otherPoint), directionCode(direction) {}

void ColorTransitionHue::updateTransition(CRGB *leds, uint8_t numLeds, uint8_t start, uint8_t numSteps)
{
    CHSV startHue = rgb2hsv_approximate(startPoint->color);
    CHSV endHue = rgb2hsv_approximate(otherPoint->color);

    if (startPoint == otherPoint)
    {
        if (directionCode == FORWARD_HUES)
        {
            endHue.h = startHue.h - (uint8_t) (256.0f / numLeds);
        }
        else
        {
            endHue.h = startHue.h + (uint8_t) (256.0f / numLeds);
        }
    }

    CRGB tempLeds[numSteps];
    fill_gradient(tempLeds, numSteps, startHue, endHue, directionCode);

    for (uint8_t i = 0; i < numSteps; ++i)
    {
        uint8_t pos = (start + i) % numLeds;
        leds[pos] = tempLeds[i];
    }
}
