-- How many parishes have “Vilar” on the name?

SELECT count(*)
FROM PARISHES P
WHERE P.NAME LIKE '%Vilar%';
