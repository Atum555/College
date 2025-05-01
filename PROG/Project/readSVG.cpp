#include "SVGElements.hpp"
#include "external/tinyxml2/tinyxml2.h"
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace tinyxml2;

namespace svg {

void readSVG(const string &svg_file, Point &dimensions, vector<SVGElement *> &svg_elements) {
    // Load SVG FIle
    XMLDocument doc;
    XMLError    r = doc.LoadFile(svg_file.c_str());
    if (r != XML_SUCCESS) throw runtime_error("Unable to load " + svg_file); // Abort if Errors

    // Get Dimensions
    XMLElement *xml_elem = doc.RootElement();
    dimensions.x         = xml_elem->IntAttribute("width");
    dimensions.y         = xml_elem->IntAttribute("height");

    XMLNode *node = doc.FirstChild(); // <svg> Node
    if (node->NoChildren()) return;   // Check if there are any elements

    // Create auxilary vector to store all elements (including subElements) with ID's
    vector<SVGElement *> svg_elems_id;

    // First actual Element
    XMLElement *element = node->FirstChildElement();

    // Loop Through Elements
    for (; element != nullptr; element = element->NextSiblingElement())
        parseElement(element, svg_elements, svg_elems_id); // Parse Element
}

void parseElement(
    const XMLElement *element, vector<SVGElement *> &elementList, vector<SVGElement *> &elementListID,
    const vector<Transform> &transforms
) {
    const char *p = nullptr;                                 // Temporary Pointer Variable Declaration

    const string elemName = element->Name();                 // Get Element Name

    p               = element->Attribute("id");              // Get Element ID
    const string id = p ? p : "";                            // Element might not have an ID

    vector<Transform> elemTransformList;                     // Generate List of Transformations
    const Transform   elemTransform = getTransform(element); // Get Element Transformation
    elemTransformList.push_back(elemTransform);              // Add Element Transformation

    // Append Inherited Transformations
    // This are inserted after because inherited
    // transformations need to be applied last
    elemTransformList.insert(elemTransformList.end(), transforms.begin(), transforms.end());


    // Create Element Pointer
    SVGElement *eP = nullptr;

    // Parse Each Element Differently

    // Ellipse
    if (elemName == "ellipse") {
        // Parse Color
        Color color = parse_color(element->Attribute("fill"));

        // Parse Center and Radius
        Point center({ element->IntAttribute("cx"), element->IntAttribute("cy") });
        Point radius({ element->IntAttribute("rx"), element->IntAttribute("ry") });

        // Create Element
        eP = new Ellipse(id, elemTransformList, color, center, radius);
    }

    // Circle
    if (elemName == "circle") {
        // Parse Color
        Color color = parse_color(element->Attribute("fill"));

        // Parse Center and Radius
        Point center({ element->IntAttribute("cx"), element->IntAttribute("cy") });
        int   radius = element->IntAttribute("r");

        // Create Element
        eP = new Circle(id, elemTransformList, color, center, radius);
    }

    // PolyLine
    if (elemName == "polyline") {
        // Parse Color
        Color color = parse_color(element->Attribute("stroke"));

        // Read Points
        vector<Point> points;
        string        pStr(element->Attribute("points"));

        // Substitute possible ',' for ' ' (spaces)
        for (auto itr = pStr.begin(); itr != pStr.end(); ++itr)
            if (*itr == ',') *itr = ' ';

        // Parse Points
        istringstream issPoints(pStr);
        int           x;
        int           y;
        while (issPoints >> x >> y) points.push_back({ x, y });

        // Create Element
        eP = new PolyLine(id, elemTransformList, points, color);
    }

    // Line
    if (elemName == "line") {
        // Parse Color
        Color color = parse_color(element->Attribute("stroke"));

        // Parse Points
        Point point1 = { element->IntAttribute("x1"), element->IntAttribute("y1") };
        Point point2 = { element->IntAttribute("x2"), element->IntAttribute("y2") };

        // Create Element
        eP = new Line(id, elemTransformList, point1, point2, color);
    }

    // PolyGon
    if (elemName == "polygon") {
        // Parse Color
        Color color = parse_color(element->Attribute("fill"));

        // Read Points
        vector<Point> points;
        string        pStr(element->Attribute("points"));

        // Substitute possible ',' for ' ' (spaces)
        for (auto itr = pStr.begin(); itr != pStr.end(); ++itr)
            if (*itr == ',') *itr = ' ';

        // Parse Points
        istringstream issPoints(pStr);
        int           x;
        int           y;
        while (issPoints >> x >> y) points.push_back({ x, y });

        // Create Element
        eP = new PolyGon(id, elemTransformList, points, color);
    }

    // Rectangle
    if (elemName == "rect") {
        // Parse Color
        p           = element->Attribute("fill");
        Color color = parse_color(p);

        // Parse Origin, Width and Height
        Point origin = { element->IntAttribute("x"), element->IntAttribute("y") };
        int   width  = element->IntAttribute("width");
        int   height = element->IntAttribute("height");

        // Create Element
        eP = new Rectangle(id, elemTransformList, color, origin, width, height);
    }

    // Group
    if (elemName == "g") {
        // Create List of Children
        vector<SVGElement *> children;

        // Get FirstChild
        const XMLElement *child = element->FirstChildElement();

        // Loop Through Children
        for (; child != nullptr; child = child->NextSiblingElement())
            parseElement(child, children, elementListID, elemTransformList); // Parse Child

        // Create Element
        eP = new GroupElement(id, elemTransformList, children);
    }

    // Use
    if (elemName == "use") {
        // Get href ignoring "#" caracter
        string href(element->Attribute("href") + 1);

        // Create Copy Element Pointer
        SVGElement *copyEP;

        // Find Matching Element
        for (SVGElement *idElem : elementListID)
            if (idElem->getID() == href)
                copyEP = idElem->copy(elemTransformList); // Make a Copy of the element with extra Transformation

        // Create Use Element
        if (copyEP) eP = new UseElement(id, elemTransformList, copyEP);
    }

    // Return if no element was created
    if (!eP) return;

    // If Element has an ID add it to the List with elements who have an ID
    if (id.size()) elementListID.push_back(eP);

    // Add Element to List
    elementList.push_back(eP);
}

Transform getTransform(const XMLElement *element) {
    // Init values
    const char *p;
    int         translateX = 0;
    int         translateY = 0;
    int         scale      = 1;
    int         rotate     = 0;
    int         originX    = 0;
    int         originY    = 0;

    // Get Transformation Attribute String
    p             = element->Attribute("transform");
    string traStr = p ? p : "a"; // "a" because later First caracter of string will be read

    // Substitute possible ',' for ' ' (spaces)
    for (auto itr = traStr.begin(); itr != traStr.end(); ++itr)
        if (*itr == ',') *itr = ' ';

    // Create sStream from substring inside Parenthesis
    size_t        start = traStr.find_first_of('(') + 1; // Will become Zero if not found
    size_t        end   = traStr.find_first_of(')');
    istringstream traStream(start ? traStr.substr(start, end - start) : "");

    // Parse Values According to Type of Transformation
    switch (traStr[0]) {
    case 't': // Translate
        traStream >> translateX;
        traStream >> translateY;
        break;
    case 'r': // Rotate
        traStream >> rotate;
        break;
    case 's': // Scale
        traStream >> scale;
        break;
    default: break;
    }

    // Get Element Transformation Origin
    p                      = element->Attribute("transform-origin");
    const string originStr = p ? p : "";

    // Parse Origin
    if (originStr.size()) {
        istringstream originStream(originStr);
        originStream >> originX;
        originStream >> originY;
    }

    return Transform(translateX, translateY, rotate, scale, originX, originY);
}


} // namespace svg