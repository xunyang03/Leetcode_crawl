class Solution {
public:
    bool isValid(string s) {
        stack<int> store;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                store.push(c);
            } else if (c == ')') {
                if (store.empty() || store.top() != '(')
                    return false;
                else
                    store.pop();
            } else if (c == ']') {
                if (store.empty() || store.top() != '[')
                    return false;
                else
                    store.pop();
            } else if (c == '}') {
                if (store.empty() || store.top() != '{')
                    return false;
                else
                    store.pop();
            }
        }
        return store.empty();
    }
};