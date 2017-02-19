// Source: https://leetcode.com/problems/jump-game/
// Author: ML3426
// Date: 2017-02-19

/*
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 */

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    // 先利用start对于intervals进行排序，再将相邻的两个元素如果有重叠则合并
    // 时间复杂度为O(nlgn)，空间复杂度为O(1)
    // Time: 13ms
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), compIntervals);

        for (int i = 0; i < intervals.size(); ++i) {
            if (res.size() == 0) res.push_back(intervals[i]);
            else if (intervals[i].start <= res.back().end) {
                Interval temp(res.back().start, max(res.back().end, intervals[i].end));
                res.pop_back();
                res.push_back(temp);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }

    static bool compIntervals(const Interval &left, const Interval &right) {
        return left.start < right.start;
    }
};