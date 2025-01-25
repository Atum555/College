-- Compute, in an approximate way, dividing the total votes of a party in the district by the total number of seats of that party in the same district, how many votes are necessary to elect a deputy on each district. List the acronym of the party, the name of the district, the sum of the votes (VOTES), the number of seats and the ratio of VOTES_PER_DEPUTY, rounded as an integer. Order  by this last column.

-- Note: to compute more accuratly this number of votes it would be necessary to implement the Hondt method, which is used on these elections.

WITH VOTES_SEATS_PER_PARTY_PER_DISTRICT AS (
    SELECT V.PARTY, D.NAME, SUM(V.VOTES) AS VOTES, L.SEATS
    FROM VOTINGS V
    JOIN PARISHES P ON P.CODE = V.PARISH
    JOIN MUNICIPALITIES M ON M.CODE = P.MUNICIPALITY
    JOIN DISTRICTS D ON D.CODE = M.DISTRICT
    JOIN LISTS L ON L.PARTY = V.PARTY AND L.DISTRICT = D.CODE
    WHERE SEATS <> 0
    GROUP BY V.PARTY, D.CODE
)

SELECT *, FLOOR(VOTES * 1.0 / SEATS) AS VOTES_PER_DEPUTY
FROM VOTES_SEATS_PER_PARTY_PER_DISTRICT
ORDER BY VOTES_PER_DEPUTY;
