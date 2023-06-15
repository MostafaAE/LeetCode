SELECT w1.id
FROM weather w1
WHERE temperature > (
    SELECT temperature
    FROM weather w2
    WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1
);