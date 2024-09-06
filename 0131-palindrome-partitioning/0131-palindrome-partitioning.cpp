class Solution {
private:
    vector<vector<string>> result;
    vector<string> combo;
public:
    const bool isPalindrome(const string& s) {
        int middle = s.size() / 2;
        for (int i = 0; i < middle; i++) {
            if (s[i] != s[s.size() - i - 1])
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
            string ss = s.substr(startIdx, i - startIdx + 1);
            if (!isPalindrome(ss))
                continue;
            combo.push_back(ss);
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