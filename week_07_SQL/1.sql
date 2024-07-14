SELECT title
FROM shows
WHERE id IN (
    SELECT show_id
    FROM ratings
    WHERE rating >= 6.0
    LIMIT 10
);

-- JOIN
SELECT * FROM shows
  JOIN ratings
  ON shows.id = ratings.show_id
  WHERE rating >= 6.0
  LIMIT 10;

--
SELECT title FROM shows
WHERE id IN (
  SELECT show_id FROM genres
  WHERE genre = 'Comedy'
  LIMIT 10
);


