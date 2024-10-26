class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) return n;
        int dp[2];
        dp[0] = 1;
        dp[1] = 2;
        int N = n - 2;
        while (N--){
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};