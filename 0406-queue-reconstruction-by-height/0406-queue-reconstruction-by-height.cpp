class Solution {
static bool cmp(vector<int>& v1, vector<int>& v2) {
        if (v1[0] == v2[0])
            return v1[1] < v2[1];
        return v1[0] > v2[0];
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);

        vector<vector<int>> h_que;
        for (auto& person : people) {
            int pos = person[1];
            h_que.insert(h_que.begin() + pos, person);
        }
        return h_que;
    }
};