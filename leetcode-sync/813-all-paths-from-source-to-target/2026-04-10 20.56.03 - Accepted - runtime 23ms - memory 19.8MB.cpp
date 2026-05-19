class Solution {
private:
    vector<vector<int>> allPaths;
    vector<bool> visited;

    void dfs(const vector<vector<int>>& graph, const int destination,
             vector<int> pathTillNow, int currNode) {
        visited[currNode] = true;

        if (currNode == destination) {
            allPaths.push_back(pathTillNow);
            visited[destination] = false;
            return;
        }

        for (auto neighbor : graph[currNode]) {
            pathTillNow.push_back(neighbor);
            dfs(graph, destination, pathTillNow, neighbor);
            pathTillNow.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        visited.assign(graph.size(), false);
        dfs(graph, graph.size() - 1, {0}, 0);
        return allPaths;
    }
};