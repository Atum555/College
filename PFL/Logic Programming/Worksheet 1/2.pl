teaches(algorithms, adalberto).
teaches(databases, bernardete).
teaches(compilers, capitolino).
teaches(statistics, diogenes).
teaches(networks, ermelinda).

attends(algorithms, alberto).
attends(algorithms, bruna).
attends(algorithms, cristina).
attends(algorithms, diogo).
attends(algorithms, eduarda).

attends(databases, antonio).
attends(databases, bruno).
attends(databases, cristina).
attends(databases, duarte).
attends(databases, eduardo).

attends(compilers, alberto).
attends(compilers, bernardo).
attends(compilers, clara).
attends(compilers, diana).
attends(compilers, eurico).

attends(statistics, antonio).
attends(statistics, bruna).
attends(statistics, claudio).
attends(statistics, duarte).
attends(statistics, eva).

attends(networks, alvaro).
attends(networks, beatriz).
attends(networks, claudio).
attends(networks, diana).
attends(networks, eduardo).

isTeacherOf(X, Y) :- teaches(_A, X), attends(_A, Y).

colleagues(X, Y) :- 
    teaches(_A, X), 
    teaches(_B, Y), 
    X \= Y.

colleagues(X, Y) :-
    attends(_A, X), attends(_A, Y),
    X \= Y.

attendsMoreThanOneClass(X) :-
    attends(_A, X),
    attends(_B, X),
    _A \= _B.
