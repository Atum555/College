-- How many seats obtained each party on the district of the parish of Mancelos, in decreasing order of the number of seats? List the acronym and the number of seats.

SELECT L.PARTY, L.SEATS
FROM LISTS L
JOIN DISTRICTS D ON D.CODE = L.DISTRICT
JOIN MUNICIPALITIES M ON M.DISTRICT = D.CODE
JOIN PARISHES P ON P.MUNICIPALITY = M.CODE
WHERE P.NAME = 'Mancelos'
ORDER BY L.SEATS DESC;
