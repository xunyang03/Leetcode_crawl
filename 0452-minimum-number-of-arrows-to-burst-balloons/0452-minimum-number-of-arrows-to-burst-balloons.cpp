class Solution {
    static bool cmp(vector<int>& v1, vector<int>& v2) { return v1[0] < v2[0]; }

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int result = 1;
        int right = points[0][1]; // x_end
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > right) {
                result++;
                right = points[i][1];
            } else {
                right = points[i][1] < right ? points[i][1] : right;
            }
        }
        return result;
    }
};