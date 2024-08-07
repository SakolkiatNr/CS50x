-- the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
    -- Your query should output a table with a single column for the title of each movie.
    -- You may assume that there is only one person in the database with the name Chadwick Boseman.
SELECT title
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE movies.id IN (
    SELECT movie_id
    FROM stars
    WHERE person_id = (
        -- id of Chadwick Boseman
        SELECT id
        FROM people
        WHERE name = 'Chadwick Boseman'
    )
)
ORDER BY ratings.rating DESC
LIMIT 5;
