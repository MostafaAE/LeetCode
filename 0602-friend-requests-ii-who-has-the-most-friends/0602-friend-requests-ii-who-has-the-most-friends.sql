WITH friendscount AS (
    SELECT
        requester_id as id
    FROM
        requestaccepted

    UNION ALL

    SELECT
        accepter_id as id
    FROM
        requestaccepted
)

SELECT
    id,
    COUNT(*) as num
FROM
    friendscount
GROUP BY
    id
ORDER BY 
    num DESC
LIMIT 
    1;