class Solution {
    static bool cmp(vector<int>& v1, vector<int>& v2) { return v1[0] < v2[0]; }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int overlap = 1;
        int bond = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= bond) {
                overlap++;
                bond = intervals[i][1];
            } else {
                bond = min(intervals[i][1], bond);
            }
        }
        return intervals.size() - overlap;
    }
};