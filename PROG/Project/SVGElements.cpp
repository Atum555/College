#include "SVGElements.hpp"
#include <string>
#include <vector>

namespace svg {

//* BASE ELEMENT

SVGElement::SVGElement(const std::string &id, const std::vector<Transform> &t) : id_(id), transforms_(t) {}

SVGElement::~SVGElement() {}

std::string SVGElement::getID() const { return id_; }

//


//* ELLIPSE && CIRCLE

Ellipse::Ellipse(
    const std::string &id, const std::vector<Transform> &t, const Color &fill, const Point &center, const Point &radius
)
    : SVGElement(id, t), color_(fill), center_(center), radius_(radius) {}

Circle::Circle(
    const std::string &id, const std::vector<Transform> &t, const Color &fill, const Point &center, int radius
)
    : Ellipse(id, t, fill, center, Point{ radius, radius }) {}

//


//* POLYLINE

PolyLine::PolyLine(
    const std::string &id, const std::vector<Transform> &t, const std::vector<Point> &points, const Color &stroke
)
    : SVGElement(id, t), color_(stroke), points_(points) {}

Line::Line(
    const std::string &id, const std::vector<Transform> &t, const Point &point1, const Point &point2,
    const Color &stroke
)
    : PolyLine(id, t, { point1, point2 }, stroke) {}

//


//* POLYGON

PolyGon::PolyGon(
    const std::string &id, const std::vector<Transform> &t, const std::vector<Point> &points, const Color &fill
)
    : SVGElement(id, t), color_(fill), points_(points) {}

Rectangle::Rectangle(
    const std::string &id, const std::vector<Transform> &t, const Color &fill, const Point &origin, int width,
    int height
)
    : PolyGon(
        id, t,
        {
            origin,
            {origin.x + width - 1,              origin.y},
            {origin.x + width - 1, origin.y + height - 1},
            {            origin.x, origin.y + height - 1},
        },
        fill
    ) {}

//


//* GROUP && USE

GroupElement::GroupElement(
    const std::string &id, const std::vector<Transform> &t, const std::vector<SVGElement *> &elems
)
    : SVGElement(id, t), elems_(elems) {}

GroupElement::~GroupElement() {
    for (SVGElement *elem : elems_) delete elem;
}

UseElement::UseElement(const std::string &id, const std::vector<Transform> &t, const SVGElement *ref)
    : SVGElement(id, t), ref_(ref) {}

UseElement::~UseElement() { delete ref_; }

//


//* Copy


SVGElement *Ellipse::copy(const std::vector<Transform> &t) const {
    // Copy only the transformation applied directly to the object
    std::vector<Transform> transList;
    transList.push_back(transforms_[0]);

    // Append Inherited Transformations
    transList.insert(transList.end(), t.begin(), t.end());

    return new Ellipse("", transList, color_, center_, radius_);
}

SVGElement *PolyLine::copy(const std::vector<Transform> &t) const {
    // Copy only the transformation applied directly to the object
    std::vector<Transform> transList;
    transList.push_back(transforms_[0]);

    // Append Inherited Transformations
    transList.insert(transList.end(), t.begin(), t.end());

    return new PolyLine("", transList, points_, color_);
}

SVGElement *PolyGon::copy(const std::vector<Transform> &t) const {
    // Copy only the transformation applied directly to the object
    std::vector<Transform> transList;
    transList.push_back(transforms_[0]);

    // Append Inherited Transformations
    transList.insert(transList.end(), t.begin(), t.end());

    return new PolyGon("", transList, points_, color_);
}

SVGElement *GroupElement::copy(const std::vector<Transform> &t) const {
    // Copy only the transformation applied directly to the object
    std::vector<Transform> transList;
    transList.push_back(transforms_[0]);

    // Append Inherited Transformations
    transList.insert(transList.end(), t.begin(), t.end());

    // Create copies of the children
    std::vector<SVGElement *> newElems;
    for (SVGElement *elem : elems_) newElems.push_back(elem->copy(transList));

    return new GroupElement("", transList, newElems);
}

SVGElement *UseElement::copy(const std::vector<Transform> &t) const {
    // Copy only the transformation applied directly to the object
    std::vector<Transform> transList;
    transList.push_back(transforms_[0]);

    // Append Inherited Transformations
    transList.insert(transList.end(), t.begin(), t.end());

    // Create copy of the referenced element
    SVGElement *newEP = ref_->copy(transList);

    return new UseElement("", transList, newEP);
}

//


//* Draw

void Ellipse::draw(PNGImage &img) const {
    Point center = center_; // Copy of the center
    Point radius = radius_; // Copy of the radius

    // Apply each Transformation to center
    for (const Transform t : transforms_) {
        center = center.translate(t.getTrans());
        center = center.scale(t.getOrigin(), t.getScale());
        center = center.rotate(t.getOrigin(), t.getRotate());

        radius = radius.scale(Point{ 0, 0 }, t.getScale()); // Radius Scales Independent from the origin
    }

    img.draw_ellipse(center, radius, color_);               // Draw Ellipse
}

void PolyLine::draw(PNGImage &img) const {
    std::vector<Point> points = points_; // Copy of the points

    // Apply each Transformation to each Point of the PolyLine
    for (const Transform t : transforms_) {
        for (Point &point : points) {
            point = point.translate(t.getTrans());
            point = point.scale(t.getOrigin(), t.getScale());
            point = point.rotate(t.getOrigin(), t.getRotate());
        }
    }

    // Draw each individual segment
    for (size_t i = 0; i < points.size() - 1; i++) img.draw_line(points[i], points[i + 1], color_);
}

void PolyGon::draw(PNGImage &img) const {
    std::vector<Point> points = points_; // Copy of the points

    // Apply each Transformation to each Point of the PolyGon
    for (const Transform t : transforms_) {
        for (Point &point : points) {
            point = point.translate(t.getTrans());
            point = point.scale(t.getOrigin(), t.getScale());
            point = point.rotate(t.getOrigin(), t.getRotate());
        }
    }

    img.draw_polygon(points, color_); // Draw Polygon
}

void GroupElement::draw(PNGImage &img) const {
    for (SVGElement *elem : elems_) elem->draw(img);
}

void UseElement::draw(PNGImage &img) const { ref_->draw(img); }


} // namespace svg