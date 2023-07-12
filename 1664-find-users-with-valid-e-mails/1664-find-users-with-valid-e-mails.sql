SELECT
    *
FROM
    users
WHERE 
    REGEXP_LIKE(LOWER(mail), '^[a-z]+[a-z0-9._-]*@leetcode[.]com$');