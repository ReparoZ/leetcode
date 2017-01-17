# Source: https://leetcode.com/problems/rank-scores/
# Author: ML3426
# Date: 2017-01-17

-- Write a SQL query to rank scores. If there is a tie between two scores, both should have the same ranking. Note that after a tie, the next ranking number should be the next consecutive integer value. In other words, there should be no "holes" between ranks.
--
-- +----+-------+
-- | Id | Score |
-- +----+-------+
-- | 1  | 3.50  |
-- | 2  | 3.65  |
-- | 3  | 4.00  |
-- | 4  | 3.85  |
-- | 5  | 4.00  |
-- | 6  | 3.65  |
-- +----+-------+
-- For example, given the above Scores table, your query should generate the following report (order by highest score):
--
-- +-------+------+
-- | Score | Rank |
-- +-------+------+
-- | 4.00  | 1    |
-- | 4.00  | 1    |
-- | 3.85  | 2    |
-- | 3.65  | 3    |
-- | 3.65  | 3    |
-- | 3.50  | 4    |
-- +-------+------+

# DDL:
CREATE DATABASE IF NOT EXISTS leetcode DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

DROP TABLE IF EXISTS Scores;

CREATE TABLE leetcode.Scores (
  Id BIGINT PRIMARY KEY AUTO_INCREMENT,
  Score DOUBLE
);

-- Test For Normal:
INSERT INTO Scores (Score) VALUES (3.50);
INSERT INTO Scores (Score) VALUES (3.65);
INSERT INTO Scores (Score) VALUES (4.00);
INSERT INTO Scores (Score) VALUES (3.85);
INSERT INTO Scores (Score) VALUES (4.00);
INSERT INTO Scores (Score) VALUES (3.65);

# Solution：
SELECT Score, (SELECT COUNT(*) FROM (SELECT DISTINCT Score S FROM Scores) TMP WHERE S >= Score) Rank FROM Scores ORDER BY Score DESC;
