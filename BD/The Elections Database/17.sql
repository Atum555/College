-- Was there any party winning on all parishes of any municipality of the district of Porto? List the code and name of the municipality and the acronym of the party. Order ascendantly by the code of the municipality and the acronym of the party.

WITH WINNER_PARTY_PER_PARISH AS (
    SELECT V.PARISH, V.PARTY
    FROM VOTINGS V
    WHERE V.VOTES <> 0 AND V.VOTES = (
        SELECT MAX(VOTES)
        FROM VOTINGS
        WHERE PARISH = V.PARISH
    )
)

SELECT M.CODE, M.NAME, W.PARTY
FROM WINNER_PARTY_PER_PARISH W
JOIN PARISHES P ON P.CODE = W.PARISH
JOIN MUNICIPALITIES M ON M.CODE = P.MUNICIPALITY
JOIN DISTRICTS D ON D.CODE = M.DISTRICT
WHERE D.NAME = 'Porto'
GROUP BY M.CODE, W.PARTY
HAVING COUNT(*) = (
    SELECT COUNT(*)
    FROM PARISHES
    WHERE MUNICIPALITY = M.CODE
)
ORDER BY M.CODE, W.PARTY;
