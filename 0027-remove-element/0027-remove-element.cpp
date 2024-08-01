class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast = 0;
        int slow = 0;
        for (fast; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};