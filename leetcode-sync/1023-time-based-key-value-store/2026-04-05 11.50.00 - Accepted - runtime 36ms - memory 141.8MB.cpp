class TimeMap {
private:
    // Store pairs of {timestamp, value} in a vector for each key
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> store;

public:
    TimeMap() {
        // Reserve space for the hash map to reduce rehashes
        store.reserve(10000); 
    }

    void set(std::string key, std::string value, int timestamp) {
        // Since timestamps are strictly increasing, push_back is O(1)
        store[key].emplace_back(timestamp, value);
    }

    std::string get(std::string key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) return "";

        const auto& values = it->second;
        
        // Find the first element with timestamp > target
        auto res_it = std::upper_bound(values.begin(), values.end(), timestamp, 
            [](int t, const std::pair<int, std::string>& pair) {
                return t < pair.first;
            });

        // If upper_bound returns the beginning, no valid timestamp exists (all are > target)
        if (res_it == values.begin()) return "";

        // The answer is the element immediately before the upper_bound result
        return std::prev(res_it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */