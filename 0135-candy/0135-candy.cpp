class Solution {
public:
    int sum(vector<int>& nums) {
        int cnt = 0;
        for (int idx = 0; idx < nums.size(); idx++){
            cnt += nums[idx];
        }
        return cnt;
    }
    int candy(vector<int>& ratings) {
        vector<int> candy_array(ratings.size(), 1);
        for (int i = 1; i < candy_array.size(); i++) {
            if (ratings[i] > ratings[i - 1])
                candy_array[i] = candy_array[i - 1] + 1;
        }
        for (int j = candy_array.size() - 2; j >= 0; j--) {
            if (ratings[j] > ratings[j + 1])
                candy_array[j] = candy_array[j] > candy_array[j + 1] + 1
                                     ? candy_array[j]
                                     : candy_array[j + 1] + 1;
        }
        return sum(candy_array);
    }
};