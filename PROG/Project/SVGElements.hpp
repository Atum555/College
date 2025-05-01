/// @file shape.hpp
#ifndef __svg_SVGElements_hpp__
#define __svg_SVGElements_hpp__

#include "Color.hpp"
#include "PNGImage.hpp"
#include "Point.hpp"
#include "external/tinyxml2/tinyxml2.h"
#include <string>
#include <vector>

namespace svg {

class Transform {
  private:
    int transX_, transY_;
    int rotate_;
    int scale_;
    int origX_, origY_;

  public:
    /// @brief      Object that represents a transformation.
    /// @param tx   Translation in X
    /// @param ty   Translation in Y
    /// @param r    Rotation
    /// @param s    Scale
    /// @param ox   Origin X
    /// @param oy   Origin Y
    Transform(int tx, int ty, int r, int s, int ox, int oy)
        : transX_(tx), transY_(ty), rotate_(r), scale_(s), origX_(ox), origY_(oy) {}

    /// @return Translation
    Point getTrans() const { return Point{ transX_, transY_ }; }

    /// @return Rotation
    int getRotate() const { return rotate_; }

    /// @return Scale
    int getScale() const { return scale_; }

    /// @return Origin
    Point getOrigin() const { return Point{ origX_, origY_ }; }
};

class SVGElement {
  protected:
    std::string            id_;
    std::vector<Transform> transforms_;

  public:
    /// @param id   Element's ID
    /// @param t    Transformations
    SVGElement(const std::string &id, const std::vector<Transform> &t);
    virtual ~SVGElement();

    /// @brief  Get the ID of the element
    /// @return Element's ID
    std::string getID() const;

    /// @brief      Draw Element
    /// @param img  PNGImage object of the image
    virtual void draw(PNGImage &img) const = 0;

    /// @brief      Generate a copy of the element
    /// @param t    Extra Transformations to add
    /// @return     Pointer to newly created element
    virtual SVGElement *copy(const std::vector<Transform> &t) const = 0;
};

class Ellipse : public SVGElement {
  protected:
    Color color_;
    Point center_;
    Point radius_;

  public:
    /// @brief          Ellipse Element
    /// @param id       Element's ID
    /// @param t        Transformations
    /// @param fill     Fill Color
    /// @param center   Ellipse Center
    /// @param radius   Point representing the x and y radius
    Ellipse(
        const std::string &id, const std::vector<Transform> &t, const Color &fill, const Point &center,
        const Point &radius
    );

    void        draw(PNGImage &img) const override final;
    SVGElement *copy(const std::vector<Transform> &t) const override final;
};

class Circle : public Ellipse {
  public:
    /// @brief          Circle Element
    /// @param id       Element's ID
    /// @param t        Transformations
    /// @param fill     Fill Color
    /// @param center   Circle Center
    /// @param radius   Circle Radius
    Circle(const std::string &id, const std::vector<Transform> &t, const Color &fill, const Point &center, int radius);
};

class PolyLine : public SVGElement {
  protected:
    Color              color_;
    std::vector<Point> points_;

  public:
    /// @brief          PolyLine Element
    /// @param id       Element's ID
    /// @param t        Transformations
    /// @param points   Points
    /// @param stroke   Stroke Color
    PolyLine(
        const std::string &id, const std::vector<Transform> &t, const std::vector<Point> &points, const Color &stroke
    );

    void        draw(PNGImage &img) const override final;
    SVGElement *copy(const std::vector<Transform> &t) const override final;
};

class Line : public PolyLine {
  public:
    /// @brief          Line Element
    /// @param id       Element's ID
    /// @param t        Transformations
    /// @param point1   Start Point
    /// @param point2   End Point
    /// @param color    Stroke Color
    Line(
        const std::string &id, const std::vector<Transform> &t, const Point &point1, const Point &point2,
        const Color &stroke
    );
};

class PolyGon : public SVGElement {
  protected:
    Color              color_;
    std::vector<Point> points_;

  public:
    /// @brief          PolyGon
    /// @param id       Element's ID
    /// @param t        Transformations
    /// @param points   Points
    /// @param color    Fill Color
    PolyGon(
        const std::string &id, const std::vector<Transform> &t, const std::vector<Point> &points, const Color &fill
    );

    void        draw(PNGImage &img) const override final;
    SVGElement *copy(const std::vector<Transform> &t) const override final;
};

class Rectangle : public PolyGon {
  public:
    /// @brief          Rectangle Element
    /// @param id       Element's ID
    /// @param t        Transformations
    /// @param origin   Start Point
    /// @param width    Width
    /// @param height   Height
    /// @param color    Fill Color
    Rectangle(
        const std::string &id, const std::vector<Transform> &t, const Color &fill, const Point &origin, int width,
        int height
    );
};

class GroupElement : public SVGElement {
  protected:
    std::vector<SVGElement *> elems_;

  public:
    /// @brief          Object that represents a group of elements
    /// @param id       Element's ID
    /// @param t        Transformations
    /// @param elems    Vector of Child Elements
    GroupElement(const std::string &id, const std::vector<Transform> &t, const std::vector<SVGElement *> &elems);
    ~GroupElement();

    void        draw(PNGImage &img) const override final;
    SVGElement *copy(const std::vector<Transform> &t) const override final;
};

class UseElement : public SVGElement {
  protected:
    const SVGElement *ref_;

  public:
    /// @brief          Object with a reference to another element
    /// @param id       Element's ID
    /// @param t        Transformations
    /// @param ref      Pointer to third Element
    UseElement(const std::string &id, const std::vector<Transform> &t, const SVGElement *ref);
    ~UseElement();

    void        draw(PNGImage &img) const override final;
    SVGElement *copy(const std::vector<Transform> &t) const override final;
};

/// @brief              Convert a svg file to a png file
/// @param svg_file     Name of svg file
/// @param png_file     Name of png file (will be overwritten!)
void convert(const std::string &svg_file, const std::string &png_file);


/// @brief              Read a SVG file and parse elements
/// @param svg_file     Name of the file
/// @param dimensions   Point to be filled with the image dimensions
/// @param svg_elements Vector to be filled with read elements
void readSVG(const std::string &svg_file, Point &dimensions, std::vector<SVGElement *> &svg_elements);


/// @brief                  Parse XMLElement into an SVGElement and add it to svg_elements and possibly to svg_elems_id
/// @param element          Pointer to the element
/// @param svg_elements     List to add the element
/// @param svg_elems_id     List of elements with ID
/// @param transforms       List of inherited transformations
void parseElement(
    const tinyxml2::XMLElement *element, std::vector<SVGElement *> &elementList,
    std::vector<SVGElement *> &elementListID, const std::vector<Transform> &transforms = {}
);


/// @brief          Get Transformation from element atributes
/// @param element  Pointer to Element
/// @return         Transformation object
Transform getTransform(const tinyxml2::XMLElement *element);
} // namespace svg
#endif