// Source: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// Author: ML3426
// Date: 2017-02-10

/*
 * You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
 * 
 * For example, given:
 * s: "barfoothefoobarman"
 * words: ["foo", "bar"]
 * 
 * You should return the indices: [0,9].
 * (order does not matter).
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Time: 26ms
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> result;
        if (s.size() <= 0 || words.size() <= 0) {
            return result;
        }

        int n = (int) s.size(), m = (int) words.size(), l = (int) words[0].size();

        //put all of words into a map    
        unordered_map<string, int> expected;
        for (int i = 0; i < m; i++) {
            if (expected.find(words[i]) != expected.end()) {
                expected[words[i]]++;
            } else {
                expected[words[i]] = 1;
            }
        }

        for (int i = 0; i < l; i++) {
            unordered_map<string, int> actual;
            int count = 0; //total count
            int winLeft = i;
            for (int j = i; j <= n - l; j += l) {
                string word = s.substr((unsigned long) j, (unsigned long) l);
                //if not found, then restart from j+1;
                if (expected.find(word) == expected.end()) {
                    actual.clear();
                    count = 0;
                    winLeft = j + l;
                    continue;
                }
                count++;
                //count the number of "word"
                if (actual.find(word) == actual.end()) {
                    actual[word] = 1;
                } else {
                    actual[word]++;
                }
                // If there is more appearance of "word" than expected
                if (actual[word] > expected[word]) {
                    string tmp;
                    do {
                        tmp = s.substr((unsigned long) winLeft, (unsigned long) l);
                        count--;
                        actual[tmp]--;
                        winLeft += l;
                    } while (tmp != word);
                }

                // if total count equals words's size, find one result
                if (count == m) {
                    result.push_back(winLeft);
                    string tmp = s.substr((unsigned long) winLeft, (unsigned long) l);
                    actual[tmp]--;
                    winLeft += l;
                    count--;
                }

            }
        }

        return result;
    }
};