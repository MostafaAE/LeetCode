SELECT 
    employee_id,
    ABS(MAX(CASE WHEN primary_flag = 'Y' THEN department_id ELSE -department_id END)) AS department_id
FROM
    employee
GROUP BY 
    employee_id;