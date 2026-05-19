class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxArray (prices.size());
        maxArray[prices.size() - 1] = prices[prices.size() - 1];

        for (int i = prices.size() - 2; i >= 0; i--) {
            maxArray[i] = max(maxArray[i+1], prices[i]);
        }

        int mNum = INT_MIN;

        for (int i = 0; i < prices.size(); i++) {
            mNum = max(mNum, maxArray[i] - prices[i]);
        }

        return mNum;
    }
};