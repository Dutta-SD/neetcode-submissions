class Solution {
public:
    int numSteps(string s) {
        string temp = s;
        int n = temp.size();
        bool c = false;
        int steps = 0;

        for (int i = n - 1; i >= 0; i--) {
            bool d = temp.at(i) - '0';
            if (!i) {
                steps += c;
                continue;
            }
            steps += 1 + (c ^ d);
            c = c | d;
        }

        return steps;
    }
};