class Solution {
static bool cmp(vector<int>& v1, vector<int>& v2){return v1[0] < v2[0];}
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> res;
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] <= right){
                right = max(right, intervals[i][1]);
            }
            else{
                res.emplace_back(vector<int>{left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        res.emplace_back(vector<int>{left, right});
        return res;
    }
};