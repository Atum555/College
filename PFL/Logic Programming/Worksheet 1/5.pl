% Jobs
% job(X, Y)
% Y has job X
job(technician, eleuterio).
job(technician, juvenaldo).
job(analyst, leonilde).
job(analyst, marciliano).
job(engineer, osvaldo).
job(engineer, porfirio).
job(engineer, reginaldo).
job(supervisor, sisnando).
job(chief_supervisor, gertrudes).
job(secretary, felismina).
job(director, asdrubal).

% Supervisions
% supervised_by(X, Y)
% X is supervised by Y
supervised_by(technician, engineer).
supervised_by(engineer, supervisor).
supervised_by(analyst, supervisor).
supervised_by(supervisor, chief_supervisor).
supervised_by(chief_supervisor, director).
supervised_by(secretary, director).

% ----------------------------
% Questions 1
% ----------------------------

% supervised_by(analyst, _X), job(_X, sisnando).
% Are analysts supervised by sisnando?

% supervised_by(technician, _X), supervised_by(_X, Y).
% How supervises the supervisors of technicians? 

% job(J, P), supervised_by(J, supervisor).
% Who is supervised by 'supervisor' and what jobs do they have?

% job(_J, asdrubal), supervised_by(_S, _J), job(_S, P).
% Who is supervised by asdrubal?

% ----------------------------
% Questions 2
% ----------------------------

% Is X a direct supervisor of Y?
supervisor(X, Y) :- supervised_by(Y, X).
% supervisor(X, Y).

% Are X and Y supervised by people with the same job?
% supervised_by(X, _A), supervised_by(Y, _A).

% Is X responsible for supervising more than one job?
% supervised_by(_A, X), supervised_by(_B, X), _A \= _B.

% Is X a supervisor of Y’s supervisor?
% supervised_by(Y, _A), supervised_by(_A, X).
