class Solution {
private:
    int nextNumber(int n) {
        int op = 0;
        int x;
        while(n > 0) {
            x = n % 10;
            op += x*x;
            n /= 10;
        }
        return op;
    }


public:
    bool isHappy(int n) {
        unordered_set<int> visited;

        while(visited.find(n) == visited.end()) {
            visited.insert(n);
            n = nextNumber(n);
            if (n == 1) return true;
        }
        return false;
    }
};