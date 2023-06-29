SELECT 
    DISTINCT n1 as ConsecutiveNums
FROM (
    SELECT 
        l1.num n1, l2.num n2, l3.num n3
    FROM 
        logs l1
    JOIN 
        logs l2 ON l1.id = l2.id-1
    JOIN 
        logs l3 ON l2.id = l3.id-1
) as consecutive3
WHERE 
    n1 = n2 AND n1 = n3