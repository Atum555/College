#include "Domino.h"
#include "Piece.h"

using namespace std;

bool Piece::can_be_left_to(const Piece &other) const { return right_ == other.left_; }

bool Piece::can_be_right_to(const Piece &other) const { return left_ == other.right_; }

const Piece &Domino::left() const { return pieces_.front(); }

const Piece &Domino::right() const { return pieces_.back(); }

bool Domino::place_left(const Piece &p) {
    if (p.can_be_left_to(left())) {
        pieces_.push_front(p);
        return true;
    }
    return false;
}

bool Domino::place_right(const Piece &p) {
    if (p.can_be_right_to(right())) {
        pieces_.push_back(p);
        return true;
    }
    return false;
}