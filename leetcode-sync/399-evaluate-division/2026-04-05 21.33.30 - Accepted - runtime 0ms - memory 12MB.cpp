class Solution {
private:
    unordered_map<string, vector<pair<double, string>>> G;
    unordered_map<string, bool> visited;

    void addToGraph(string& a, string& b, double& v) {
        G[a].push_back({v, b});
        G[b].push_back({1.0 / v, a});
    }

    void makeGraph(vector<vector<string>>& equations, vector<double>& values) {
        for (int i = 0; i < equations.size(); i++) {
            addToGraph(equations[i][0], equations[i][1], values[i]);
            visited[equations[i][0]] = false;
            visited[equations[i][1]] = false;
        }
    }

    double answerOneQuery(string& c, string& d) {
        if (c == d)
            return 1.0;
        visited[c] = true;

        for (auto& it : G[c]) {
            string neighbor = it.second;
            double weight = it.first;

            if (!visited[neighbor]) {
                double res = answerOneQuery(neighbor, d);
                if (res != -1.0)
                    return weight * res;
            }
        }
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        makeGraph(equations, values);
        vector<double> results;
        for (auto q : queries) {
            string source = q[0];
            string destination = q[1];
            double answer;

            if (G.find(source) == G.end() || G.find(destination) == G.end())
                answer = -1.0;
            else {
                visited.clear();
                answer = answerOneQuery(source, destination);
            }
            results.push_back(answer);
        }

        return results;
    }
};