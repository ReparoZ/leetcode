# Source: https://leetcode.com/problems/big-countries/
# Author: ML3426
# Date: 2017-06-09

-- There is a table World
--
-- +-----------------+------------+------------+--------------+---------------+
-- | name            | continent  | area       | population   | gdp           |
-- +-----------------+------------+------------+--------------+---------------+
-- | Afghanistan     | Asia       | 652230     | 25500100     | 20343000      |
-- | Albania         | Europe     | 28748      | 2831741      | 12960000      |
-- | Algeria         | Africa     | 2381741    | 37100000     | 188681000     |
-- | Andorra         | Europe     | 468        | 78115        | 3712000       |
-- | Angola          | Africa     | 1246700    | 20609294     | 100990000     |
-- +-----------------+------------+------------+--------------+---------------+
-- A country is big if it has an area of bigger than 3 million square km or a population of more than 25 million.
--
-- Write a SQL solution to output big countries' name, population and area.
--
-- For example, according to the above table, we should output:
--
-- +--------------+-------------+--------------+
-- | name         | population  | area         |
-- +--------------+-------------+--------------+
-- | Afghanistan  | 25500100    | 652230       |
-- | Algeria      | 37100000    | 2381741      |
-- +--------------+-------------+--------------+

# DDL:
CREATE DATABASE IF NOT EXISTS leetcode DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

DROP TABLE IF EXISTS World;

CREATE TABLE leetcode.World (
  name VARCHAR(50),
  continent VARCHAR(50),
  area BIGINT,
  population BIGINT,
  gdp BIGINT
);

TRUNCATE World;
INSERT INTO leetcode.World (name, continent, area, population, gdp) VALUES ('Afghanistan', 'Asia', 652230, 25500100, 20343000);
INSERT INTO leetcode.World (name, continent, area, population, gdp) VALUES ('Albania', 'Europe', 28748, 2831741, 12960000);
INSERT INTO leetcode.World (name, continent, area, population, gdp) VALUES ('Algeria', 'Africa', 2381741, 37100000, 188681000);
INSERT INTO leetcode.World (name, continent, area, population, gdp) VALUES ('Andorra', 'Europe', 468, 78115, 3712000);
INSERT INTO leetcode.World (name, continent, area, population, gdp) VALUES ('Angola', 'Africa', 1246700, 20609294, 100990000);

# Solution：
## 2700ms
SELECT name, population, area FROM World WHERE area > 3000000 OR population > 25000000;
