# Source: https://leetcode.com/problems/word-frequency/
# Author: ML3426
# Date: 2017-01-15

# Write a bash script to calculate the frequency of each word in a text file words.txt.
#
# For simplicity sake, you may assume:

# words.txt contains only lowercase characters and space ' ' characters.
# Each word must consist of lowercase characters only.
# Words are separated by one or more whitespace characters.
# For example, assume that words.txt has the following content:
#
# the day is sunny the the
# the sunny is is
# # Your script should output the following, sorted by descending frequency:
# the 4
# is 3
# sunny 2
# day 1
# Note:
# Don't worry about handling ties, it is guaranteed that each word's frequency count is unique.
#
# Hint:
# Could you write it in one-line using Unix pipes?

# Solution:
## tr -s ' ' '\n'：将空格转换为换行符，让文本变成以单词为行的形式。（-s是为了压缩重复的空格）
## sort & uniq -c：文本排序统计的基础方法。
## sort -r：将统计结果按照从大到小排列。（-r reverse sort）
## awk '{ print $2, $1 }' 将（数字，单词）的统计结果反转为（单词，数字）。

## 15ms（tr sort uniq耗时长）
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{ print $2, $1 }'

# Solution2（转自illuz）:
## 使用awk（速度最快）

## 9ms
awk '{ for (i=1; i<=NF; i++) { ++D[$i]; } } END { for (i in D) { print i, D[i] } }' words.txt | sort -nr -k 2
