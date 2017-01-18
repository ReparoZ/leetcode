# Source: https://leetcode.com/problems/customers-who-never-order/
# Author: ML3426
# Date: 2017-01-19

-- Suppose that a website contains two tables, the Customers table and the Orders table. Write a SQL query to find all customers who never order anything.
--
-- Table: Customers.
--
-- +----+-------+
-- | Id | Name  |
-- +----+-------+
-- | 1  | Joe   |
-- | 2  | Henry |
-- | 3  | Sam   |
-- | 4  | Max   |
-- +----+-------+
-- Table: Orders.
--
-- +----+------------+
-- | Id | CustomerId |
-- +----+------------+
-- | 1  | 3          |
-- | 2  | 1          |
-- +----+------------+
-- Using the above tables as example, return the following:
--
-- +-----------+
-- | Customers |
-- +-----------+
-- | Henry     |
-- | Max       |
-- +-----------+

# DDL:
CREATE DATABASE IF NOT EXISTS leetcode DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

DROP TABLE IF EXISTS Customers;
DROP TABLE IF EXISTS Orders;

CREATE TABLE leetcode.Customers (
  Id BIGINT PRIMARY KEY AUTO_INCREMENT,
  Name VARCHAR(15)
);

CREATE TABLE leetcode.Orders (
  Id BIGINT PRIMARY KEY AUTO_INCREMENT,
  CustomerId BIGINT
);

TRUNCATE Customers;
INSERT INTO Customers (Name) VALUES ('Joe');
INSERT INTO Customers (Name) VALUES ('Henry');
INSERT INTO Customers (Name) VALUES ('Sam');
INSERT INTO Customers (Name) VALUES ('Max');

TRUNCATE Orders;
INSERT INTO Orders (CustomerId) VALUES (3);
INSERT INTO Orders (CustomerId) VALUES (1);

# Solution：
## Where-NotIn(1121ms)
SELECT Name Customers FROM Customers WHERE Id NOT IN (SELECT CustomerId FROM Orders);

## LEFT JOIN(838ms)
SELECT Name Customers FROM Customers LEFT JOIN Orders ON Customers.Id = CustomerId WHERE Orders.Id IS NULL;
