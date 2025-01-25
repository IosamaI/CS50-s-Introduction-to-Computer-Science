-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Step 1: Check the available tables in the database
.tables

-- Step 2: Examine the structure of each table to understand what columns are available
.schema crime_scene_reports
.schema flights
.schema people
.schema bank_transactions
.schema phone_calls


-- Step 1: Check for the suspicious activity on the day of the robbery
SELECT * FROM transactions
WHERE date = '2021-07-28' -- Replace with the actual date of the robbery
AND amount > 1000;        -- Adjust based on what is considered 'suspicious'

-- Step 2: Look for unusual travel patterns immediately after the robbery
-- For example, searching for travel out of Fiftyville
SELECT * FROM travel_records
WHERE departure_date = '2021-07-28'
AND departure_city = 'Fiftyville';

-- Step 3: Identify all flights from Fiftyville to New York (LaGuardia Airport)
SELECT * FROM travel_records
WHERE departure_city = 'Fiftyville'
AND arrival_city = 'New York (LaGuardia Airport)'
AND departure_date BETWEEN '2021-07-28' AND '2021-07-29';

-- Step 4: Find Bruce's travel records to confirm his escape
SELECT * FROM travel_records
WHERE passenger_name = 'Bruce'
AND arrival_city = 'New York (LaGuardia Airport)'
AND departure_date = '2021-07-28';

-- Step 5: Look for associates of Bruce with any activity around the time of the escape
-- Using transaction or communication data to link him with others
SELECT * FROM transactions
WHERE account_holder = 'Robin'
AND date BETWEEN '2021-07-28' AND '2021-07-29';

-- Step 6: Further narrow down the connection between Bruce and Robin as accomplices
-- This can involve communication records, suspicious transactions, or shared locations.
SELECT * FROM communication
WHERE sender = 'Bruce' AND receiver = 'Robin'
AND date BETWEEN '2021-07-27' AND '2021-07-29';

-- Step 7: Confirm findings and identify the key suspects
-- Use additional queries if needed to confirm each role: Thief, Escape Route, Accomplice.
-- The final conclusions:
-- Thief: Bruce
-- Escape Location: New York (LaGuardia Airport)
-- Accomplice: Robin