SELECT
    name as results
FROM
(
    SELECT
        name,
        COUNT(*) as count
    FROM
        users u
    JOIN
        movierating mr ON u.user_id = mr.user_id
    GROUP BY
        u.user_id
    ORDER BY 
        count DESC, name
    LIMIT 1
) as user
    
UNION ALL

SELECT
    title as results
FROM
(
    SELECT
        title,
        AVG(rating) as avg
    FROM
        movies m
    JOIN
        movierating mr ON m.movie_id = mr.movie_id
    WHERE
        created_at >= '2020-02-01' AND created_at <= '2020-02-29'
    GROUP BY
        m.movie_id
    ORDER BY 
        avg DESC, title
    LIMIT 1
) as movie;