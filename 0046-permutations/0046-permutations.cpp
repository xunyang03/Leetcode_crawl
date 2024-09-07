class Solution {
private:
    vector<vector<int>> result;
    vector<int> combo;
    unordered_set<int> used;
public:
    void findCombo(vector<int>& nums){
        if (combo.size() == nums.size()){
            result.push_back(combo);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (used.find(nums[i]) != used.end())
                continue;
            combo.push_back(nums[i]);
            used.insert(nums[i]);
            findCombo(nums);
            used.erase(nums[i]);
            combo.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        findCombo(nums);
        return result;
    }
};