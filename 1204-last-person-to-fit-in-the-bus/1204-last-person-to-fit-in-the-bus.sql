# Write your MySQL query statement below

SELECT 
    person_name
FROM (
    SELECT 
        person_name,
        (
            SELECT SUM(weight) FROM queue q2 WHERE q2.turn <= q1.turn
        ) as total_weight
    FROM 
        queue q1
    ORDER BY 
        total_weight desc
) as q
WHERE 
    q.total_weight <= 1000
LIMIT 
    1;