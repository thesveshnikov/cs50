SELECT language, COUNT(*) AS count FROM favorites
GROUP BY language
ORDER BY count DESC;
