#ifndef DOMINO_H
#define DOMINO_H

#include "Piece.h"
#include <list>

using namespace std;

class Domino {
  public:
    // Constructor with parameters
    Domino(const list<Piece> &initial) : pieces_(initial) {}

    // Get the left end of the domino line
    const Piece &left() const;
    // Get the right end of the domino line
    const Piece &right() const;
    // Place piece in the left end
    bool         place_left(const Piece &p);
    // Place piece in the right end
    bool         place_right(const Piece &p);

    // Display the domino line of pieces
    string to_string() const {
        string s("[");
        for (auto p : pieces_) s.append(" ").append(p.to_string());
        s.append(" ]");
        return s;
    }

  private:
    // The line of played pieces "on the table"
    list<Piece> pieces_;
};

#endif
