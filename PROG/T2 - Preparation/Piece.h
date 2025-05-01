#ifndef PIECE_H
#define PIECE_H

#include <sstream>
#include <string>
using namespace std;

class Piece {
  public:
    // Constructor with parameters
    Piece(int left, int right) : left_(left), right_(right) {}

    // Determine if this piece can be placed on the left of other
    bool can_be_left_to(const Piece &other) const;
    // Determine if this piece can be placed on the right of other
    bool can_be_right_to(const Piece &other) const;

    // Accessors
    int get_left() const { return left_; }

    int get_right() const { return right_; }

    string to_string() const {
        ostringstream out;
        out << left_ << ':' << right_;
        return out.str();
    }

  private:
    // The points in the two sides of the piece
    int left_, right_;
};

#endif
