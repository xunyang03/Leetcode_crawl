class Solution {
private:
    vector<int> rec;
public:
    int fmax(int n){
        if (n == 1)
            return 1;
        if (rec[n] != -1)
            return rec[n];
        int result = 0;
        for (int m = 1; m < n; m++){
            result = max({result, (n - m)*m, fmax(n - m)*m});
        }
        rec[n] = result;
        return result;
    }
    
    int integerBreak(int n) {
        rec = vector<int>(n+1, -1);
        return fmax(n);
    }
};