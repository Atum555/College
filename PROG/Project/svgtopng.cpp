#include "SVGElements.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Usage: svgtopng in_file.svg out_file.png" << std::endl;
    } else {
        std::cout << "Performing conversion ... " << argv[1] << " --> "
                  << argv[2] << std::endl;
        svg::convert(argv[1], argv[2]);
        std::cout << "Done!" << std::endl;
    }
    return 0;
}