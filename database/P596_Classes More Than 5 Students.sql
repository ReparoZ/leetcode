# Source: https://leetcode.com/problems/classes-more-than-5-students/
# Author: ML3426
# Date: 2017-06-09

-- There is a table courses with columns: student and class
--
-- Please list out all classes which have more than or equal to 5 students.
--
-- For example, the table:
--
-- +---------+------------+
-- | student | class      |
-- +---------+------------+
-- | A       | Math       |
-- | B       | English    |
-- | C       | Math       |
-- | D       | Biology    |
-- | E       | Math       |
-- | F       | Computer   |
-- | G       | Math       |
-- | H       | Math       |
-- | I       | Math       |
-- +---------+------------+
-- Should output:
--
-- +---------+
-- | class   |
-- +---------+
-- | Math    |
-- +---------+
-- Note:
-- The students should not be counted duplicate in each course.

# DDL:
CREATE DATABASE IF NOT EXISTS leetcode DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

DROP TABLE IF EXISTS courses;

CREATE TABLE leetcode.courses (
  student VARCHAR(50),
  class VARCHAR(50)
);

TRUNCATE courses;
INSERT INTO leetcode.courses (student, class) VALUES ('A', 'Math');
INSERT INTO leetcode.courses (student, class) VALUES ('B', 'English');
INSERT INTO leetcode.courses (student, class) VALUES ('C', 'Math');
INSERT INTO leetcode.courses (student, class) VALUES ('D', 'Biology');
INSERT INTO leetcode.courses (student, class) VALUES ('E', 'Math');
INSERT INTO leetcode.courses (student, class) VALUES ('F', 'Computer');
INSERT INTO leetcode.courses (student, class) VALUES ('G', 'Math');
INSERT INTO leetcode.courses (student, class) VALUES ('H', 'Math');
INSERT INTO leetcode.courses (student, class) VALUES ('I', 'Math');

# Solution：
## 1383ms
SELECT class FROM courses GROUP BY class HAVING COUNT(DISTINCT(student)) >= 5;
