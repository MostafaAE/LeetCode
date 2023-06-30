SELECT
    product_id,
    new_price AS price
FROM 
    products
WHERE
    (product_id, change_date) IN (
        SELECT 
            product_id, 
            MAX(change_date)
        FROM 
            products
        WHERE
            change_date <= '2019-08-16'
        GROUP BY
            product_id
    )

UNION ALL

SELECT 
    product_id,
    10 AS price
FROM
    products    
GROUP BY 
    product_id
HAVING
    MIN(change_date) > '2019-08-16';