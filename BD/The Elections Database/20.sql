-- Which parties had zero votes on all parishes of a municipality? List the acronym and the name of the municipality. Order ascendantly by the acronym and the name of the municipality.

SELECT V.PARTY, M.NAME
FROM VOTINGS V
JOIN PARISHES P ON P.CODE = V.PARISH
JOIN MUNICIPALITIES M ON M.CODE = P.MUNICIPALITY
GROUP BY V.PARTY, M.CODE
HAVING SUM(V.VOTES) = 0
ORDER BY V.PARTY, M.NAME;
