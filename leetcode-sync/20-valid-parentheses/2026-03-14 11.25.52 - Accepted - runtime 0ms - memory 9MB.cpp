class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') stk.push(c);
            else if (stk.empty()) return false;
            else {
                char t = stk.top();
                if (
                    (c == ')' && t != '(') ||
                    (c == ']' && t != '[') ||
                    (c == '}' && t != '{')
                ) return false;
                else stk.pop();
            }
        }

        return stk.empty();
    }
};