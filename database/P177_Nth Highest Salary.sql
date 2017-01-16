# Source: https://leetcode.com/problems/nth-highest-salary/
# Author: ML3426
# Date: 2017-01-16

-- Write a SQL query to get the nth highest salary from the Employee table.
--
-- +----+--------+
-- | Id | Salary |
-- +----+--------+
-- | 1  | 100    |
-- | 2  | 200    |
-- | 3  | 300    |
-- +----+--------+
-- For example, given the above Employee table, the nth highest salary where n = 2 is 200. If there is no nth highest salary, then the query should return null.

# DDL:
CREATE DATABASE IF NOT EXISTS leetcode DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

DROP TABLE IF EXISTS Employee;

CREATE TABLE leetcode.Employee (
  Id BIGINT PRIMARY KEY AUTO_INCREMENT,
  Salary INT
);

-- Test For Normal:
INSERT INTO Employee (Salary) VALUES (100);
INSERT INTO Employee (Salary) VALUES (200);
INSERT INTO Employee (Salary) VALUES (200);
INSERT INTO Employee (Salary) VALUES (300);
INSERT INTO Employee (Salary) VALUES (300);
INSERT INTO Employee (Salary) VALUES (400);

DROP FUNCTION IF EXISTS getNthHighestSalary;

# Solution：
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    # Write your MySQL query statement below.
    SELECT IF(N <= COUNT(*), MIN(Salary), NULL) FROM (SELECT Salary FROM Employee GROUP BY Salary ORDER BY Salary DESC LIMIT N) SalaryTable
  );
END;

SELECT getNthHighestSalary(5);
