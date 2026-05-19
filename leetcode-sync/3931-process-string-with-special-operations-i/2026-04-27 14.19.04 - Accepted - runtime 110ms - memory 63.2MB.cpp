class Solution {
public:
    string processStr(const string& s) {
        deque<char> dq;

        bool readFront = true;

        for (char c : s) {
            if (c == '%') {
                readFront = !readFront;
            } 
            else if (c == '#') {
                deque<char> temp;

                if (readFront) {
                    for (auto it = dq.begin(); it != dq.end(); ++it)
                        temp.push_back(*it);
                    
                    // append temp at end
                    for (char ch : temp)
                        dq.push_back(ch);
                } else {
                    for (auto it = dq.rbegin(); it != dq.rend(); ++it)
                        temp.push_back(*it);
                    
                    // add temp at front
                    for (auto it = temp.begin(); it != temp.end(); ++it)
                        dq.push_front(*it);
                }
            } 
            else if (c == '*') {
                if (!dq.empty()) {
                    readFront ? dq.pop_back() : dq.pop_front();
                }
            } 
            else {
                readFront ? dq.push_back(c) : dq.push_front(c);
            }
        }

        string res;
        if (readFront) {
            for (char c : dq) res += c;
        } else {
            for (auto it = dq.rbegin(); it != dq.rend(); ++it)
                res += *it;
        }

        return res;
    }
};