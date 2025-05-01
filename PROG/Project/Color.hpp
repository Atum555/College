//! @file Color.hpp
#ifndef __svg_Color_hpp__
#define __svg_Color_hpp__

#include <string>

namespace svg {
typedef unsigned char rgb_value;

//! Representation of 8-bit RGB colors.
struct Color {
    //! Red component.
    rgb_value red;
    //! Green component.
    rgb_value green;
    //! Blue component.
    rgb_value blue;
};

//! Parse a color from a string.
//! The string may refer to a color name or have a
//! '#rrggbb' format where 'rr', 'gg' and 'bb'
//! are hexadecimal values for each RGB component.
//! @param str String.
//! @return A corresponding color.
Color parse_color(const std::string &str);

} // namespace svg
#endif