class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++){
            cnt += nums[i];
            result = cnt > result? cnt : result;
            if (cnt < 0)
                cnt = 0;
        }
        return result;
    }
};