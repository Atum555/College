-- List the district name, the number of voters and the number of abstentions, but only in the case where the number of abstentions in the district is higher than 75% of the number of voters. Order by district name.

SELECT D.NAME, P.VOTERS, P.ABSTENTIONS
FROM PARTICIPATIONS P
JOIN DISTRICTS D ON D.CODE = P.DISTRICT
WHERE P.ABSTENTIONS > 0.75 * P.VOTERS
ORDER BY D.NAME;
