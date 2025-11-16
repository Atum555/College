% Layer 1
female(grace).
male(frank).
female(dede).
male(jay).
female(gloria).
male(javier).
female(barb).
male(merle).

% Layer 2
male(phil).
female(claire).
male(mitchell).
male(joe).
male(manny).
male(cameron).
female(pameron).
male(bo).

% Layer 3
male(dylan).
female(haley).
female(alex).
male(luke).
female(lily).
male(rexford).
male(calhoun).

% Layer 4
male(george).
female(poppy).

% Layer 1 - 1
parent(grace, phil).
parent(frank, phil).

% Layer 1 - 2
parent(dede, claire).
parent(jay, claire).
parent(dede, mitchell).
parent(jay, mitchell).

% Layer 1 - 3
parent(gloria, joe).
parent(jay, joe).

% Layer 1 - 4
parent(gloria, manny).
parent(javier, manny).

% Layer 1 - 5
parent(merle, cameron).
parent(barb, cameron).
parent(merle, pameron).
parent(barb, pameron).

% Layer 2 - 1
parent(phil, haley).
parent(claire, haley).
parent(phil, alex).
parent(claire, alex).
parent(phil, luke).
parent(claire, luke).

% Layer 2 - 2
parent(mitchell, lily).
parent(cameron, lily).
parent(mitchell, rexford).
parent(cameron, rexford).

% Layer 2 - 3
parent(pameron, calhoun).
parent(bo, calhoun).

% Layer 3 - 1
parent(haley, george).
parent(dylan, george).
parent(haley, poppy).
parent(dylan, poppy).

% Relations
father(X, Y) :-   male(X), parent(X, Y).
mother(X, Y) :- female(X), parent(X, Y).

grandparent(X, Y) :- parent(X, A), parent(A, Y).
grandfather(X, Y) :-   male(X), grandparent(X, Y).
grandmother(X, Y) :- female(X), grandparent(X, Y).

halfSiblings(X, Y) :- 
    parent(_A, X), parent(_A, Y), 
    parent(_B, X), 
    parent(_C, Y), 
    X \= Y,
    _A \= _B, _A \= _C, 
    _B \= _C.

halfBrother(X, Y) :-   male(X), halfSiblings(X, Y).
halfSister(X, Y)  :- female(X), halfSiblings(X, Y).

siblings(X, Y) :- 
    parent(_A, X), parent(_A, Y),
    parent(_B, X), parent(_B, Y),
    X \= Y,
    _A \= _B.

brother(X, Y) :-   male(X), siblings(X, Y).
sister(X, Y)  :- female(X), siblings(X, Y).

cousins(X, Y) :- 
    parent(_A, X), 
    parent(_B, Y),
    siblings(_A, _B).

uncle(X, Y) :- father(X, _A), cousins(_A, Y).
aunt(X, Y)  :- mother(X, _A), cousins(_A, Y).
