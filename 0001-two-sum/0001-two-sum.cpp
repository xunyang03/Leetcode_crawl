class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++) {
            int res = target - nums[i];
            auto key = record.find(res);
            if (key != record.end())
                return {i, key->second};
            record.insert(pair<int,int>(nums[i],i));
        }
        return {};
    }
};