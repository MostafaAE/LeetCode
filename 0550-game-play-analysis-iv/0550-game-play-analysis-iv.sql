SELECT 
    ROUND(
        COUNT(a1.player_id) 
        / (SELECT COUNT(DISTINCT a3.player_id) FROM activity a3), 2) as fraction
FROM 
    activity a1
WHERE 
    (a1.player_id, DATE_SUB(a1.event_date, INTERVAL 1 DAY)) IN (
    SELECT 
        a2.player_id, MIN(a2.event_date) 
    FROM 
        activity a2 
    GROUP BY 
        a2.player_id
);