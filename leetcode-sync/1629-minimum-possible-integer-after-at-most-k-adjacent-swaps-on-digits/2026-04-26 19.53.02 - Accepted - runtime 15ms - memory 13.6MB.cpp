class Solution {
    vector<int> bit;
    int n;

    void update(int i) {
        for (++i; i <= n; i += i & (-i))
            bit[i]++;
    }

    int query(int i) {
        int s = 0;
        for (++i; i > 0; i -= i & (-i))
            s += bit[i];
        return s;
    }

public:
    string minInteger(string num, int k) {
        n = num.size();
        bit.assign(n + 1, 0);
        queue<int> queues[10];

        for (int i = 0; i < n; i++)
            queues[num[i] - '0'].push(i);

        string res;
        for (int i = 0; i < n; i++) {
            for (int d = 0; d < 10; d++) {
                if (queues[d].empty())
                    continue;
                int idx = queues[d].front();
                int cost = idx - (idx > 0 ? query(idx - 1) : 0);
                if (cost <= k) {
                    k -= cost;
                    queues[d].pop();
                    update(idx);
                    res += ('0' + d);
                    break;
                }
            }
        }
        return res;
    }
};