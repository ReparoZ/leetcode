# Source: https://leetcode.com/problems/duplicate-emails/
# Author: ML3426
# Date: 2017-01-19

-- Write a SQL query to find all duplicate emails in a table named Person.
--
-- +----+---------+
-- | Id | Email   |
-- +----+---------+
-- | 1  | a@b.com |
-- | 2  | c@d.com |
-- | 3  | a@b.com |
-- +----+---------+
-- For example, your query should return the following for the above table:
--
-- +---------+
-- | Email   |
-- +---------+
-- | a@b.com |
-- +---------+
-- Note: All emails are in lowercase.

# DDL:
CREATE DATABASE IF NOT EXISTS leetcode DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

DROP TABLE IF EXISTS Person;

CREATE TABLE leetcode.Person (
  Id BIGINT PRIMARY KEY AUTO_INCREMENT,
  Email VARCHAR(50)
);

TRUNCATE Person;
INSERT INTO Person (Email) VALUES ('a@b.com');
INSERT INTO Person (Email) VALUES ('c@d.com');
INSERT INTO Person (Email) VALUES ('a@b.com');

# Solution：
## GroupBy-Having(944ms)
SELECT Email FROM Person GROUP BY Email HAVING COUNT(*) > 1;

## Where(1025ms)
SELECT DISTINCT(A.Email) Email FROM Person A JOIN Person B WHERE A.Email = B.Email AND A.Id != B.Id;
