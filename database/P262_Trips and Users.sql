# Source: https://leetcode.com/problems/trips-and-users/
# Author: ML3426
# Date: 2017-01-19

-- The Trips table holds all taxi trips. Each trip has a unique Id, while Client_Id and Driver_Id are both foreign keys to the Users_Id at the Users table. Status is an ENUM type of (‘completed’, ‘cancelled_by_driver’, ‘cancelled_by_client’).
--
-- +----+-----------+-----------+---------+--------------------+----------+
-- | Id | Client_Id | Driver_Id | City_Id |        Status      |Request_at|
-- +----+-----------+-----------+---------+--------------------+----------+
-- | 1  |     1     |    10     |    1    |     completed      |2013-10-01|
-- | 2  |     2     |    11     |    1    | cancelled_by_driver|2013-10-01|
-- | 3  |     3     |    12     |    6    |     completed      |2013-10-01|
-- | 4  |     4     |    13     |    6    | cancelled_by_client|2013-10-01|
-- | 5  |     1     |    10     |    1    |     completed      |2013-10-02|
-- | 6  |     2     |    11     |    6    |     completed      |2013-10-02|
-- | 7  |     3     |    12     |    6    |     completed      |2013-10-02|
-- | 8  |     2     |    12     |    12   |     completed      |2013-10-03|
-- | 9  |     3     |    10     |    12   |     completed      |2013-10-03|
-- | 10 |     4     |    13     |    12   | cancelled_by_driver|2013-10-03|
-- +----+-----------+-----------+---------+--------------------+----------+
-- The Users table holds all users. Each user has an unique Users_Id, and Role is an ENUM type of (‘client’, ‘driver’, ‘partner’).
--
-- +----------+--------+--------+
-- | Users_Id | Banned |  Role  |
-- +----------+--------+--------+
-- |    1     |   No   | client |
-- |    2     |   Yes  | client |
-- |    3     |   No   | client |
-- |    4     |   No   | client |
-- |    10    |   No   | driver |
-- |    11    |   No   | driver |
-- |    12    |   No   | driver |
-- |    13    |   No   | driver |
-- +----------+--------+--------+
-- Write a SQL query to find the cancellation rate of requests made by unbanned clients between Oct 1, 2013 and Oct 3, 2013. For the above tables, your SQL query should return the following rows with the cancellation rate being rounded to two decimal places.
--
-- +------------+-------------------+
-- |     Day    | Cancellation Rate |
-- +------------+-------------------+
-- | 2013-10-01 |       0.33        |
-- | 2013-10-02 |       0.00        |
-- | 2013-10-03 |       0.50        |
-- +------------+-------------------+

# DDL:
CREATE DATABASE IF NOT EXISTS leetcode DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

DROP TABLE IF EXISTS Trips;
DROP TABLE IF EXISTS Users;

CREATE TABLE leetcode.Trips (
  Id BIGINT PRIMARY KEY AUTO_INCREMENT,
  Client_Id BIGINT,
  Driver_Id BIGINT,
  City_Id BIGINT,
  Status VARCHAR(50),
  Request_at DATE
);

CREATE TABLE leetcode.Users (
  Users_Id BIGINT PRIMARY KEY,
  Banned VARCHAR(3),
  Role VARCHAR(15)
);

TRUNCATE Trips;
INSERT INTO Trips (Client_Id, Driver_Id, City_Id, Status, Request_at) VALUES (1, 10, 1, 'completed', '2013-10-01');
INSERT INTO Trips (Client_Id, Driver_Id, City_Id, Status, Request_at) VALUES (2, 11, 1, 'cancelled_by_driver', '2013-10-01');
INSERT INTO Trips (Client_Id, Driver_Id, City_Id, Status, Request_at) VALUES (3, 12, 6, 'completed', '2013-10-01');
INSERT INTO Trips (Client_Id, Driver_Id, City_Id, Status, Request_at) VALUES (4, 13, 6, 'cancelled_by_client', '2013-10-01');
INSERT INTO Trips (Client_Id, Driver_Id, City_Id, Status, Request_at) VALUES (1, 10, 1, 'completed', '2013-10-02');
INSERT INTO Trips (Client_Id, Driver_Id, City_Id, Status, Request_at) VALUES (2, 11, 6, 'completed', '2013-10-02');
INSERT INTO Trips (Client_Id, Driver_Id, City_Id, Status, Request_at) VALUES (3, 12, 6, 'completed', '2013-10-02');
INSERT INTO Trips (Client_Id, Driver_Id, City_Id, Status, Request_at) VALUES (2, 12, 12, 'completed', '2013-10-03');
INSERT INTO Trips (Client_Id, Driver_Id, City_Id, Status, Request_at) VALUES (3, 10, 12, 'completed', '2013-10-03');
INSERT INTO Trips (Client_Id, Driver_Id, City_Id, Status, Request_at) VALUES (4, 13, 12, 'cancelled_by_driver', '2013-10-03');

TRUNCATE Users;
INSERT INTO Users (Users_Id, Banned, Role) VALUES (1, 'NO', 'client');
INSERT INTO Users (Users_Id, Banned, Role) VALUES (2, 'Yes', 'client');
INSERT INTO Users (Users_Id, Banned, Role) VALUES (3, 'NO', 'client');
INSERT INTO Users (Users_Id, Banned, Role) VALUES (4, 'NO', 'client');
INSERT INTO Users (Users_Id, Banned, Role) VALUES (10, 'NO', 'client');
INSERT INTO Users (Users_Id, Banned, Role) VALUES (11, 'NO', 'client');
INSERT INTO Users (Users_Id, Banned, Role) VALUES (12, 'NO', 'client');
INSERT INTO Users (Users_Id, Banned, Role) VALUES (13, 'NO', 'client');

# Solution：
## 694ms
SELECT Request_at Day, ROUND(COUNT(IF(Status != 'completed', TRUE, NULL)) / COUNT(*), 2) 'Cancellation Rate' FROM Trips WHERE Request_at BETWEEN '2013-10-01' AND '2013-10-03' AND Client_id NOT IN (SELECT Users_Id FROM Users WHERE Banned = 'Yes') GROUP BY Request_at;
