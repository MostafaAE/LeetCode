SELECT p.product_id, ROUND(SUM(p.price * us.units)/SUM(units), 2) as average_price
FROM prices p
JOIN unitssold us ON p.product_id = us.product_id
WHERE p.start_date <= us.purchase_date AND us.purchase_date <= p.end_date
GROUP BY product_id;