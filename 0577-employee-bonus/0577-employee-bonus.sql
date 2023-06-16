SELECT name, bonus
FROM employee e
LEFT JOIN bonus b ON e.empId = b.empId
WHERE bonus IS NULL OR bonus < 1000;