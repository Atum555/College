-- What was the party that had the highest number of votes in a single parish? List the acronym of the party, the name of the parish and the number of votes it obtained in that parish.

SELECT V.PARTY, P.NAME, V.VOTES
FROM VOTINGS V
JOIN PARISHES P ON P.CODE = V.PARISH
WHERE V.VOTES = (SELECT MAX(VOTES) FROM VOTINGS);
