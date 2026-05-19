class SnapshotArray {
private:
    // map each index to a list of {snap_id, value}
    vector<vector<pair<int, int>>> history;
    int snap_id = 0;

public:
    SnapshotArray(int length) {
        history.resize(length);
        for (int i = 0; i < length; i++) {
            history[i].push_back({0, 0});
        }
    }

    void set(int index, int val) { history[index].push_back({snap_id, val}); }

    int snap() { return snap_id++; }

    int get(int index, int snap_id) {
        // Binary search for the largest snap_id <= requested snap_id
        auto it = upper_bound(history[index].begin(), history[index].end(),
                              make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};
