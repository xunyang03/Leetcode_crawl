class Solution {
public:
    bool canJump(vector<int>& nums) {
        int range = 0;
        for (int i = 0; i <= range; i++){
            range = max(i + nums[i], range);
            if (range >= nums.size() - 1)
                return true;
        }
        return false;
    }
};