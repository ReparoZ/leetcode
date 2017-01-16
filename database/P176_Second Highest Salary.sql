# Source: https://leetcode.com/problems/second-highest-salary/
# Author: ML3426
# Date: 2017-01-15

-- Write a SQL query to get the second highest salary from the Employee table.
--
-- +----+--------+
-- | Id | Salary |
-- +----+--------+
-- | 1  | 100    |
-- | 2  | 200    |
-- | 3  | 300    |
-- +----+--------+
-- For example, given the above Employee table, the second highest salary is 200. If there is no second highest salary, then the query should return null.

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
INSERT INTO Employee (Salary) VALUES (300);
INSERT INTO Employee (Salary) VALUES (400);

-- Test For Null:
TRUNCATE Employee;
INSERT INTO Employee (Salary) VALUES (100);
INSERT INTO Employee (Salary) VALUES (100);
INSERT INTO Employee (Salary) VALUES (100);

# Solution：
## 此解法利用了SELECT在SELECT一个空行时会返回NULL的特性
SELECT (SELECT Salary FROM Employee GROUP BY Employee.Salary ORDER BY Salary DESC LIMIT 1, 1) SecondHighestSalary;
## MAX函数遇到空值会返回NULL
SELECT MAX(Salary) SecondHighestSalary FROM Employee WHERE Salary < (SELECT MAX(Salary) FROM Employee);
