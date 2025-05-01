#ifndef __domino_h__
#define __domino_h__

#include <iostream>
#include <string>
#include <vector>

struct domino {
    int n1;
    int n2;

    void print() { std::cout << n1 << "|" << n2; }

    bool operator==(domino a) const {
        return (a.n1 == n1 and a.n2 == n2) or (a.n1 == n2 and a.n2 == n1);
    }

    domino flip() const { return domino{ n2, n1 }; }
};

struct player {
    unsigned long       points;
    std::string         name;
    std::vector<domino> hand;

    void print() {
        std::cout << name << "\t - " << points << "pts : ";
        std::cout << "[";
        for (domino d : hand) std::cout << " " << d.n1 << "|" << d.n2 << " ,";
        std::cout << "]" << std::endl;
    }

    void printPoints() { std::cout << name << " - " << points << "pts" << std::endl; }
};

struct game {
    int                 round;
    int                 pTurn;
    player              players[4];
    std::vector<domino> table;

    void print() {
        std::cout << " /// PLAYERS \\\\\\" << std::endl;
        for (int i = 0; i < 4; ++i) players[i].print();
        std::cout << std::endl << std::endl;
        std::cout << " /// BOARD \\\\\\" << std::endl;
        std::cout << "[";
        for (domino d : table) std::cout << " " << d.n1 << "|" << d.n2 << " ,";
        std::cout << "]" << std::endl << std::endl;
    }
};


#endif
