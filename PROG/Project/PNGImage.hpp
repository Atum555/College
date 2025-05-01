//! @file png_image.hpp
#ifndef __svg_png_image_hpp__
#define __svg_png_image_hpp__

#include "Color.hpp"
#include "Point.hpp"

#include <string>
#include <vector>

namespace svg {
//! PNG image.
class PNGImage {
  public:
    //! Constructor that loads image from a file.
    //! @param png_file_name File name.
    PNGImage(const std::string &png_file_name);
    //! Constructor of blank image.
    //! Initally, all pixels will be white.
    //! @param w Image width.
    //! @param h Image height.
    PNGImage(int w, int h);
    //! Destructor.
    ~PNGImage();
    //! Get image width.
    //! @return The image width.
    int    width() const;
    //! Get image height.
    //! @return The image height.
    int    height() const;
    //! Get mutable reference to image pixel.
    //! @param x X position
    //! @param y Y position.
    //! @return Reference to pixel.
    Color &at(int x, int y);
    //! Get const reference to image pixel.
    //! @param x X position
    //! @param y Y position.
    //! @return Reference to pixel.
    Color  at(int x, int y) const;
    //! Save to output file.
    //! @param png_file_name Output file name.
    void   save(const std::string &png_file_name) const;
    //! Draw a line defined by 2 points.
    //! @param a First point.
    //! @param b Second point.
    //! @param c Color to use for the line.
    void   draw_line(const Point &a, const Point &b, const Color &c);
    //! Draw a polygon.
    //! @param points Vector of points defining the polygon.
    //! @param fill Color to use for the polygon fill.
    void   draw_polygon(const std::vector<Point> &points, const Color &fill);
    //! Draw an ellipse.
    //! @param center Coordinates for the ellipse center.
    //! @param radius Radius in X and Y axis.
    //! @param fill Color to use for the ellipse fill.
    //! @param orientation ellipse orientation.
    void
    draw_ellipse(const Point &center, const Point &radius, const Color &fill);

  private:
    //! Width.
    int    width_;
    //! Height.
    int    height_;
    //! Pixels.
    Color *pixels_;
};
} // namespace svg

#endif
