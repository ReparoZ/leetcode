// Source: https://leetcode.com/problems/jump-game/
// Author: ML3426
// Date: 2017-02-19

/*
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their start times.
 * 
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 * 
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 * 
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
    // 要考虑到newInterval位于最前面和最后面的可能，当newInterval位于最后时，还要考虑他也有可能需要合并
    // 时间复杂度为O(N)，空间复杂度为O(1)
    // Time: 16ms
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        bool inserted = false;

        for (int i = 0; i < intervals.size(); ++i) {
            if (res.size() == 0)
                newInterval.start < intervals[0].start ? res.push_back(newInterval) : res.push_back(intervals[i]);
            else if (newInterval.start >= res.back().start && newInterval.start <= intervals[i].start) {
                if (newInterval.start > res.back().end) res.push_back(newInterval);
                else {
                    Interval temp(res.back().start, max(res.back().end, newInterval.end));
                    res.pop_back();
                    res.push_back(temp);
                }
                inserted = true;
            }

            if (intervals[i].start <= res.back().end) {
                Interval temp(res.back().start, max(res.back().end, intervals[i].end));
                res.pop_back();
                res.push_back(temp);
            } else {
                res.push_back(intervals[i]);
            }
        }

        if (!inserted) {
            if (res.size() > 0 && newInterval.start <= res.back().end) {
                Interval temp(res.back().start, max(res.back().end, newInterval.end));
                res.pop_back();
                res.push_back(temp);
            } else res.push_back(newInterval);
        }

        return res;
    }
};