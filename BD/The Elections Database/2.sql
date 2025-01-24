-- What were the results obtained by each party in the parish of Mancelos? List the acronym of each party and the number of votes it got, descending on the number of votes and ascendingly by acronym.

SELECT V.PARTY, V.VOTES
FROM VOTINGS V
JOIN PARISHES P ON P.CODE = V.PARISH
WHERE P.NAME = 'Mancelos'
ORDER BY V.VOTES DESC, V.PARTY;
