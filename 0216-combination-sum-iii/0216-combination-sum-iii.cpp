class Solution {
private:
    vector<vector<int>> result;
    vector<int> combo;
    void backtrack(int k, int n, int sum, int startIdx){
        if (sum > n) return;
        if (combo.size() == k){
            if (sum == n){
                result.push_back(combo);
                return;
            }
        }
        for (int i = startIdx; i <= 9 - (k - combo.size()) + 1; i++){
            combo.push_back(i);
            sum += i;
            backtrack(k, n, sum, i + 1);
            sum -= i;
            combo.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 0, 1);
        return result;
    }
};