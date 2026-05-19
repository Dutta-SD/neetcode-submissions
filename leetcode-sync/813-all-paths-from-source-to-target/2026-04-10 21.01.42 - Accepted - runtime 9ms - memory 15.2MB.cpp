class Solution {
private:
    vector<vector<int>> allPaths;

    void dfs(const vector<vector<int>>& graph, int dest, vector<int>& path,
             int curr) {
        if (curr == dest) {
            allPaths.push_back(path);
            return;
        }
        for (int neighbor : graph[curr]) {
            path.push_back(neighbor);
            dfs(graph, dest, path, neighbor);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path = {0};
        dfs(graph, graph.size() - 1, path, 0);
        return allPaths;
    }
};