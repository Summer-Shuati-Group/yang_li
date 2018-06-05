/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool comp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), comp);
		// first sort the start by increasing order 
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i+1].start <= intervals[i].end) {
                intervals[i].end = max(intervals[i+1].end, intervals[i].end);
                intervals.erase(intervals.begin() + i + 1);
                i--;
            } // then just compare the end, choose the bigger one
            
        }
        return intervals; 
    }
};