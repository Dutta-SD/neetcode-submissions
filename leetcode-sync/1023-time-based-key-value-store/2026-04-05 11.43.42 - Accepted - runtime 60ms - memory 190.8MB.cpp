class TimeMap {
private:
    unordered_map<string, map<int, string, greater<int>>> store;

public:
    TimeMap() { store.reserve(100000); }

    void set(string key, string value, int timestamp) {
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