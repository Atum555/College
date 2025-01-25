-- What are the names of the municipalities of the district with the higher number of voters?
-- Order ascendantly by the name of the municipality.

SELECT M.NAME
FROM PARTICIPATIONS P
JOIN DISTRICTS D ON D.CODE = P.DISTRICT
JOIN MUNICIPALITIES M ON M.DISTRICT = D.CODE
WHERE P.VOTERS = (SELECT MAX(VOTERS) FROM PARTICIPATIONS)
ORDER BY M.NAME;
