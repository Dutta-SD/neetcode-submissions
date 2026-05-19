class Solution {
private:
    struct count_element {
        int count = 0;
        int firstIndex = -1;
    };

public:
    int findShortestSubArray(vector<int>& A) {
        // Map each number to its count and first seen index
        unordered_map<int, count_element> stats;
        int res = 0, degree = 0;

        for (int i = 0; i < A.size(); ++i) {
            int num = A[i];
            
            // 1. If it's the first time seeing the number, record the index
            if (stats[num].firstIndex == -1) {
                stats[num].firstIndex = i;
            }
            
            // 2. Increment count
            stats[num].count++;

            // 3. Compare current number's stats against the global degree
            if (stats[num].count > degree) {
                degree = stats[num].count;
                res = i - stats[num].firstIndex + 1;
            } else if (stats[num].count == degree) {
                res = min(res, i - stats[num].firstIndex + 1);
            }
        }
        return res;
    }
};
