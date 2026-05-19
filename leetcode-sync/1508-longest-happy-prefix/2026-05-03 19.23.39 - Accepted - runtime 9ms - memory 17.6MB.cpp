class Solution {
public:
    string longestPrefix(string s) {
        long long MOD = 1e9 + 7;
        long long BASE = 31;
        long long power = 1; 
        
        long long pHash = 0;
        long long sHash = 0;
        int maxLen = 0;
        int n = s.size();

        for (int i = 0; i < n - 1; i++) {
            long long pChar = s[i] - 'a';
            long long sChar = s[n - i - 1] - 'a';

            pHash = (pHash * BASE + pChar) % MOD;
            sHash = (sChar * power + sHash) % MOD;
            power = (power * BASE) % MOD;

            if (pHash == sHash) {
                maxLen = i + 1;
            }
        }

        return s.substr(0, maxLen);
    }
};