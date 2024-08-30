class Solution {
private:
vector<vector<int>> result;
vector<int> combo; // individual combo size = k
void backtrack(int n, int k, int startIdx){
    // stopping criteria
    if (combo.size() == k){
        result.push_back(combo);
        return;
    }
    // single layer loop logic
    for (int i = startIdx; i<=n; i++){
        combo.push_back(i);
        backtrack(n, k, i + 1); // recurse
        combo.pop_back(); // backtrack
    }
}    

public:
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        combo.clear();
        backtrack(n, k, 1);
        return result;
    }
};