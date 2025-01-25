-- How many votes had each party globally?
-- As we want the global result, the administrative division is irrelevant.
-- List the acronym of the party and the total number of votes, name VOTES.
-- Order ascendantly by the acronym.

SELECT V.PARTY, SUM(V.VOTES) AS VOTES
FROM VOTINGS V
GROUP BY V.PARTY
ORDER BY V.PARTY;
