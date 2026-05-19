class TimeMap {
private:
    unordered_map<string, map<int, string, greater<int>>> store;

public:
    TimeMap() { store = {}; }

    void set(string key, string value, int timestamp) {
        if (store.find(key) == store.end()) {
            store[key][timestamp] = value;
            return;
        }
        store[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (store.find(key) != store.end()) {
            auto it = store[key].lower_bound(timestamp);
            if (it != store[key].end())
                return it->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */