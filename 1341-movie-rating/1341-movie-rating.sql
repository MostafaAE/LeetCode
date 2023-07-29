(SELECT
    name as results
FROM
    users u
JOIN
    movierating mr ON u.user_id = mr.user_id
GROUP BY
    u.user_id
ORDER BY 
    COUNT(*) DESC, name
LIMIT 1)

    
UNION ALL

(SELECT
    title as results
FROM
    movies m
JOIN
    movierating mr ON m.movie_id = mr.movie_id
WHERE
    MONTH(created_at) = '02' AND YEAR(created_at) = '2020'
GROUP BY
    m.movie_id
ORDER BY 
    AVG(rating) DESC, title
LIMIT 1);