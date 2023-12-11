#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

struct domino 
{
    int n1;
    int n2;
};

struct player
{
    char name[50];
    int handS;
    struct domino hand[7];
};

struct game
{
    struct player players[4];
    int round;
    int pTurn;
    struct domino table[8*4];
};

void shuffle(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void pTable(struct domino t[], int r) {
    printf("Mesa: ");
    for (int i = 0; i < r-1; i++) {
        printf("%d%d ", t[i].n1, t[i].n2);
    }
    printf("\n");
}

void pPlaHands(struct player p) {
    printf("%s ", p.name);
    for (int i = 0; i < p.handS; i++) {
        printf("%d", p.hand[i].n1);
        printf("%d ", p.hand[i].n2);
    }
    printf("\n");
}

void pPlaPoints(struct player p) {
    printf("%s ", p.name);
    int c = 0;
    for (int i = 0; i < p.handS; i++) {
        c += p.hand[i].n1 + p.hand[i].n2;
    }
    printf("%d pontos.\n", c);
}

void shiftTable(struct domino *t, int round) {
    struct domino a;
    for (int i = round; i > 0; i--) {
        a = t[i];
        t[i] = t[i-1];
        t[i-1] = a;
    }
}

void addDtoTable(struct domino *t, int round, struct domino d, bool reversed, bool start) {
    if (reversed) {
        int a = d.n1;
        d.n1 = d.n2;
        d.n2 = a;
    }
    if (!start) {
        t[round-1] = d;
    } else {
        shiftTable(t, round);
        t[0] = d;
    }
}

void removeDfromP(struct player *p, int pindex, int dindex) {
    p[pindex].handS--;
    if (p[pindex].handS > dindex) {
        for (size_t i = dindex; i < p[pindex].handS; i++) {
            p[pindex].hand[i] = p[pindex].hand[i+1];
        }
    }
}

int main() {
    srand(time(NULL)); // Set Random Generator Seed
    const char *names[4] = {"Beatriz", "Carlos", "Ricardo", "Miguel"};


    // Generate pieces Indexes
    int pieceIndexes[28];
    for (int i = 0; i < 28; i++) { pieceIndexes[i] = i; }
    shuffle(pieceIndexes, 28);

    // Generate Pieces
    struct domino pieces[28];
    int c = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < i+1; j++) {
            pieces[c].n1 = j;
            pieces[c].n2 = i;
            c++;
        }
        
    }


    // Creating the game and adding players
    struct game theGame = {0};

    c = 0;
    for (int i = 0; i < 4; i++) {
        struct player p;            // Creating player
        strcpy(p.name, names[i]);   // Adding the name
        p.handS = 7;                // Setting hand size
        
        // Adding hand to the player
        for (int j = 0; j < 7; j++) {
            p.hand[j] = pieces[pieceIndexes[c]];  // Add domino to the players hand
            c++;
        }
        theGame.players[i] = p;     // Adding player to the game
    }

    // Game Loop
    while (1) {
        theGame.round += 1;
        theGame.pTurn = (theGame.pTurn +1) % 4;
        printf("***** Jogada %d *****\n", theGame.round);               // Print Round
        pTable(theGame.table, theGame.round);                           // Print the Table
        for (int i = 0; i < 4; i++) { pPlaHands(theGame.players[i]); }  // Print Players Hands

        // First
        if (theGame.round == 1) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 7; j++) {
                    if (theGame.players[i].hand[j].n1 == 6 && theGame.players[i].hand[j].n2 == 6) {
                        theGame.pTurn = i;
                        addDtoTable(theGame.table, theGame.round, theGame.players[i].hand[j], false, false);
                        removeDfromP(theGame.players, i, j);
                        printf("-> %s joga 66 no início!\n", theGame.players[i].name);
                    }
                }
            }
            char ignore;
            scanf("%c", &ignore);
            continue;
        }

        // Play
        int first = theGame.table[0].n1;
        int last = theGame.table[theGame.round-2].n2;
        bool play = false;
        for (int i = 0; i < 4; i++) {
            if (play) { break; }
            for (int j = 0; j < theGame.players[(theGame.pTurn + i) % 4].handS; j++) {
                if (play) { break; }
                //printf("%s for %d %d\n", theGame.players[(theGame.pTurn + i) % 4].name, i, j);
                if (theGame.players[(theGame.pTurn + i) % 4].hand[j].n1 == first) {
                    addDtoTable(theGame.table, theGame.round, theGame.players[(theGame.pTurn + i) % 4].hand[j], true, true);
                    int n1 = theGame.players[(theGame.pTurn + i) % 4].hand[j].n1;
                    int n2 = theGame.players[(theGame.pTurn + i) % 4].hand[j].n2;
                    printf("-> %s joga %d%d no início!\n", theGame.players[(theGame.pTurn + i) % 4].name, n1, n2);
                    removeDfromP(theGame.players, theGame.pTurn + i, j);
                    play = true;
                } else if (theGame.players[(theGame.pTurn + i) % 4].hand[j].n2 == first) {
                    addDtoTable(theGame.table, theGame.round, theGame.players[(theGame.pTurn + i) % 4].hand[j], false, true);
                    int n1 = theGame.players[(theGame.pTurn + i) % 4].hand[j].n1;
                    int n2 = theGame.players[(theGame.pTurn + i) % 4].hand[j].n2;
                    printf("-> %s joga %d%d no início!\n", theGame.players[(theGame.pTurn + i) % 4].name, n1, n2);
                    removeDfromP(theGame.players, theGame.pTurn + i, j);
                    play = true;
                } else if (theGame.players[(theGame.pTurn + i) % 4].hand[j].n1 == last) {
                    addDtoTable(theGame.table, theGame.round, theGame.players[(theGame.pTurn + i) % 4].hand[j], false, false);
                    int n1 = theGame.players[(theGame.pTurn + i) % 4].hand[j].n1;
                    int n2 = theGame.players[(theGame.pTurn + i) % 4].hand[j].n2;
                    printf("-> %s joga %d%d no fim!\n", theGame.players[(theGame.pTurn + i) % 4].name, n1, n2);
                    removeDfromP(theGame.players, theGame.pTurn + i, j);
                    play = true;
                } else if (theGame.players[(theGame.pTurn + i) % 4].hand[j].n2 == last) {
                    addDtoTable(theGame.table, theGame.round, theGame.players[(theGame.pTurn + i) % 4].hand[j], true, false);
                    int n1 = theGame.players[(theGame.pTurn + i) % 4].hand[j].n1;
                    int n2 = theGame.players[(theGame.pTurn + i) % 4].hand[j].n2;
                    printf("-> %s joga %d%d no fim!\n", theGame.players[(theGame.pTurn + i) % 4].name, n1, n2);
                    removeDfromP(theGame.players, theGame.pTurn + i, j);
                    play = true;
                }
            }
        }
        if (!play) { break; }
        char ignore;
        scanf("%c", &ignore);
    }
    printf("-> FIM DE JOGO!\n\n ***** RESULTADOS: *****\n");
    for (int i = 0; i < 4; i++) { pPlaPoints(theGame.players[i]); }  // Print Players Points
    return 0;
}