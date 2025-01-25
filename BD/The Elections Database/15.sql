-- What are the acronyms of the parties that presented a list but obtained zero seats on all the districts that have an "o" or an "O" in its name? Order ascendantly by acronym.

WITH DISTRICTS_WITH_O AS (
    SELECT CODE
    FROM DISTRICTS
    WHERE NAME LIKE '%O%' OR NAME LIKE '%o%'
)

SELECT L.PARTY
FROM LISTS L
JOIN DISTRICTS D ON D.CODE = L.DISTRICT
WHERE L.SEATS = 0 AND D.CODE IN DISTRICTS_WITH_O
GROUP BY L.PARTY
HAVING COUNT(*) = (SELECT COUNT(*) FROM DISTRICTS_WITH_O);
