class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int result = 1;
        int diff = 0;
        int prediff = 0;
        for (int i = 0; i < nums.size()-1; i++){
            diff = nums[i + 1] - nums[i];
            if ((prediff <= 0 && diff > 0) || (prediff >= 0 && diff < 0)){
                result++;
                prediff = diff;
            }
        }
        return result;
    }
};