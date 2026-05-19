class Solution {

public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        char x, y;

        while (i < j) {
            while (i < s.size() && !isalnum(s[i]))
                i++;
            while (j >= 0 && !isalnum(s[j]))
                j--;

            if (i > j)
                return true;

            x = tolower(s[i]);
            y = tolower(s[j]);

            if (x != y)
                return false;
            i++;
            j--;
        }

        return true;
    }
};