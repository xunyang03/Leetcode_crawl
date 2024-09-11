class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int s_idx = s.size() - 1;
        int count = 0;
        for (int i = g.size() - 1; i >= 0; i--){
            if (s_idx >= 0 && g[i] <= s[s_idx]){
                count++;
                s_idx--;
            }
        }
        return count;
    }
};