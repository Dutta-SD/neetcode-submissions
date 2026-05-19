class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int dig_a, dig_b, x;

        auto ra = a.rbegin();
        auto rb = b.rbegin();

        vector<char> resultAsChar;

        while (ra != a.rend() || rb != b.rend()) {
            dig_a = (ra == a.rend()) ? 0 : *(ra) - '0';
            dig_b = (rb == b.rend()) ? 0 : *(rb) - '0';

            x = dig_a + dig_b + carry;
            resultAsChar.push_back(x%2 + '0');
            carry = x / 2;

            if(ra != a.rend()) ra++;
            if(rb != b.rend()) rb++;
        }

        if (carry) resultAsChar.push_back('1');

        reverse(resultAsChar.begin(), resultAsChar.end());
        return string(resultAsChar.begin(), resultAsChar.end());    
    }
};