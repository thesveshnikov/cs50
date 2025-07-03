SELECT title FROM shows 
WHERE id IN (
    SELECT show_id FROM genres 
    WHERE genre = "Comedy"
) AND year = 2019;
