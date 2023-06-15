SELECT product_name, year, price
FROM Product as p
JOIN Sales as s ON p.product_id = s.product_id;