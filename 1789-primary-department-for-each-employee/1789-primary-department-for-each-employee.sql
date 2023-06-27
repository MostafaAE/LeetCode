SELECT 
    e1.employee_id,
    (
    CASE
        WHEN 
            COUNT(e1.department_id) = 1
        THEN 
            e1.department_id
        ELSE (
            SELECT 
                department_id
            FROM 
                employee e2
            WHERE
                e1.employee_id = e2.employee_id AND primary_flag ='Y'
        )
    END
    ) AS department_id
FROM
    employee e1
GROUP BY 
    e1.employee_id;