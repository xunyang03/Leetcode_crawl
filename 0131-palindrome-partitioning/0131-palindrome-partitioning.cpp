class Solution {
private:
    vector<vector<string>> result;
    vector<string> combo;
public:
    const bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

    void findCombo(string& s, int startIdx) {
        if (startIdx >= s.size()) {
            result.push_back(combo);
            return;
        }
        for (int i = startIdx; i < s.size(); i++) {
            if (!isPalindrome(s, startIdx, i))
                continue;
            combo.push_back(s.substr(startIdx, i - startIdx + 1));
            findCombo(s, i + 1);
            combo.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        result.clear();
        if (s.size() == 0) return result;
        findCombo(s, 0);
        return result;
    }
};