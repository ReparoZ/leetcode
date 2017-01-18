# Source: https://leetcode.com/problems/consecutive-numbers/
# Author: ML3426
# Date: 2017-01-18

-- Write a SQL query to find all numbers that appear at least three times consecutively.
--
-- +----+-----+
-- | Id | Num |
-- +----+-----+
-- | 1  |  1  |
-- | 2  |  1  |
-- | 3  |  1  |
-- | 4  |  2  |
-- | 5  |  1  |
-- | 6  |  2  |
-- | 7  |  2  |
-- +----+-----+
-- For example, given the above Logs table, 1 is the only number that appears consecutively for at least three times.

# DDL:
CREATE DATABASE IF NOT EXISTS leetcode DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

DROP TABLE IF EXISTS Logs;

CREATE TABLE leetcode.Logs (
  Id BIGINT PRIMARY KEY AUTO_INCREMENT,
  Num INT
);

-- Test Case #1:
TRUNCATE Logs;
INSERT INTO Logs (Num) VALUES (1);
INSERT INTO Logs (Num) VALUES (1);
INSERT INTO Logs (Num) VALUES (1);
INSERT INTO Logs (Num) VALUES (2);
INSERT INTO Logs (Num) VALUES (1);
INSERT INTO Logs (Num) VALUES (2);
INSERT INTO Logs (Num) VALUES (2);

-- Test Case #2:
TRUNCATE Logs;
INSERT INTO Logs (Num) VALUES (-1);
INSERT INTO Logs (Num) VALUES (-1);
INSERT INTO Logs (Num) VALUES (-1);

# Solution：
## 对Logs表自连接三次查询
## Time: Time Limit Exceeded
EXPLAIN SELECT DISTINCT(A.Num) ConsecutiveNums FROM Logs A, Logs B, Logs C WHERE A.Id + 1 = B.Id AND A.Id + 2 = C.Id AND A.Num = B.Num AND B.Num = C.Num;
