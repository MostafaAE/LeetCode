SELECT query_name,
       ROUND(AVG(rating/position), 2) as quality,
       ROUND(COUNT(CASE WHEN rating < 3 THEN 1 ELSE NULL END)/COUNT(*) * 100, 2) as poor_query_percentage
FROM queries
GROUP BY query_name;