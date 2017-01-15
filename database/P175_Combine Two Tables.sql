# Source: https://leetcode.com/problems/combine-two-tables/
# Author: ML3426
# Date: 2017-01-15

-- Table: Person
--
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | PersonId    | int     |
-- | FirstName   | varchar |
-- | LastName    | varchar |
-- +-------------+---------+
-- PersonId is the primary key column for this table.
-- Table: Address
--
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | AddressId   | int     |
-- | PersonId    | int     |
-- | City        | varchar |
-- | State       | varchar |
-- +-------------+---------+
-- AddressId is the primary key column for this table.
--
-- Write a SQL query for a report that provides the following information for each person in the Person table, regardless if there is an address for each of those people:
--
-- FirstName, LastName, City, State

# DDL:
CREATE DATABASE IF NOT EXISTS leetcode DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

DROP TABLE IF EXISTS Person;
DROP TABLE IF EXISTS Address;

CREATE TABLE leetcode.Person (
  PersonId INT PRIMARY KEY AUTO_INCREMENT,
  FirstName VARCHAR(50),
  LastName VARCHAR(50)
);

CREATE TABLE leetcode.Address (
  AddressId INT PRIMARY KEY AUTO_INCREMENT,
  PersonId INT,
  City VARCHAR(50),
  State VARCHAR(50)
);

INSERT INTO Person (FirstName, LastName) VALUES ('Milagros', 'Sanford');
INSERT INTO Person (FirstName, LastName) VALUES ('Selma', 'Dotson');
INSERT INTO Person (FirstName, LastName) VALUES ('Doug', 'Mccall');
INSERT INTO Person (FirstName, LastName) VALUES ('Tommie', 'Gilmore');
INSERT INTO Person (FirstName, LastName) VALUES ('Joann', 'Mccarty');
INSERT INTO Person (FirstName, LastName) VALUES ('Ed', 'Dillard');
INSERT INTO Person (FirstName, LastName) VALUES ('Morton', 'Franco');
INSERT INTO Person (FirstName, LastName) VALUES ('Edwin', 'Wall');
INSERT INTO Person (FirstName, LastName) VALUES ('Claudette', 'Cook');
INSERT INTO Person (FirstName, LastName) VALUES ('Nita', 'Morgan');

INSERT INTO Address (PersonId, City, State) VALUES (1, 'Massillon', 'OH');
INSERT INTO Address (PersonId, City, State) VALUES (2, 'Akron', 'OH');
INSERT INTO Address (PersonId, City, State) VALUES (4, 'Albany', 'NY');
INSERT INTO Address (PersonId, City, State) VALUES (5, 'Akron', 'OH');
INSERT INTO Address (PersonId, City, State) VALUES (7, 'Vancouver', 'WA');
INSERT INTO Address (PersonId, City, State) VALUES (8, 'Miami', 'FL');
INSERT INTO Address (PersonId, City, State) VALUES (9, 'Passadena', 'CA');
INSERT INTO Address (PersonId, City, State) VALUES (10, 'Austin', 'TX');

# Solution：
-- 考察JOIN的使用
-- JOIN: 如果表中有至少一个匹配，则返回行
-- LEFT JOIN: 即使右表中没有匹配，也从左表返回所有的行
-- RIGHT JOIN: 即使左表中没有匹配，也从右表返回所有的行
-- FULL JOIN: 只要其中一个表中存在匹配，就返回行
SELECT FirstName, LastName, City, State FROM Person LEFT JOIN Address ON Person.PersonId = Address.PersonId;
