class Solution {
private:
    vector<vector<int>> result;
    vector<int> set;
public:
    void findSubset(vector<int>& nums, int startIdx){
        result.push_back(set);
        if (startIdx >= nums.size()){            
            return;
        }
        for (int i = startIdx; i< nums.size(); i++){
            set.push_back(nums[i]);
            findSubset(nums, i + 1);
            set.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        findSubset(nums, 0);
        return result;
    }
};