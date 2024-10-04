class Solution {
public:
    vector<int> partitionLabels(string s) {
        int end_loc[26] = {0};
        vector<int> result;
        for (int i = 0; i < s.size(); i++) {
            end_loc[s[i] - 'a'] = i;
        }
        int left = 0, right = 0;
        for (int j = 0; j < s.size(); j++) {
            right = max(right, end_loc[s[j] - 'a']);
            if (j == right) {
                result.push_back(right - left + 1);
                left = j + 1;
            }
        }
        return result;
    }
};