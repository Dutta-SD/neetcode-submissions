class Solution {
private:
    unordered_map<int, vector<string>> numbers;

public:
    Solution() {
        numbers[1] = {"0", "1"};
        for (int i = 2; i <= 18; i++) {
            vector<string> v;
            for (auto st : numbers[i - 1]) {
                if (st.back() == '0') {
                    v.emplace_back(st + '1');
                } else {
                    v.emplace_back(st + '0');
                    v.emplace_back(st + '1');
                }
            }
            numbers[i] = v;
        }
    }
    vector<string> validStrings(int n) { return numbers[n]; }
};