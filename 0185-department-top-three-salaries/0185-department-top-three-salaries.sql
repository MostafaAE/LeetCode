# Write your MySQL query statement below

SELECT 
    d.name as Department,
    e1.name as Employee,
    e1.salary as Salary
FROM
    employee e1 JOIN department d ON e1.departmentId = d.id
WHERE
    3 > (
        SELECT
            COUNT(DISTINCT e2.Salary)
        FROM 
            employee e2
        WHERE
            e2.Salary > e1.Salary AND e2.departmentId = e1.departmentId
    );