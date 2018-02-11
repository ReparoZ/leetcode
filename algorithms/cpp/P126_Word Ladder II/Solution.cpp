// Source: https://leetcode.com/problems/word-ladder-ii/
// Author: ML3426
// Date: 2017-10-22

/**
 * Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
 * 
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 * For example,
 * 
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * Return
 *   [
 *     ["hit","hot","dot","dog","cog"],
 *     ["hit","hot","lot","log","cog"]
 *   ]
 * Note:
 * Return an empty list if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * UPDATE (2017/1/20):
 * The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 从上到下的广度优先搜索
    // Time: 886ms
    vector<vector<string>> findLadders(const string &beginWord, const string &endWord, vector<string> &wordList) {
        unordered_map<string, vector<string>> map;
        bool findEnd = false;

        vector<string> currentLayer = {beginWord};
        set<int> removedSet = {};
        auto beginIter = find(wordList.begin(), wordList.end(), beginWord);
        if (beginIter != wordList.end()) wordList.erase(beginIter);
        auto endIter = find(wordList.begin(), wordList.end(), endWord);
        if (endIter == wordList.end()) return {};

        while (!currentLayer.empty()) {
            vector<string> thisLayer = {};
            for (const auto &thisWord : currentLayer) {
                if (isDiffOne(thisWord, endWord)) {
                    map.insert(pair<string, vector<string>>(thisWord, {endWord}));
                    thisLayer = {};
                    findEnd = true;
                } else if (!findEnd) {
                    pair<string, vector<string>> currentPair = {thisWord, {}};
                    for (auto j = static_cast<int>(wordList.size() - 1); j >= 0; --j) {
                        if (isDiffOne(thisWord, wordList[j])) {
                            thisLayer.push_back(wordList[j]);
                            currentPair.second.push_back(wordList[j]);
                            removedSet.insert(j);
                        }
                    }
                    map.insert(currentPair);
                }
            }
            currentLayer = thisLayer;
            for (auto i = removedSet.rbegin(); i != removedSet.rend(); ++i) wordList.erase(wordList.begin() + *i);
            removedSet.clear();
        }
        return generatePath(map, beginWord, endWord);
    }

    bool isDiffOne(const string &oriWord, const string &transformedWord) {
        bool diffOne = false;

        for (int i = 0; i < oriWord.length(); ++i) {
            if (oriWord[i] != transformedWord[i]) {
                if (diffOne) return false;
                else diffOne = true;
            }
        }
        return diffOne;
    }

    vector<vector<string>> generatePath(const unordered_map<string, vector<string>> &resultMap,
                                        const string &start, const string &end) {
        vector<vector<string>> result = {};
        if (start == end) {
            return {{end}};
        } else {
            if (resultMap.find(start) != resultMap.end()) {
                auto alters = resultMap.at(start);
                for (auto &&alter : alters) {
                    auto lastResult = generatePath(resultMap, alter, end);
                    for (auto &&path : lastResult) {
                        path.insert(path.begin(), start);
                        result.push_back(path);
                    }
                }
            }
        }
        return result;
    }
};