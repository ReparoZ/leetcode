# Source: https://leetcode.com/problems/human-traffic-of-stadium/
# Author: ML3426
# Date: 2017-06-09

-- X city built a new stadium, each day many people visit it and the stats are saved as these columns: id, date, people
--
-- Please write a query to display the records which have 3 or more consecutive rows and the amount of people more than 100(inclusive).
--
-- For example, the table stadium:
-- +------+------------+-----------+
-- | id   | date       | people    |
-- +------+------------+-----------+
-- | 1    | 2017-01-01 | 10        |
-- | 2    | 2017-01-02 | 109       |
-- | 3    | 2017-01-03 | 150       |
-- | 4    | 2017-01-04 | 99        |
-- | 5    | 2017-01-05 | 145       |
-- | 6    | 2017-01-06 | 1455      |
-- | 7    | 2017-01-07 | 199       |
-- | 8    | 2017-01-08 | 188       |
-- +------+------------+-----------+
-- For the sample data above, the output is:
--
-- +------+------------+-----------+
-- | id   | date       | people    |
-- +------+------------+-----------+
-- | 5    | 2017-01-05 | 145       |
-- | 6    | 2017-01-06 | 1455      |
-- | 7    | 2017-01-07 | 199       |
-- | 8    | 2017-01-08 | 188       |
-- +------+------------+-----------+
-- Note:
-- Each day only have one row record, and the dates are increasing with id increasing.

# DDL:
CREATE DATABASE IF NOT EXISTS leetcode DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

DROP TABLE IF EXISTS stadium;

CREATE TABLE leetcode.stadium (
  id BIGINT PRIMARY KEY AUTO_INCREMENT,
  date DATE,
  people INTEGER
);

TRUNCATE stadium;
INSERT INTO leetcode.stadium (date, people) VALUES ('2017-01-01', 10);
INSERT INTO leetcode.stadium (date, people) VALUES ('2017-01-02', 109);
INSERT INTO leetcode.stadium (date, people) VALUES ('2017-01-03', 150);
INSERT INTO leetcode.stadium (date, people) VALUES ('2017-01-04', 99);
INSERT INTO leetcode.stadium (date, people) VALUES ('2017-01-05', 145);
INSERT INTO leetcode.stadium (date, people) VALUES ('2017-01-06', 1455);
INSERT INTO leetcode.stadium (date, people) VALUES ('2017-01-07', 199);
INSERT INTO leetcode.stadium (date, people) VALUES ('2017-01-08', 188);

# Solution：
## 214ms
## 利用Group完成根据某字段去重但展示其他字段的功能
SELECT id, date, people FROM stadium ORIGIN, (SELECT A.id AID, B.id BID, C.id CID FROM stadium A JOIN stadium B JOIN stadium C ON A.id = B.id - 1 AND A.id = C.id - 2 WHERE A.people >= 100 AND B.people >= 100 AND C.people >= 100) ALIAS WHERE id = AID OR id = BID OR id = CID GROUP BY id;
