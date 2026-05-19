class Solution {
private:
    vector<vector<int>> G;

    void makeGraph(vector<int>& manager, vector<int>& informTime) {
        G.assign(manager.size(), vector<int>());

        for (int c = 0; c < manager.size(); c++) {
            if (manager[c] >= 0)
                G[manager[c]].push_back(c);
        }
    }

    int maxTime(int node, const vector<int>& informTime) {
        if (!G[node].size()) {
            // leaf
            return 0;
        }

        int maxT = INT_MIN;
        for (auto nb : G[node]) {
            maxT = max(maxT, maxTime(nb, informTime));
        }

        return maxT + informTime[node];
    }

public:
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        makeGraph(manager, informTime);
        return maxTime(headID, informTime);
    }
};