SELECT stu.student_id, stu.student_name, sub.subject_name, COUNT(ex.student_id) as attended_exams
FROM students stu
JOIN subjects sub
LEFT JOIN examinations ex ON stu.student_id = ex.student_id AND sub.subject_name = ex.subject_name
GROUP BY stu.student_id, sub.subject_name
ORDER BY stu.student_id, sub.subject_name;