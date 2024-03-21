#include "domino.h"
#include <algorithm>
#include <random>
#include <string>
#include <vector>

void createPlayer(player &player, const char *name) {
    player.points = 0;
    player.name   = name;
    player.hand.clear();
}

game *createGame(const char *names[]) {
    game *g = new game;
    // Add Players
    for (int i = 0; i < 4; ++i) createPlayer(g->players[i], names[i]);

    // Generate Pieces
    std::vector<domino> pieces;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < i + 1; j++) pieces.push_back(domino{ j, i });

    // Shuffle Pieces
    std::shuffle(
        std::begin(pieces), std::end(pieces), std::default_random_engine(time(NULL))
    );

    // Assign pieces
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 7; ++j)
            g->players[i].hand.push_back(pieces[i * 7 + j]);

    g->round = 0;
    g->pTurn = -1;
    return g;
}

void playPiece(game *g, player *p, domino d) {
    // Print Move
    std::cout << " -> " << p->name << " joga ";
    d.print();
    std::cout << std::endl << std::endl << std::endl;

    // Add Point to Player
    p->points++;

    // Remove Piece from Player hand
    for (size_t i = 0; i < p->hand.size(); ++i)
        if (p->hand[i] == d) {
            p->hand.erase(p->hand.begin() + i);
            break;
        }

    // Add Piece to Board
    if (!g->table.size()) {
        g->table.push_back(d); // Empty Board
        return;
    }

    int first = g->table[0].n1;
    int last  = g->table[g->table.size() - 1].n2;

    if (d.n1 == first) g->table.insert(g->table.begin(), d.flip());
    else if (d.n1 == last) g->table.insert(g->table.end(), d);
    else if (d.n2 == first) g->table.insert(g->table.begin(), d);
    else if (d.n2 == last) g->table.insert(g->table.end(), d.flip());
}

int main() {
    // Creating the game
    const char *names[] = { "Beatriz", "Carlos", "Ricardo", "Miguel" };
    game       *g       = createGame(names);

    // Game Loop
    while (true) {
        g->round++;
        g->pTurn = (g->pTurn + 1) % 4;

        // Print Round Number
        std::cout << "                     "
                  << "/////  Jogada " << g->round << "  \\\\\\\\\\"
                  << std::endl;
        // Print Players Hands
        g->print();

        // First Round
        if (g->round == 1) {
            for (int i = 0; i < 4; i++)
                for (domino d : g->players[i].hand)
                    // Play 6|6 piece
                    if (d.n1 == 6 and d.n2 == 6) {
                        g->pTurn = (g->pTurn + i) % 4;
                        playPiece(g, &g->players[i], domino{ 6, 6 });
                    }
            std::cin.ignore();
            continue;
        }


        // Play
        int  first  = g->table[0].n1;
        int  last   = g->table[g->table.size() - 1].n2;
        bool played = false;
        // Loop Through Players
        for (int i = 0; i < 4; i++) {
            if (played) break;

            player *p = &g->players[(g->pTurn + i) % 4];

            // Loop through Pieces
            for (int j = 0; j < p->hand.size(); j++) {
                if (played) { break; }

                domino d = p->hand[j];

                if (d.n1 == first or d.n1 == last or d.n2 == first
                    or d.n2 == last) {
                    g->pTurn = (g->pTurn + i) % 4;
                    played   = true;
                    playPiece(g, p, d);
                }
            }
        }

        if (!played) break;
        std::cin.ignore();
    }

    // End Game
    std::cout << "-> FIM DE JOGO!" << std::endl
              << std::endl
              << "                     "
              << "/////  RESULTADOS  \\\\\\\\\\" << std::endl;

    // Print Players Points
    for (int i = 0; i < 4; i++) g->players[i].printPoints();
    return 0;
}