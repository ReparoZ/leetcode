// Source: https://leetcode.com/problems/text-justification/
// Author: ML3426
// Date: 2017-02-23

/*
 * Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
 * 
 * You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 * 
 * Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 * 
 * For the last line of text, it should be left justified and no extra space is inserted between words.
 * 
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 * 
 * Return the formatted lines as:
 * [
 *    "This    is    an",
 *    "example  of text",
 *    "justification.  "
 * ]
 * Note: Each word is guaranteed not to exceed L in length.
 * 
 * click to show corner cases.
 * 
 * Corner Cases:
 * A line other than the last line might contain only one word. What should you do in this case?
 * In this case, that line should be left-justified.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 时间复杂度为O(N)，空间复杂度为O(N)
    // Time: 0ms
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;

        vector<string> temp;
        int wordLength = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (wordLength + temp.size() + words[i].length() > maxWidth) {
                res.push_back(makeJustify(temp, wordLength, maxWidth, false));
                temp.clear();
                wordLength = 0;
            }
            temp.push_back(words[i]);
            wordLength += (int) words[i].length();
        }
        res.push_back(makeJustify(temp, wordLength, maxWidth, true));

        return res;
    }

    string makeJustify(vector<string> &words, int wordLength, int maxWidth, bool lastLine) {
        string res;
        if (words.size() == 1) {
            res = words[0] + string((unsigned long) (maxWidth - wordLength), ' ');
            return res;
        } else if (lastLine) {
            for (int i = 0; i < words.size(); ++i) {
                res += words[i];
                if (i != words.size() - 1) res += " ";
            }
            res += string(maxWidth - res.length(), ' ');
        } else {
            int baseInterval = int((maxWidth - wordLength) / (words.size() - 1));
            int leftInterval = int((maxWidth - wordLength) - baseInterval * (words.size() - 1));
            for (int i = 0; i < words.size(); ++i) {
                res += words[i];
                if (i != words.size() - 1) {
                    res += string((unsigned long) baseInterval, ' ');
                    if (leftInterval-- > 0) res += " ";
                }
            }
        }

        return res;
    }
};
