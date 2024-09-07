class Solution {
private:
    vector<vector<int>> result;
    vector<int> sequence;
public:
    void backtrack(vector<int>& nums, int startIdx){
        if (sequence.size() >= 2)
            result.push_back(sequence);
        if (startIdx >= nums.size())
            return;
        unordered_set<int> used;
        for (int i = startIdx; i < nums.size(); i++){
            if (!sequence.empty() && nums[i] < sequence[sequence.size() - 1])
                continue;
            if (used.find(nums[i]) != used.end())
                continue;
            sequence.push_back(nums[i]);
            used.insert(nums[i]);
            backtrack(nums, i + 1);
            sequence.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        backtrack(nums, 0);
        return result;
    }
};