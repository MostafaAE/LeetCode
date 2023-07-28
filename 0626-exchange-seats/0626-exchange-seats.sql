SELECT
    s1.id,
    CASE
        WHEN s1.id % 2 = 1 THEN COALESCE((SELECT student FROM seat s2 WHERE s2.id = s1.id + 1), s1.student)
        ELSE (SELECT student FROM seat s2 WHERE s2.id = s1.id - 1)
    END as student
FROM
    seat s1;