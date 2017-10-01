# Source: https://leetcode.com/problems/not-boring-movies/
# Author: ML3426
# Date: 2017-10-01

-- X city opened a new cinema, many people would like to go to this cinema. The cinema also gives out a poster indicating the movies’ ratings and descriptions.
--
-- Please write a SQL query to output movies with an odd numbered ID and a description that is not 'boring'. Order the result by rating.
--
-- For example, table cinema:
--
-- +---------+-----------+--------------+-----------+
-- |   id    | movie     |  description |  rating   |
-- +---------+-----------+--------------+-----------+
-- |   1     | War       |   great 3D   |   8.9     |
-- |   2     | Science   |   fiction    |   8.5     |
-- |   3     | irish     |   boring     |   6.2     |
-- |   4     | Ice song  |   Fantacy    |   8.6     |
-- |   5     | House card|   Interesting|   9.1     |
-- +---------+-----------+--------------+-----------+
-- For the example above, the output should be:
-- +---------+-----------+--------------+-----------+
-- |   id    | movie     |  description |  rating   |
-- +---------+-----------+--------------+-----------+
-- |   5     | House card|   Interesting|   9.1     |
-- |   1     | War       |   great 3D   |   8.9     |
-- +---------+-----------+--------------+-----------+

# DDL:
CREATE DATABASE IF NOT EXISTS leetcode DEFAULT CHARSET utf8 COLLATE utf8_general_ci;
USE leetcode;

DROP TABLE IF EXISTS cinema;

CREATE TABLE cinema (
  id BIGINT PRIMARY KEY AUTO_INCREMENT,
  movie VARCHAR(255),
  description VARCHAR(255),
  rating FLOAT(2, 1)
);

TRUNCATE cinema;
INSERT INTO cinema (movie, description, rating) VALUES ('War', 'great 3D', '8.9');
INSERT INTO cinema (movie, description, rating) VALUES ('Science', 'fiction', '8.5');
INSERT INTO cinema (movie, description, rating) VALUES ('irish', 'boring', '6.2');
INSERT INTO cinema (movie, description, rating) VALUES ('Ice song', 'Fantacy', '8.6');
INSERT INTO cinema (movie, description, rating) VALUES ('House card', 'Interesting', '9.1');

# Solution：
## 152ms
## 简单查询
SELECT * FROM cinema WHERE id & 1 AND description <> 'boring' ORDER BY rating DESC;
