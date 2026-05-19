class Solution {
private:
    string getHash(const string& s) {
        vector<int> v (26, 0);
        for (auto c : s) {
            v[c-'a']++;
        }
        string g;
        for (int i = 0; i < 26; i++) {
            if (v[i]) {
                g += string (v[i], 'a' + i);
            }
        }
        return g;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string h;
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for (auto s : strs){
            h = getHash(s);
            mp[h].push_back(s);
        }

        for (auto v : mp) {
            res.push_back(v.second);
        }

        return res;
    }
};