-- What is the total of votes of each of the 5 major parties? List the acronym and the total of votes as TOTAL, ordered decreasingly on the number of votes.

SELECT V.PARTY, SUM(V.VOTES) AS TOTAL
FROM VOTINGS V
GROUP BY V.PARTY
ORDER BY TOTAL DESC
LIMIT 5;
