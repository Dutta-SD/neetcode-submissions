#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> evens;
        vector<int> odds;
        vector<int> final_arr;

        for (auto it : nums) {
            if (it % 2)
                odds.push_back(it);
            else
                evens.push_back(it);
        }

        // sort(odds.begin(), odds.end());
        // sort(evens.begin(), evens.end());

        for (int i = 0; i < nums.size(); i++) {
            final_arr.push_back(i % 2 ? odds[i / 2] : evens[i / 2]);
        }

        return final_arr;
    }
};