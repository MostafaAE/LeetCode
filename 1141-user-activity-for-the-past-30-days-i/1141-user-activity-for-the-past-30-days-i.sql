SELECT activity_date AS day, COUNT(DISTINCT user_id) as active_users
FROM activity
GROUP BY day
HAVING DATEDIFF('2019-07-27', day) < 30 AND DATEDIFF('2019-07-27', day) >= 0;