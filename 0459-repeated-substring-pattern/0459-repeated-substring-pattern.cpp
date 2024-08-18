class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        ss.erase(ss.begin());
        ss.erase(ss.end() - 1);
        if (ss.find(s) != std::string::npos) // find s in ss
            return true;
        return false;
    }
};