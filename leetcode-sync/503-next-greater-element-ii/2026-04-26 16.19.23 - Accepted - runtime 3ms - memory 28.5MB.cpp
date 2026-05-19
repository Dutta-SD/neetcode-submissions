class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> nge (n);

        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;
            while (!st.empty() && st.top() <= nums[idx])
                st.pop();
            nge[idx] = st.empty() ? -1 : st.top();
            st.push(nums[idx]);
        }

        return nge;
    }
};