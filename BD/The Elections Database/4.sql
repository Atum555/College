-- What is the code and the name of the district of the parish of Mancelos?

SELECT D.CODE, D.NAME
FROM DISTRICTS D
JOIN MUNICIPALITIES M ON M.DISTRICT = D.CODE
JOIN PARISHES P ON P.MUNICIPALITY = M.CODE
WHERE P.NAME = 'Mancelos';
