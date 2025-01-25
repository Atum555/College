-- Which is the municipality with the most parishes? List the name of the municipality and its number of parishes (NR_PAR).

SELECT M.NAME, COUNT(*) AS NR_PAR
FROM PARISHES P
JOIN MUNICIPALITIES M ON M.CODE = P.MUNICIPALITY
GROUP BY M.CODE
ORDER BY NR_PAR DESC
LIMIT 1;
