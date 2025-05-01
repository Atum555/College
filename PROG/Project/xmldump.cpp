#include "external/tinyxml2/tinyxml2.h"

using namespace tinyxml2;

#include <iostream>

void dump(XMLElement *elem, int indentation) {
    for (int i = 0; i < indentation; i++) std::cout << " ";

    std::cout << elem->Name() << " --> [";

    for (const XMLAttribute *attr = elem->FirstAttribute(); attr != nullptr;
         attr                     = attr->Next())
        std::cout << " " << attr->Name() << "=\"" << attr->Value() << "\"";

    std::cout << " ] " << std::endl;
    for (XMLElement *child = elem->FirstChildElement(); child != nullptr;
         child             = child->NextSiblingElement()) {
        dump(child, indentation + 2);
    }
}

int main(int argc, char **argv) {
    XMLDocument doc;
    if (argc != 2) {
        std::cout << "Usage: xmldump filename";
    } else {
        doc.LoadFile(argv[1]);
        dump(doc.RootElement(), 0);
    }
    return 0;
}