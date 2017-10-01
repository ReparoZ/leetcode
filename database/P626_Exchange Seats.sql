# Source: https://leetcode.com/problems/exchange-seats/
# Author: ML3426
# Date: 2017-10-01

-- Mary is a teacher in a middle school and she has a table seat storing students' names and their corresponding seat ids.
--
-- The column id is continuous increment.
-- Mary wants to change seats for the adjacent students.
-- Can you write a SQL query to output the result for Mary?
-- +---------+---------+
-- |    id   | student |
-- +---------+---------+
-- |    1    | Abbot   |
-- |    2    | Doris   |
-- |    3    | Emerson |
-- |    4    | Green   |
-- |    5    | Jeames  |
-- +---------+---------+
-- For the sample input, the output is:
-- +---------+---------+
-- |    id   | student |
-- +---------+---------+
-- |    1    | Doris   |
-- |    2    | Abbot   |
-- |    3    | Green   |
-- |    4    | Emerson |
-- |    5    | Jeames  |
-- +---------+---------+
-- Note:
-- If the number of students is odd, there is no need to change the last one's seat.

# DDL:
CREATE DATABASE IF NOT EXISTS leetcode DEFAULT CHARSET utf8 COLLATE utf8_general_ci;
USE leetcode;

DROP TABLE IF EXISTS seat;

CREATE TABLE seat (
  id BIGINT PRIMARY KEY AUTO_INCREMENT,
  student VARCHAR(255)
);

TRUNCATE seat;
INSERT INTO seat (student) VALUES ('Abbot');
INSERT INTO seat (student) VALUES ('Doris');
INSERT INTO seat (student) VALUES ('Emerson');
INSERT INTO seat (student) VALUES ('Green');
INSERT INTO seat (student) VALUES ('Jeames');

# Solution：
## 451ms
## 简单查询法
SELECT
  a.id      id,
  b.student student
FROM seat a
  JOIN seat b ON
                (a.id & 1 = 1 AND a.id = b.id - 1) OR -- 单数匹配下一行
                (a.id & 1 = 0 AND a.id = b.id + 1) OR -- 双数匹配上一行
                (a.id = (SELECT MAX(id) FROM seat) AND a.id & 1 AND a.id = b.id) -- 最后一行单数匹配当前行
ORDER BY a.id;

## 451ms
## 简单查询法（优化，使用位运算和COALESCE）
SELECT a.id id, COALESCE(b.student, a.student) student FROM seat a LEFT JOIN seat b ON b.id = (a.id + 1) ^ 1 - 1 ORDER BY a.id;

## 420ms
## CASE流程控制法
SELECT
    (CASE
        WHEN MOD(id, 2) != 0 AND counts != id THEN id + 1
        WHEN MOD(id, 2) != 0 AND counts = id THEN id
        ELSE id - 1
    END) AS id,
    student
FROM
    seat,
    (SELECT
        COUNT(*) AS counts
    FROM
        seat) AS seat_counts
ORDER BY id ASC;
