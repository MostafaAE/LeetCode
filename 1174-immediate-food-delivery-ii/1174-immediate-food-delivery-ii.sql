SELECT ROUND(SUM(d1.order_date = d1.customer_pref_delivery_date) / COUNT(*) * 100, 2) AS immediate_percentage
FROM delivery d1
WHERE d1.order_date = (
    SELECT d2.order_date
    FROM delivery d2
    WHERE d1.customer_id = d2.customer_id
    ORDER BY d2.order_date
    LIMIT 1
);