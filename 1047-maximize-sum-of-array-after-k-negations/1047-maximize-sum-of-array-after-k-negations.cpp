class Solution {
private:
    static bool abscmp(int a, int b) { return abs(a) > abs(b); }
    int sumArray(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
            res += nums[i];
        return res;
    }

public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), abscmp);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
        }
        if (k % 2 == 1) {
            nums[nums.size() - 1] *= -1;
        }
        return sumArray(nums);
    }
};