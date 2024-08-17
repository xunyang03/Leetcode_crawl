class Solution {
public:
    bool isAnagram(string s, string t) {
        int rec[26] = {0};
        for (auto& ch : s) {
            rec[ch - 'a']++;
        }
        for (auto& ch : t) {
            rec[ch - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (rec[i] != 0)
                return false;
        }
        return true;
    }
};