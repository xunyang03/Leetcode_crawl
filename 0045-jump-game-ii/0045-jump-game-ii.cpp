class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int result = 1; // least step
        int range = 0;
        int start = 0;
        for (int i = 0; i < nums.size(); i++){
            range = max(i + nums[i], range); // the max dist that can reach
            if (range >= nums.size() - 1)
                break;
            if (i == start){    // need a new jump
                start = range; // update the new start as the max range
                result++;
                }
        }
        return result;
    }
};