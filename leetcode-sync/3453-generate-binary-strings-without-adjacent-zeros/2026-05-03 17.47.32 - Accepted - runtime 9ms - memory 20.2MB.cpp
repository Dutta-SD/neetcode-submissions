class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        // Pre-reserve memory to avoid reallocations
        // The count follows Fibonacci: F(n+2). 10000 is safe for n=18.
        result.reserve(7000); 
        
        string current = "";
        backtrack(n, current, result);
        return result;
    }

private:
    void backtrack(int n, string& current, vector<string>& result) {
        if (current.length() == n) {
            result.push_back(current);
            return;
        }

        // Option 1: Always allowed to add '1'
        current.push_back('1');
        backtrack(n, current, result);
        current.pop_back();

        // Option 2: Add '0' only if the last char wasn't '0'
        if (current.empty() || current.back() == '1') {
            current.push_back('0');
            backtrack(n, current, result);
            current.pop_back();
        }
    }
};