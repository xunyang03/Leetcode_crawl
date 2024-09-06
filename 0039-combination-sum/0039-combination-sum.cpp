class Solution {
private:
    vector<vector<int>> result;
    vector<int> combo;
    int sum;
    void findCombo(vector<int>& candidates, int target, int startIdx) {
        if (sum > target)
            return;
        if (sum == target) {
            result.push_back(combo);
            return;
        }

        for (int i = startIdx; i < candidates.size(); i++) {
            int candi = candidates[i];
            combo.push_back(candi);
            sum += candi;
            findCombo(candidates, target, i);
            sum -= candi;
            combo.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        sort(candidates.begin(), candidates.end());
        findCombo(candidates, target, 0);
        return result;
    }
};