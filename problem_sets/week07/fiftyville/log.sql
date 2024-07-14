-- Keep a log of any SQL queries you execute as you solve the mystery.

-- All you know is that the theft took place on July 28, 2023 and that it took place on Humphrey Street.

-- Find crime scence description
SELECT description
  FROM crime_scene_reports
 WHERE month = 7
   AND day = 28
   AND street = 'Humphrey Street';
-- Info:
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time
-- each of their interview transcripts mentions the bakery.

-- List of three witnesses
SELECT name, transcript
FROM interviews
WHERE year = 2023
AND month = 7
AND day = 28
AND transcript LIKE '%bakery%';
-- INFO:
-- Ruth: Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

-- license plates that exit the bakery store between 10.15 - 10.25am
SELECT *
  FROM bakery_security_logs
 WHERE day   = 28
   AND month = 7
   AND hour  = 10
   AND minute BETWEEN 15 AND 25;

-- Eugene: I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

-- List of account number that withdraw in the early morning
SELECT *
  FROM atm_transactions
 WHERE atm_location     = 'Leggett Street'
   AND transaction_type = 'withdraw';

-- Raymond: As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
-- List of phone calls
SELECT caller, receiver
FROM phone_calls
WHERE year  = 2023
  AND month = 7
  AND day   = 28
  AND duration < 60;

-- flight out of Fiftyville
SELECT flights.id
FROM flights
JOIN airports ON flights.origin_airport_id = airports.id
WHERE month = 7
  AND day   = 29
  AND year  = 2023
  AND airports.full_name = 'Fiftyville Regional Airport'
ORDER BY hour
LIMIT 1;
-- ======================================================================
-- Time to catch the thief!
SELECT name as the_theif
FROM people
WHERE phone_number IN (
  -- List of phone calls
    SELECT caller
      FROM phone_calls
     WHERE year = 2023
       AND month = 7
       AND day = 28
       AND duration < 60
)
AND license_plate IN (
    -- license plates that exit the bakery store between 10.15 - 10.25am
    SELECT license_plate
      FROM bakery_security_logs
     WHERE day = 28
       AND month = 7
       AND hour = 10
       AND minute BETWEEN 15 AND 25
       AND activity = 'exit'
)
AND passport_number IN (
    SELECT passport_number
      FROM passengers
     WHERE flight_id = (
           -- flight out of Fiftyville
           SELECT flights.id
             FROM flights
             JOIN airports ON flights.origin_airport_id = airports.id
            WHERE month = 7
              AND day   = 29
              AND year  = 2023
              AND airports.full_name = 'Fiftyville Regional Airport'
            ORDER BY hour
            LIMIT 1
     )
)
AND id IN (
    SELECT person_id
      FROM bank_accounts
     WHERE account_number IN (
           -- List of account number that withdraw in the early morning
           SELECT account_number
             FROM atm_transactions
            WHERE atm_location     = 'Leggett Street'
              AND transaction_type = 'withdraw'
    )
);
-- the thief was Bruce!

-- The ACCOMPLICE was ...Robin!
SELECT name as the_accomplice
FROM people
WHERE phone_number = (
      SELECT receiver
        FROM phone_calls
       WHERE duration < 60
         AND day = 28
         AND month = 7
         AND year = 2023
         AND caller IN (
             SELECT phone_number
               FROM people
              WHERE name = 'Bruce'
      )
);

-- The city the thief ESCAPED TO ... New York City
SELECT city
FROM airports
WHERE id = (
      SELECT destination_airport_id
        FROM flights
        JOIN airports ON flights.origin_airport_id = airports.id
       WHERE month = 7
         AND day   = 29
         AND year  = 2023
         AND airports.full_name = 'Fiftyville Regional Airport'
       ORDER BY hour
       LIMIT 1
);
