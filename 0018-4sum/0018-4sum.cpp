class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int first = 0; first < n - 3; first++) {
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            for (int second = first + 1; second < n - 2; second++) {
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;
                int third = second + 1;
                int fourth = n - 1;
                while (third < fourth) {
                    long sum = (long)nums[first] + nums[second] + nums[third] +
                               nums[fourth];
                    if (sum == target) {
                        ans.push_back({nums[first], nums[second], nums[third],
                                       nums[fourth]});
                        third++;
                        fourth--;
                        while (third < fourth && nums[third] == nums[third - 1])
                            third++;
                        while (third < fourth &&
                               nums[fourth] == nums[fourth + 1])
                            fourth--;
                    } else if (sum > target)
                        fourth--;
                    else
                        third++;
                }
            }
        }
        return ans;
    }
};