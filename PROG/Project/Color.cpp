#include "Color.hpp"
#include <iomanip>
#include <map>
#include <sstream>

namespace svg {
const std::map<std::string, Color> NAMES_TO_COLORS = {
    { "black",       { 0, 0, 0 }},
    { "white", { 255, 255, 255 }},
    {   "red",     { 255, 0, 0 }},
    { "green",     { 0, 255, 0 }},
    {  "blue",     { 0, 0, 255 }},
    {"yellow",   { 255, 255, 0 }}
};

Color parse_color(const std::string &str) {
    Color c;
    if (str.at(0) == '#') {
        int                v;
        std::istringstream ss(str.substr(1));
        ss >> std::hex >> v;
        c.red   = (v >> 16);
        c.green = (v >> 8) & 0xFF;
        c.blue  = v & 0xFF;
    } else {
        c = NAMES_TO_COLORS.at(str);
    }
    return c;
}
} // namespace svg