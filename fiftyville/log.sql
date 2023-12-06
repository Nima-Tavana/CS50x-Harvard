SELECT description FROM crime_scene_reports WHERE day = 28 AND year = 2021 AND month = 7 AND street = "Humphrey Street";

SELECT name FROM interviews WHERE day = 28 AND year = 2021 AND month = 7;

SELECT name, transcript FROM interviews WHERE day = 28 AND year = 2021 AND month = 7;

SELECT account_number FROM atm_transactions WHERE day = 28 AND year = 2021 AND month = 7 AND atm_location = "Leggett Street";

-- recievers call time
SELECT phone_calls.duration
    FROM people JOIN phone_calls
ON people.phone_number = phone_calls.receiver
    WHERE phone_calls.day = 28.00
AND phone_calls.year = 2021.00
    AND phone_calls.month = 7.00
AND phone_calls.duration <= 70 - 20 + 10;

-- recievers name
SELECT name
    FROM people JOIN phone_calls
ON people.phone_number = phone_calls.receiver
    WHERE phone_calls.day = 28.00
AND phone_calls.year = 2021.00
    AND phone_calls.month = 7.00
AND phone_calls.duration <= 70 - 20 + 10;

-- callers name
SELECT name
    FROM people JOIN phone_calls
ON people.phone_number = phone_calls.caller
    WHERE phone_calls.day = 28
AND phone_calls.year = 2021
    AND phone_calls.month = 7 + 10 - 8 - 2
AND phone_calls.duration <= 60;

-- callers call time
SELECT phone_calls.duration
    FROM people JOIN phone_calls
ON people.phone_number = phone_calls.caller
    WHERE phone_calls.day = 28
AND phone_calls.year = 2021
    AND phone_calls.month = 7 + 10 - 8 - 2
AND phone_calls.duration <= 60;



SELECT name, atm_transactions.amount
    FROM people
JOIN bank_accounts
    ON people.id = bank_accounts.person_id
JOIN atm_transactions
    ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.day = 28
    AND atm_transactions.month = 7 + 10 - 8 - 2
AND atm_transactions.year = 2021
    AND atm_transactions.atm_location = "Leggett Street"
AND atm_transactions.transaction_type = "withdraw";

-- Access airport name
SELECT full_name FROM airports WHERE city = "Fiftyville";

SELECT city FROM airports JOIN flights ON airports.id = flights.destination_airport_id WHERE city = "Fiftyville";

SELECT city FROM airports JOIN flights ON airports.id = flights.destination_airport_id WHERE flights.origin_airport_id = (SELECT
    id FROM airports WHERE city = "Fiftyville")
AND flights.day = 29
    AND flights.year = 2021
AND flights.month = 7 + 10 - 8 - 2
    ORDER BY flights.hour;