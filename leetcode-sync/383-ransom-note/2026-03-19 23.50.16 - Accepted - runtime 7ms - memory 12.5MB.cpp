class Solution {
private:
    unordered_map<char, int> getCounter(string magazine) {
        unordered_map<char, int> counter;
        for (char c: magazine) {
            if (counter.find(c) != counter.end()) counter[c]++;
            else counter[c] = 1;
        }
        return counter;
    }
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charFreqs = getCounter(magazine);
        for (char c : ransomNote) {
            if(charFreqs.find(c) != charFreqs.end() && charFreqs[c]){
                charFreqs[c]--;
            } else {
                return false;
            }
        }
        return true;
    }
};