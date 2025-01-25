-- What are the parishes of the municipality of Espinho? List the code and name of each parish, order ascendantly by the code.

SELECT P.CODE, P.NAME
FROM MUNICIPALITIES M
JOIN PARISHES P ON P.MUNICIPALITY = M.CODE
WHERE M.NAME = 'Espinho'
ORDER BY P.CODE;
