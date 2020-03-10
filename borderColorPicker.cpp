#include "borderColorPicker.h"

/**
 * borderColorPicker: a functor that determines the color that should be used
 * given an `point`. If the given position is near a border of
 * the fill, then it should be colored with the given color. Otherwise, its color
 * should not change.
 *
 * The following criteria should be used to determine if a position p is near
 * a border: if p is within distance `borderSize` of any cell that will be outside the
 * fill, then the pixel at position p should be colored with the given color.
 *
 * You will use Euclidian distance to judge proximity. That means if p is at
 * location (x,y), its distance to a point at location (a,b) is
 * squareRoot([(x-a)^2 + (y-b)^2]). Note that you should not ever have to
 * compute the square root to solve this problem.
 *
 **/

 /**
  * Constructs a new borderColorPicker.
  *
  * @param borderSize  Number of pixels to color around border
  * @param fillColor   Color for the border.
  * @param img         Image to pick colors from.
  * @param tolerance   Tolerance used to determine the border of the fill.
  */
borderColorPicker::borderColorPicker(unsigned int borderSize, HSLAPixel fillColor, PNG &img, double tolerance)
{
    /* your code here */
    borderSize = borderSize;
    fillColor = fillColor;
    img = img;
    tolerance = tolerance;
}

/**
 * Picks the color for pixel at point. If the x or y coordinate is
 * near the border of the fill, or the border of the image,
 * it will be filled with the fillColor.
 * Otherwise, its color will not be changed.
 *
 * @param p   The point for which you're picking a color.
 * @return    The color chosen for (p).
 */
HSLAPixel borderColorPicker::operator()(point p)
{
    /* your code here */
    // HSLAPixel* currPixel = img.getPixel(0, 0);
    // int borderY = 0;
    //
    // if (p.y <= img.width()/2)  borderY = 0;
    // else  borderY = img.width() - 1;
    //
    // int distance = sqr(p.x-);
    //
    // if (p.x == borderSize)
    //   p.c.color = fillColor;
    //
    // for (int i = 0; i < img.width(); i++) {
    //   for (int j = 0; )
    // }

      // HSLAPixel color = bcp(p); // bcp is a bordercolorpicker object,
      //                       // p is a point

  int currX = p.x + borderSize;
  int currY = p.y + borderSize;

  HSLAPixel *currPixel = img.getPixel(p.x, p.y);
  for (int i = p.x-borderSize; i <= currX; i++){
      for (int j = p.y-borderSize; j <= currY; j++){
          if (j >= img.height() || i >= img.width() || i < 0 || j < 0 ||
                  ((p.x - i) * (p.x - i) + (p.y - j) * (p.y - j) <= borderSize*borderSize && img.getPixel(i,j)->dist(p.c.color) > tolerance)){
              return p.c.color;
          }
      }
  }
  return *currPixel;

}
