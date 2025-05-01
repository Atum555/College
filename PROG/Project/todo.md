## SVGElements.hpp

-   SVGElement (id, transform)
    -   Use  (idCopy)                               - ????

    -   Group (vector SVGElement*)                  - VASCO

    -   Ellipse (cx, cy, rx, ry, fill)              - FRANCISCA
        -   Circle (r) (Same Radius)

    -   Poly (Points "int,int")                     - CLAUDIO
        -   PolyLine (Stroke)
            -   Line (Only 2 points)

        -   Polygon (Fill)
            -   Rect (Only 4 points, start, width and height)

## SVGElements.cpp

-   Implement draw functions
    - Group                         - VASCO
    - Ellipse                       - FRANCISCA
    - Poly                          - CLAUDIO

## readSVG.cpp

-   Read SVG                                                - VASCO

    -   Loop Through each element and its children         
    -   Parse the element's type
    -   Parse the element's attributes

-   Return List of Pointers to Elements
