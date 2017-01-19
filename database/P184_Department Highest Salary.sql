# Source: https://leetcode.com/problems/department-highest-salary/
# Author: ML3426
# Date: 2017-01-19

-- The Employee table holds all employees. Every employee has an Id, a salary, and there is also a column for the department Id.
--
-- +----+-------+--------+--------------+
-- | Id | Name  | Salary | DepartmentId |
-- +----+-------+--------+--------------+
-- | 1  | Joe   | 70000  | 1            |
-- | 2  | Henry | 80000  | 2            |
-- | 3  | Sam   | 60000  | 2            |
-- | 4  | Max   | 90000  | 1            |
-- +----+-------+--------+--------------+
-- The Department table holds all departments of the company.
--
-- +----+----------+
-- | Id | Name     |
-- +----+----------+
-- | 1  | IT       |
-- | 2  | Sales    |
-- +----+----------+
-- Write a SQL query to find employees who have the highest salary in each of the departments. For the above tables, Max has the highest salary in the IT department and Henry has the highest salary in the Sales department.
--
-- +------------+----------+--------+
-- | Department | Employee | Salary |
-- +------------+----------+--------+
-- | IT         | Max      | 90000  |
-- | Sales      | Henry    | 80000  |
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

TRUNCATE Department;
INSERT INTO Department (Name) VALUES ('IT');
INSERT INTO Department (Name) VALUES ('Sales');

# Solution：
## 1446ms
SELECT B.Name Department, A.Name Employee, A.Salary Salary FROM Employee A JOIN Department B JOIN (SELECT DepartmentId, MAX(Salary) Salary FROM Employee GROUP BY DepartmentId) C WHERE A.DepartmentId = B.Id AND A.Salary = C.Salary AND A.DepartmentId = C.DepartmentId ORDER BY A.DepartmentId;
