class Solution {
private:
    vector<vector<int>> result;
    vector<int> subset;
public:
    void findSubset(vector<int>& nums, int startIdx){
        result.push_back(subset);
        if (startIdx >= nums.size()){
            return;
        }
        for (int i = startIdx; i < nums.size(); i++){
            if (i > startIdx && nums[i] == nums[i - 1])
                continue;
            subset.push_back(nums[i]);
            findSubset(nums, i + 1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        sort(nums.begin(), nums.end());
        findSubset(nums, 0);
        return result;
    }
};