#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
    int count = 0;

    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj) {
        for (int i = 0; i < adj[node].size(); i++) {
            if (adj[node][i].first != parent) {
                count += adj[node][i].second;
                dfs(adj[node][i].first, node, adj);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back({connections[i][1], 1});
            adj[connections[i][1]].push_back({connections[i][0], 0});
        }
        dfs(0, -1, adj);
        return count;
    }
};