-- What are the municipalities of the same district with the same number of parishes? List the code of the district, the names of the municipalities and the common number of parishes, without repetitions such as (A,B) and (B,A). Order ascendantly on the district's code, name of the first municipality and name of the second municipality.

WITH PARISHES_PER_MUNI AS (
    SELECT M.DISTRICT, M.NAME, COUNT(*) AS PARISHES
    FROM MUNICIPALITIES M
    JOIN PARISHES P ON P.MUNICIPALITY = M.CODE
    GROUP BY M.CODE
)

SELECT A.DISTRICT AS code, A.NAME AS namea, B.NAME AS nameb, A.PARISHES AS c
FROM PARISHES_PER_MUNI A, PARISHES_PER_MUNI B
WHERE 
    A.DISTRICT = B.DISTRICT AND 
    A.PARISHES = B.PARISHES AND 
    A.NAME < B.NAME
ORDER BY code, namea, nameb;
