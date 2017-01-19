# Source: https://leetcode.com/problems/department-top-three-salaries/
# Author: ML3426
# Date: 2017-01-19

-- The Employee table holds all employees. Every employee has an Id, and there is also a column for the department Id.
--
-- +----+-------+--------+--------------+
-- | Id | Name  | Salary | DepartmentId |
-- +----+-------+--------+--------------+
-- | 1  | Joe   | 70000  | 1            |
-- | 2  | Henry | 80000  | 2            |
-- | 3  | Sam   | 60000  | 2            |
-- | 4  | Max   | 90000  | 1            |
-- | 5  | Janet | 69000  | 1            |
-- | 6  | Randy | 85000  | 1            |
-- +----+-------+--------+--------------+
-- The Department table holds all departments of the company.
--
-- +----+----------+
-- | Id | Name     |
-- +----+----------+
-- | 1  | IT       |
-- | 2  | Sales    |
-- +----+----------+
-- Write a SQL query to find employees who earn the top three salaries in each of the department. For the above tables, your SQL query should return the following rows.
--
-- +------------+----------+--------+
-- | Department | Employee | Salary |
-- +------------+----------+--------+
-- | IT         | Max      | 90000  |
-- | IT         | Randy    | 85000  |
-- | IT         | Joe      | 70000  |
-- | Sales      | Henry    | 80000  |
-- | Sales      | Sam      | 60000  |
-- +------------+----------+--------+

# DDL:
CREATE DATABASE IF NOT EXISTS leetcode DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

DROP TABLE IF EXISTS Employee;
DROP TABLE IF EXISTS Department;

CREATE TABLE leetcode.Employee (
  Id BIGINT PRIMARY KEY AUTO_INCREMENT,
  Name VARCHAR(15),
  Salary INT,
  DepartmentId BIGINT
);

CREATE TABLE leetcode.Department (
  Id BIGINT PRIMARY KEY AUTO_INCREMENT,
  Name VARCHAR(15)
);

TRUNCATE Employee;
INSERT INTO Employee (Name, Salary, DepartmentId) VALUES ('Joe', 70000, 1);
INSERT INTO Employee (Name, Salary, DepartmentId) VALUES ('Henry', 80000, 2);
INSERT INTO Employee (Name, Salary, DepartmentId) VALUES ('Sam', 60000, 2);
INSERT INTO Employee (Name, Salary, DepartmentId) VALUES ('Max', 90000, 1);
INSERT INTO Employee (Name, Salary, DepartmentId) VALUES ('Janet', 69000, 1);
INSERT INTO Employee (Name, Salary, DepartmentId) VALUES ('Randy', 85000, 1);

TRUNCATE Department;
INSERT INTO Department (Name) VALUES ('IT');
INSERT INTO Department (Name) VALUES ('Sales');

# Solution：
## 1521ms
SELECT B.Name Department, A.Name Employee, A.Salary FROM Employee A JOIN Department B ON A.DepartmentId = B.Id WHERE 3 > (SELECT COUNT(DISTINCT(C.Salary)) FROM Employee C WHERE C.Salary > A.Salary AND A.DepartmentId = C.DepartmentId ) ORDER BY DepartmentId, A.Salary DESC;
