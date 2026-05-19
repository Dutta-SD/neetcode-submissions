class Solution {
private:
    vector<bool> visited;

    void bfs(const vector<vector<int>>& rooms, int startNode) {
        queue<int> q;
        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;
            for (auto neighbor : rooms[node]) {
                if (!visited[neighbor])
                    q.push(neighbor);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited = vector<bool>(rooms.size(), false);
        bfs(rooms, 0);
        return all_of(visited.begin(), visited.end(),
                      [](bool val) { return val; });
    }
};