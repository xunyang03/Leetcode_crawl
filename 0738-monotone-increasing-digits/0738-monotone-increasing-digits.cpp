class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        int start_change = str.size();
        for (int i = str.size() - 1; i > 0; i--){
            if (str[i - 1] > str[i]){
                start_change = i;
                str[i - 1]--;
            }
        }
        for (int j = start_change; j < str.size(); j++){
            str[j] = '9';
        }
        return stoi(str);
    }
};