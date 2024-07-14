-- Four types of commands: CRUD
CREATE
READ
UPDATE
DELETE

-- commands to access data
AVG
COUNT
DISTINCT
LOWER
MAX
MIN
UPPER

-- additional commands
WHERE       -- adding a Boolean expression to filter our data
LIKE        -- filtering responses more loosely
ORDER BY    -- ordering responses
LIMIT       -- limiting the number of responses
GROUP BY    -- grouping responses together


-- SELECT COUNT(language) FROM favorites;
-- SELECT COUNT(DISTINCT(language)) FROM favorites;
-- SELECT COUNT(*) FROM favorites WHERE language = 'C' AND problem = 'Hello, World';
-- SELECT language, COUNT(*) FROM favorites GROUP BY language;
-- SELECT language, COUNT(*) FROM favorites GROUP BY language ORDER BY COUNT(*);

-- INSERT INTO table (col...) VALUE(value,...);

-- DELETE FROM favorites WHERE Timestamp IS NULL;
