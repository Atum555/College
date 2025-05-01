#include "SVGElements.hpp"
#include <string>
#include <vector>

namespace svg {
void convert(const std::string &svg_file, const std::string &png_file) {
    Point                     dimensions;
    std::vector<SVGElement *> svg_elements;
    readSVG(svg_file, dimensions, svg_elements);
    PNGImage img(dimensions.x, dimensions.y);
    for (SVGElement *e : svg_elements) { e->draw(img); }
    img.save(png_file);
    for (SVGElement *e : svg_elements) { delete e; }
}
} // namespace svg