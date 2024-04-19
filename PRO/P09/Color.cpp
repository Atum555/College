#include "Color.h"

const Color Color::RED(255, 0, 0);
const Color Color::GREEN(0, 255, 0);
const Color Color::BLUE(0, 0, 255);
const Color Color::BLACK(0, 0, 0);
const Color Color::WHITE(255, 255, 255);

Color::Color(unsigned char red, unsigned char green, unsigned char blue)
    : red_(red), green_(green), blue_(blue) {}

Color::Color(const Color &c) : Color(c.red_, c.green_, c.blue_) {}

unsigned char Color::red() const { return red_; }

unsigned char Color::green() const { return green_; }

unsigned char Color::blue() const { return blue_; }

bool Color::equal_to(const Color &other) const {
    return other.red_ == red_ and other.green_ == green_
           and other.blue_ == blue_;
}

void Color::invert() {
    red_   = 255 - red_;
    green_ = 255 - green_;
    blue_  = 255 - blue_;
}
