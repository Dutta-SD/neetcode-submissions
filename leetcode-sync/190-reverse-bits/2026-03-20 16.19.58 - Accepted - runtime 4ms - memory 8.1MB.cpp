class Solution {
private:
    bool getBitAt(int n, int pos){
        return n & (1 << pos);
    }

    int setBitAt(int n, int pos, bool value) {
        return value ? n | (1 << pos) : n & ~(1<<pos);
    }

public:
    int reverseBits(int n) {
        bool x, y;
        for(int i = 0; i < 16; i++) {
            x = getBitAt(n, i);
            y = getBitAt(n, 31 - i);
            n = setBitAt(n, i, y);
            n = setBitAt(n, 31 - i, x);
        }
        return n;
    }
};