WITH friendscount AS (
    SELECT
        requester_id as id,
        COUNT(*) as num
    FROM
        requestaccepted
    GROUP BY requester_id

    UNION ALL

    SELECT
        accepter_id as id,
        COUNT(*) as num
    FROM
        requestaccepted
    GROUP BY accepter_id
)

SELECT
    id,
    SUM(num) as num
FROM
    friendscount
GROUP BY
    id
ORDER BY 
    num DESC
LIMIT 
    1;