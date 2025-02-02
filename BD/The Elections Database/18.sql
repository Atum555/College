-- Was there any party winning on all municipalities of a district? List the code and name of the district and the acronym of the party. Order ascendantly by code.

WITH 
VOTES_PER_PARTY_PER_MUNI AS (
    SELECT P.MUNICIPALITY, V.PARTY, SUM(V.VOTES) AS VOTES
    FROM VOTINGS V
    JOIN PARISHES P ON P.CODE = V.PARISH
    GROUP BY P.MUNICIPALITY, V.PARTY
),
WINNER_PARTY_PER_MUNI AS (
    SELECT MUNICIPALITY, PARTY
    FROM VOTES_PER_PARTY_PER_MUNI V
    WHERE (MUNICIPALITY, VOTES) IN (
        SELECT MUNICIPALITY, MAX(VOTES)
        FROM VOTES_PER_PARTY_PER_MUNI
        GROUP BY MUNICIPALITY    
    )
)

SELECT D.CODE, D.NAME, W.PARTY
FROM WINNER_PARTY_PER_MUNI W
JOIN MUNICIPALITIES M ON M.CODE = W.MUNICIPALITY
JOIN DISTRICTS D ON D.CODE = M.DISTRICT
GROUP BY D.CODE, W.PARTY
HAVING (D.CODE, COUNT(*)) IN (
    SELECT DISTRICT, COUNT(*)
    FROM MUNICIPALITIES
    GROUP BY DISTRICT
);
