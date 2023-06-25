SELECT user_id, COUNT(*) as followers_count
FROM followers
GROUP BY user_id
ORDER BY user_id;