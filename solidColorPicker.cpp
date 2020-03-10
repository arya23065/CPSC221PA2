#include "solidColorPicker.h"

/**
 * Constructs a new solidColorPicker.
 *
 * @param fillColor The color for this color picker.
 */
solidColorPicker::solidColorPicker(HSLAPixel fillColor)
{
    /* your code here */
    color = fillColor;
}

/**
 * Picks the color for pixel (x, y).
 *
 * Simply returns the same color (used to construct the picker) all
 * of the time.
 */
HSLAPixel solidColorPicker::operator()(point p)
{
    /* your code here */
    // add checks 
    return color;
}
