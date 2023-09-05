# Write your MySQL query statement below
SELECT 
    visited_on, 
    (
        SELECT SUM(amount)
        FROM customer c2 
        WHERE DATEDIFF(c1.visited_on, c2.visited_on) <= 6 AND DATEDIFF(c1.visited_on, c2.visited_on) >=0
    ) as amount,
    
    ROUND
    (
        (
        SELECT SUM(amount) / 7
        FROM customer c2 
        WHERE DATEDIFF(c1.visited_on, c2.visited_on) <= 6 AND DATEDIFF(c1.visited_on, c2.visited_on) >=0
        )
    , 2
    ) as average_amount
    
FROM 
    customer c1
GROUP BY 
    visited_on
HAVING 
    DATEDIFF(c1.visited_on, (SELECT c3.visited_on FROM customer c3 LIMIT 1)) >= 6;