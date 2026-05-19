class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // 1. Build a more memory-efficient adjacency list
        vector<vector<int>> children(n);
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                children[manager[i]].push_back(i);
            }
        }

        // 2. Use BFS to calculate the time reached for each employee
        int maxTime = 0;
        queue<pair<int, int>> q; // {current_node, time_received_info}
        q.push({headID, 0});

        while (!q.empty()) {
            auto [u, currTime] = q.front();
            q.pop();

            maxTime = max(maxTime, currTime);

            for (int v : children[u]) {
                q.push({v, currTime + informTime[u]});
            }
        }

        return maxTime;
    }
};
