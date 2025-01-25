-- What is the district with the most municipalities? List the name of the district and the number of municipalities (NR_MUN).

SELECT D.NAME, COUNT(*) AS NR_MUN
FROM DISTRICTS D
JOIN MUNICIPALITIES M ON M.DISTRICT = D.CODE
GROUP BY D.CODE
ORDER BY NR_MUN DESC
LIMIT 1;
