% Pilots
% pilot(X)
% X is a Pilot.
pilot(lamb).
pilot(besenyei).
pilot(chambliss).
pilot(maclean).
pilot(mangold).
pilot(jones).
pilot(bonhomme).

% Teams
% team(X, Y).
% X is from team Y.
team(lamb, breitling).
team(besenyei, red_bull).
team(chambliss, red_bull).
team(maclean, mediterranean_racing_team).
team(mangold, cobra).
team(jones, matador).
team(bonhomme, matador).

% Aircraft
% plane(X, Y)
% X pilots plane Y
plane(lamb, mx2).
plane(besenyei, edge540).
plane(chambliss, edge540).
plane(maclean, edge540).
plane(mangold, edge540).
plane(jones, edge540).
plane(bonhomme, edge540).

% Circuits
% circuit(X)
% X is a circuit
circuit(istanbul).
circuit(budapest).
circuit(porto).

% Winners
% won(X, Y)
% X won in circuit Y
won(jones, porto).
won(mangold, budapest).
won(mangold, istanbul).

% Gates
% gates(X, Y)
% Circuit X has Y gates
gates(istanbul, 9).
gates(budapest, 6).
gates(porto, 5).

% Team wins
% team_won(X, Y)
% Team X won circuit Y
team_won(Team, Circuit) :-
    won(Pilot, Circuit),
    team(Pilot, Team).

% ----------------------------
% Questions
% ----------------------------

% Who won the race in Porto?
% won(Pilot, porto).

% What team won the race in Porto?
% team_won(Team, porto).

% Which circuits have nine gates?
% gates(Circuit, 9).

% Which pilots do not fly an Edge540?
% pilot(Pilot), plane(Pilot, _Plane), _Plane \= edge540.

% Which pilots have won more than one circuit?
% won(Pilot, _CircuitA), won(Pilot, _CircuitB), _CircuitA \= _CircuitB.

% What is the plane piloted by the pilot who won the race in Porto?
% won(_Pilot, porto), plane(_Pilot, Plane).
