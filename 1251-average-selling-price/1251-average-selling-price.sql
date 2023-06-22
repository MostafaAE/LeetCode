SELECT product_id, ROUND(SUM(total_price)/SUM(units), 2) as average_price
FROM (
    SELECT p.product_id, p.price * us.units as total_price, us.units
    FROM prices p
    JOIN unitssold us ON p.product_id = us.product_id AND p.start_date <= us.purchase_date AND us.purchase_date <= p.end_date
) as avg
GROUP BY product_id;