class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0); // 0: unvisited, 1: visiting, 2: safe
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (dfs(i, state, graph)) {
                result.push_back(i);
            }
        }
        return result;
    }

private:
    bool dfs(int node, vector<int>& state, const vector<vector<int>>& graph) {
        if (state[node] > 0) {
            return state[node] == 2; // Return true if already marked safe
        }

        state[node] = 1; // Mark as "visiting"
        for (int neighbor : graph[node]) {
            // If neighbor is currently being visited, we found a cycle
            if (state[neighbor] == 1 || !dfs(neighbor, state, graph)) {
                return false; 
            }
        }

        state[node] = 2; // Mark as "safe"
        return true;
    }
};
