-- What are the parishes of region 'M' where the party 'PSN' obtained zero votes? List the code and name of the parish, in ascending order on the code.

SELECT P.CODE, P.NAME
FROM VOTINGS V
JOIN PARISHES P ON P.CODE = V.PARISH
JOIN MUNICIPALITIES M ON M.CODE = P.MUNICIPALITY
JOIN DISTRICTS D ON D.CODE = M.DISTRICT
WHERE D.REGION = 'M' AND V.VOTES = 0 AND V.PARTY = 'PSN'
ORDER BY P.CODE;
