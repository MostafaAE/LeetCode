SELECT project_id, ROUND(AVG(experience_years), 2) as average_years
FROM project p
JOIN employee e ON p.employee_id = e.employee_id
GROUP BY project_id;