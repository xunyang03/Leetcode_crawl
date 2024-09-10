class Solution {
private:
    vector<vector<int>> result;
    vector<int> arrange;
    unordered_set<int> used_loc; // 记录数组中的位置
public:
    void findArrangement(vector<int>& nums){
        if (arrange.size() == nums.size()){
            result.push_back(arrange);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (used_loc.find(i) != used_loc.end())
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && used_loc.find(i - 1) == used_loc.end()) // 前一位相同的数没有被使用，即为重复情况
                continue;
            arrange.push_back(nums[i]);
            used_loc.insert(i);
            findArrangement(nums);
            used_loc.erase(i);
            arrange.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        sort(nums.begin(), nums.end());
        findArrangement(nums);
        return result;
    }
};