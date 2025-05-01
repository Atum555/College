//! @file point.hpp
#ifndef __svg_point_hpp__
#define __svg_point_hpp__

namespace svg {
//! 2D Point struct, with a few convenience member functions (can be defined for
//! structs too).
struct Point {
    //! X coordinate.
    int x;
    //! Y coordinate.
    int y;

    //! Translate a point.
    //! @param t translation direction.
    //! @return Translation result.
    Point translate(const Point &t) const;
    //! Rotate a point.
    //! @param origin Rotation origin
    //! @param degrees Degrees of rotation.
    //! @return Rotation result.
    Point rotate(const Point &origin, int degrees) const;
    //! Scale a point.
    //! @param origin Scaling origin.
    //! @param v Scale amount.
    //! @return Scaling result.
    Point scale(const Point &origin, int v) const;
};
} // namespace svg
#endif
