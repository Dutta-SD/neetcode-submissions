class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int maxT = events[0][1];
        int btnIdx = events[0][0];
        for (int i = 1; i < events.size(); i++) {
            int v = events[i][1] - events[i - 1][1];
            if (v > maxT || (v == maxT && events[i][0] < btnIdx)) {
                maxT = v;
                btnIdx = events[i][0];
            }
        }
        return btnIdx;
    }
};