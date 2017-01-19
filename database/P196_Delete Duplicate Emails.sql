# Source: https://leetcode.com/problems/delete-duplicate-emails/
# Author: ML3426
# Date: 2017-01-19

-- Write a SQL query to delete all duplicate email entries in a table named Person, keeping only unique emails based on its smallest Id.
--
-- +----+------------------+
-- | Id | Email            |
-- +----+------------------+
-- | 1  | john@example.com |
-- | 2  | bob@example.com  |
-- | 3  | john@example.com |
-- +----+------------------+
-- Id is the primary key column for this table.
-- For example, after running your query, the above Person table should have the following rows:
--
-- +----+------------------+
-- | Id | Email            |
-- +----+------------------+
-- | 1  | john@example.com |
-- | 2  | bob@example.com  |
-- +----+------------------+

# DDL:
CREATE DATABASE IF NOT EXISTS leetcode DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

DROP TABLE IF EXISTS Person;

CREATE TABLE leetcode.Person (
  Id BIGINT PRIMARY KEY AUTO_INCREMENT,
  Email VARCHAR(50)
);

TRUNCATE Person;
INSERT INTO Person (Email) VALUES ('john@example.com');
INSERT INTO Person (Email) VALUES ('bob@example.com');
INSERT INTO Person (Email) VALUES ('john@example.com');

# Solution：
## 1297ms
DELETE FROM Person WHERE Id IN (SELECT Id FROM (SELECT A.Id Id FROM Person A JOIN Person B WHERE A.Id != B.Id AND A.Email = B.Email AND A.Id != (SELECT MIN(C.Id) FROM Person C WHERE C.Email = A.Email)) D);
