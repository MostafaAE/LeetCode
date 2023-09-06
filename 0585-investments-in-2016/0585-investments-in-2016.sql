# Write your MySQL query statement below
SELECT ROUND(
    SUM(
        CASE 
        WHEN (SELECT COUNT(*) FROM insurance i3 WHERE i3.tiv_2015 = i1.tiv_2015 ) >= 2 THEN i1.tiv_2016 ELSE 0
        END
    )
    , 2) as tiv_2016
FROM insurance i1
LEFT JOIN insurance i2 ON i1.pid != i2.pid AND i1.lat = i2.lat AND i1.lon = i2.lon
WHERE i2.pid IS null;