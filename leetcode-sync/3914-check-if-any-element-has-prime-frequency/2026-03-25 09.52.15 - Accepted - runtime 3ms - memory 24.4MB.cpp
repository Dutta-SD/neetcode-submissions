class Solution {
private:
    bool isPrime(int x) {
        if (x == 1) return false;
        if (x == 2 || x == 3) return true;
        int a = 2;
        while (a*a <= x) {
            if (x % a == 0) return false;
            a++;
        }
        return true;
    }
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (auto i : nums) {
            if (counter.find(i) != counter.end()){
                counter[i]++;
            } else {
                counter[i] = 1;
            }
        }

        for (auto const& pair : counter) {
            if (isPrime(pair.second)) return true;
        }
        

        return false;
    }
};