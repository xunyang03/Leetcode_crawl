class Solution {
private:
    vector<string> result;
    int dotnum = 0;

public:
    const bool isValid(const string& s) {
        if (s.size() < 1 || s.size() > 3)
            return false;
        if (s[0] == '0' && s.size() > 1)
            return false;
        int sum = 0;
        for (auto ch : s) {
            int val = ch - '0';
            if (val >= 0 && val <= 9) {
                sum = 10 * sum + val;
            } else
                return false;
        }
        if (sum > 255)
            return false;
        return true;
    }
    void findAddress(string& s, int startIdx) {
        if (dotnum == 3) {
            if (isValid(s.substr(startIdx, s.size() - startIdx))) {
                result.push_back(s);
                return;
            }
        }
        for (int i = startIdx; i < s.size(); i++) {
            string ss = s.substr(startIdx, i - startIdx + 1);
            if (!isValid(ss))
                continue;
            s.insert(s.begin() + i + 1, '.');
            dotnum++;
            findAddress(s, i + 2); // 插入逗点之后下一个子串的起始位置为i+2
            dotnum--;
            s.erase(s.begin() + i + 1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        findAddress(s, 0);
        return result;
    }
};