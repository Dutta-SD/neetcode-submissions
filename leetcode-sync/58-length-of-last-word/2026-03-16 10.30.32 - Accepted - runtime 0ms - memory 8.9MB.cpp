class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos = s.size() - 1;
        while(pos > -1 && s[pos] == ' ') pos--;

        int len = 0;
        while(pos - len > -1 && s[pos - len] != ' ') len++;

        return len; 
    }
};