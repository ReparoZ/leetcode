// Source: https://leetcode.com/problems/word-ladder/
// Author: ML3426
// Date: 2018-02-11

/**
 * Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 * For example,
 * 
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 * 
 * Note:
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * UPDATE (2017/1/20):
 * The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 从上到下的广度优先搜索
    // Time: 35ms
    int ladderLength(const string &beginWord, const string &endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.find(endWord) == wordSet.end()) return 0;
        unordered_set<string> s1, s2;
        s1.insert(beginWord);
        s2.insert(endWord);
        int ans = 1;
        while(!s1.empty() && !s2.empty()){
            ans++;
            if(s1.size() > s2.size()) swap(s1, s2);
            unordered_set<string> temp;
            for (auto w : s1) {
                for(int i = 0; i < w.size(); i++){
                    char c = w[i];
                    for(int j = 0; j < 26; j++){
                        w[i] = 'a' + j;
                        if(s2.find(w) != s2.end()) return ans;
                        if(wordSet.find(w) != wordSet.end()){
                            temp.insert(w);
                            wordSet.erase(w);
                        }
                    }
                    w[i] = c;
                }
            }
            swap(s1, temp);
        }
        return 0;
    }
};