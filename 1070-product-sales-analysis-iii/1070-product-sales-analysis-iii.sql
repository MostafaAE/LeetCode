SELECT s1.product_id, s1.year as first_year, s1.quantity, s1.price
FROM sales s1
WHERE (s1.product_id, s1.year) IN (
    SELECT s2.product_id, MIN(s2.year)
    FROM sales s2
    GROUP BY s2.product_id
);