SELECT
    product_name,
    SUM(unit) as unit
FROM
    products p
JOIN
    orders o ON p.product_id = o.product_id
WHERE 
    EXTRACT(YEAR_MONTH FROM order_date) = 202002
GROUP BY
    o.product_id
HAVING 
    unit >= 100;