-- What is the average number of parishes per municipality? Round this AVERAGE with two decimal digits.

WITH PARISHES_PER_MUN AS (
    SELECT P.MUNICIPALITY, COUNT(*) AS PARISHES
    FROM PARISHES P
    GROUP BY P.MUNICIPALITY
)

SELECT ROUND(AVG(P.PARISHES),2) AS AVERAGE  
FROM PARISHES_PER_MUN P;
