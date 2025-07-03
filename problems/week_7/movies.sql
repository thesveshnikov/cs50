-- 1.sql
SELECT title FROM movies WHERE year = 2008;

-- 2.sql
SELECT birth FROM people WHERE name = "Emma Stone";

-- 3.sql
SELECT title FROM movies WHERE year >= 2018 ORDER BY title;

-- 4.sql
SELECT COUNT(*) FROM ratings WHERE rating = 10.0;

-- 5.sql
SELECT title, year FROM movies WHERE title LIKE "Harry Potter%" ORDER BY year;

-- 6.sql
SELECT AVG(rating) FROM ratings JOIN movies ON ratings.movie_id = movies.id WHERE year = 2012;

-- 7.sql
SELECT title, rating FROM movies 
JOIN ratings ON movies.id = ratings.movie_id 
WHERE year = 2010 
ORDER BY rating DESC, title;

-- 8.sql
SELECT name FROM people 
JOIN stars ON people.id = stars.person_id 
JOIN movies ON stars.movie_id = movies.id 
WHERE title = "Toy Story";

-- 9.sql
SELECT name FROM people 
JOIN stars ON people.id = stars.person_id 
JOIN movies ON stars.movie_id = movies.id 
WHERE year = 2004 
ORDER BY birth;

-- 10.sql
SELECT name FROM people 
JOIN directors ON people.id = directors.person_id 
JOIN movies ON directors.movie_id = movies.id 
JOIN ratings ON movies.id = ratings.movie_id 
WHERE rating >= 9.0;

-- 11.sql
SELECT title FROM movies 
JOIN stars ON movies.id = stars.movie_id 
JOIN people ON stars.person_id = people.id 
JOIN ratings ON movies.id = ratings.movie_id 
WHERE name = "Chadwick Boseman" 
ORDER BY rating DESC 
LIMIT 5;

-- 12.sql
SELECT title FROM movies 
JOIN stars ON movies.id = stars.movie_id 
JOIN people ON stars.person_id = people.id 
WHERE name = "Johnny Depp" 
INTERSECT 
SELECT title FROM movies 
JOIN stars ON movies.id = stars.movie_id 
JOIN people ON stars.person_id = people.id 
WHERE name = "Helena Bonham Carter";

-- 13.sql
SELECT name FROM people 
WHERE id IN (
    SELECT person_id FROM stars 
    WHERE movie_id IN (
        SELECT movie_id FROM stars 
        WHERE person_id = (
            SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958
        )
    )
) 
AND name != "Kevin Bacon";
