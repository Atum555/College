#include <iostream>

int main() {
    char str;
    std::cin >> str;
    if (('a' <= str && str <= 'z') or ('A' <= str && str <= 'Z')) {
        std::cout << "LETTER" << std::endl;
    } else if ('0' <= str && str <= '9') {
        std::cout << "DIGIT" << std::endl;
    } else {
        std::cout << "OTHER" << std::endl;
    }
    return 0;
}
