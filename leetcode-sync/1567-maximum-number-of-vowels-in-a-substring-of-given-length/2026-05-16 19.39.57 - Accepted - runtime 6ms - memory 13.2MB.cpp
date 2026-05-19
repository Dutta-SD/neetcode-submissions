class Solution {
private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

public:
    int maxVowels(string s, int k) {
        int vowelCounter = 0;
        for (int i = 0; i < k; i++) {
            vowelCounter += isVowel(s[i]);
        }

        int maxVowels = vowelCounter;

        for (int i = k; i < s.size(); i++) {
            vowelCounter += isVowel(s[i]) - isVowel(s[i - k]);
            maxVowels = max(maxVowels, vowelCounter);
        }

        return maxVowels;
    }
};