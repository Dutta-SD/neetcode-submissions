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
        for (int i = 0; i < numCourses; i++)
            if (!inDegree[i])
                q.push(i);

        int processed = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            processed++;
            for (int neighbor : adj[node])
                if (--inDegree[neighbor] == 0)
                    q.push(neighbor);
        }

        return processed == numCourses;
    }
};