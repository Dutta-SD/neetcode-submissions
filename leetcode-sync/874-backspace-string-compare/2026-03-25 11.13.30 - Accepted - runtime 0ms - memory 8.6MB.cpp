class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1, stk2;
        string f, g;

        for (auto c : s) {
            if (c != '#') stk1.push(c);
            else if (!stk1.empty()) stk1.pop();
        }

        for (auto c : t) {
            if (c != '#') stk2.push(c);
            else if (!stk2.empty()) stk2.pop();
        }

        while(!stk1.empty()){
            char c = stk1.top();
            stk1.pop();
            f += c;
        }

        while(!stk2.empty()){
            char c = stk2.top();
            stk2.pop();
            g += c;
        }

        return f == g;
    }
};