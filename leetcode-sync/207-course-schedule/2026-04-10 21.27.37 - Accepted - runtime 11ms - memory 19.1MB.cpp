class Solution {
private:
    vector<vector<int>> adj;
    vector<int> inDegree;

    void buildGraph(int n, vector<vector<int>>& edges) {
        adj.assign(n, {});
        inDegree.assign(n, 0);
        for (auto& e : edges) {
            adj[e[1]].push_back(e[0]);
            inDegree[e[0]]++;
        }
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        buildGraph(numCourses, prerequisites);
        queue<int> q;

        for (int i = 0; i < adj.size(); i++) {
            if (!inDegree[i])
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (!inDegree[neighbor])
                    q.push(neighbor);
            }
        }

        for (auto& i : inDegree) {
            if (i)
                return false;
        }
        return true;
    }
};