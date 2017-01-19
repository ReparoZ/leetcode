# Source: https://leetcode.com/problems/rising-temperature/
# Author: ML3426
# Date: 2017-01-19

-- Given a Weather table, write a SQL query to find all dates' Ids with higher temperature compared to its previous (yesterday's) dates.
--
-- +---------+------------+------------------+
-- | Id(INT) | Date(DATE) | Temperature(INT) |
-- +---------+------------+------------------+
-- |       1 | 2015-01-01 |               10 |
-- |       2 | 2015-01-02 |               25 |
-- |       3 | 2015-01-03 |               20 |
-- |       4 | 2015-01-04 |               30 |
-- +---------+------------+------------------+
-- For example, return the following Ids for the above Weather table:
-- +----+
-- | Id |
-- +----+
-- |  2 |
-- |  4 |
-- +----+

# DDL:
CREATE DATABASE IF NOT EXISTS leetcode DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

DROP TABLE IF EXISTS Weather;

CREATE TABLE leetcode.Weather (
  Id BIGINT PRIMARY KEY AUTO_INCREMENT,
  Date DATE,
  Temperature INT
);

TRUNCATE Weather;
INSERT INTO Weather (Date, Temperature) VALUES ('2015-01-01', 10);
INSERT INTO Weather (Date, Temperature) VALUES ('2015-01-02', 25);
INSERT INTO Weather (Date, Temperature) VALUES ('2015-01-03', 20);
INSERT INTO Weather (Date, Temperature) VALUES ('2015-01-04', 30);

# Solution：
## 988ms
SELECT A.Id FROM Weather A, Weather B WHERE TO_DAYS(A.Date) - TO_DAYS(B.DATE) = 1 AND A.Temperature > B.Temperature;
