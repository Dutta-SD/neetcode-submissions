class Solution {
private:
    int32_t ROW_1_MASK = 0x15BC110;
    int32_t ROW_2_MASK = 0x40EE9;
    int32_t ROW_3_MASK = 0x2A03006;

    int32_t setBitAt(int32_t n, int k) {
        n |= (1 << k);
        return n;
    }

public:
    vector<string> findWords(vector<string>& words) {
        vector<string> output;

        for (auto word : words) {
            int32_t w_mask = 0;
            for (auto ch : word) {
                w_mask = setBitAt(w_mask, ch >= 'a' ? ch - 'a' : ch - 'A');
            }
            if ((w_mask & ROW_1_MASK) == w_mask ||
                (w_mask & ROW_2_MASK) == w_mask ||
                (w_mask & ROW_3_MASK) == w_mask) {
                output.push_back(word);
            }
        }

        return output;
    }
};