class Solution {
private:
    vector<string> result;
    string combo;
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };

    void findCombo(string& digits, int id) {
        if (combo.size() == digits.size()) {
            result.push_back(combo);
            return;
        }
        char digit = digits[id];
        int num = digit - '0';
        string letters = letterMap[num];
        for (char letter : letters) {
            combo.push_back(letter);
            findCombo(digits, id + 1);
            combo.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        result.clear();
        if (digits.size() == 0)
            return result;
        findCombo(digits, 0);
        return result;
    }
};