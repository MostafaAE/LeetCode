# Write your MySQL query statement below
SELECT ROUND(
    SUM(tiv_2016), 2
) as tiv_2016
FROM insurance i1
WHERE
    i1.tiv_2015 IN (
        SELECT 
            tiv_2015
        FROM
            insurance
        GROUP BY 
            tiv_2015
        HAVING COUNT(*) > 1
        
    )
AND
    CONCAT(lat, lon) IN (
        SELECT
            CONCAT(lat, lon)
        FROM 
            insurance
        GROUP BY 
            lat, lon
        HAVING COUNT(*) = 1
    )
;