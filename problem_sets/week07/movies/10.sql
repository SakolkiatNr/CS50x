-- the names of all people who have directed a movie that received a rating of at least 9.0.
    -- Your query should output a table with a single column for the name of each person.
    -- If a person directed more than one movie that received a rating of at least 9.0, they should only appear in your results once.

SELECT DISTINCT name AS Directors
FROM people
WHERE id IN (
    -- directors who direct movie(s) that have rating at least 9.0
    SELECT person_id
    FROM directors
    WHERE movie_id IN (
        -- id of movies that have rating at least 9.0
        SELECT id
        FROM movies
        WHERE id IN (
            -- rating at leat 9.0
            SELECT movie_id
            FROM ratings
            WHERE rating >= 9
        )
    )
);



