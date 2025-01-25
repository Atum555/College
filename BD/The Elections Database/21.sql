-- What are the differences on the percentages of seats and of votes at the global level? List the acronym of the party and a column DIFFERENCE, ordered by DIFFERENCE decreasingly.

-- Note: to force an arithmetic operation between integer numbers to result in a real number, multiply one of the integers by 1.0.

WITH 
VOTES_PER_PARTY AS (
    SELECT PARTY, SUM(VOTES) AS VOTES
    FROM VOTINGS V
    GROUP BY PARTY
),
SEATS_PER_PARTY AS (
    SELECT PARTY, SUM(SEATS) AS SEATS
    FROM LISTS
    GROUP BY PARTY
)

SELECT 
    V.PARTY AS party,
    (
        (S.SEATS *1.0 / (SELECT SUM(SEATS) FROM LISTS)) -
        (V.VOTES *1.0/ (SELECT SUM(VOTERS) FROM PARTICIPATIONS))
    )
    * 100.0 AS DIFFERENCE 
FROM VOTES_PER_PARTY V
JOIN SEATS_PER_PARTY S ON S.PARTY = V.PARTY
ORDER BY DIFFERENCE DESC;
