class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Use a set to automatically handle unique values
        std::set<int> distinct_nums(nums.begin(), nums.end());
        
        // Put unique values into the priority queue
        std::priority_queue<int> pq;
        for (int x : distinct_nums) {
            pq.push(x);
        }

        int max_1 = pq.top(); // Get the value
        if (pq.size() < 3) return max_1;

        pq.pop(); // Remove 1st max
        pq.pop(); // Remove 2nd max
        
        return pq.top(); // Return 3rd max
    }
};
