# Source: https://leetcode.com/problems/employees-earning-more-than-their-managers/
# Author: ML3426
# Date: 2017-01-19

-- The Employee table holds all employees including their managers. Every employee has an Id, and there is also a column for the manager Id.
--
-- +----+-------+--------+-----------+
-- | Id | Name  | Salary | ManagerId |
-- +----+-------+--------+-----------+
-- | 1  | Joe   | 70000  | 3         |
-- | 2  | Henry | 80000  | 4         |
-- | 3  | Sam   | 60000  | NULL      |
-- | 4  | Max   | 90000  | NULL      |
-- +----+-------+--------+-----------+
-- Given the Employee table, write a SQL query that finds out employees who earn more than their managers. For the above table, Joe is the only employee who earns more than his manager.
--
-- +----------+
-- | Employee |
-- +----------+
-- | Joe      |
-- +----------+

# DDL:
CREATE DATABASE IF NOT EXISTS leetcode DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

DROP TABLE IF EXISTS Employee;

CREATE TABLE leetcode.Employee (
  Id BIGINT PRIMARY KEY AUTO_INCREMENT,
  Name VARCHAR(15),
  Salary INT,
  ManagerId BIGINT
);

TRUNCATE Employee;
INSERT INTO Employee (Name, Salary, ManagerId) VALUES ('Joe', 70000, 3);
INSERT INTO Employee (Name, Salary, ManagerId) VALUES ('Henry', 80000, 4);
INSERT INTO Employee (Name, Salary, ManagerId) VALUES ('Sam', 60000, NULL);
INSERT INTO Employee (Name, Salary, ManagerId) VALUES ('Max', 90000, NULL);

# Solution：
## JOIN-ON方法(1884ms)
SELECT A.Name Employee FROM Employee A JOIN Employee B ON A.ManagerId = B.Id WHERE A.Salary > B.Salary;

## Where方法(1261ms)
SELECT A.Name Employee FROM Employee A JOIN Employee B WHERE A.ManagerId = B.Id AND A.Salary > B.Salary;
