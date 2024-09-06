class Solution {
private:
    vector<vector<int>> result;
    vector<int> combo;
    int sum = 0;
    void findCombo(vector<int>& candidates, int target, int startIdx){
        if (sum > target)
            return;
        if (sum == target){
            result.push_back(combo);
            return;
        }
        for (int i = startIdx; i < candidates.size(); i++){
            if (i > startIdx && candidates[i] == candidates[i - 1]) { // 去重
                continue;
            }
            combo.push_back(candidates[i]);
            sum += candidates[i];
            findCombo(candidates, target, i + 1);
            sum -= candidates[i];
            combo.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        sort(candidates.begin(), candidates.end());
        findCombo(candidates, target, 0);
        return result;
    }
};