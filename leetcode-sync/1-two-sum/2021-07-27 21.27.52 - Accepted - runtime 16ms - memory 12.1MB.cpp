class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {        
        vector <int> idx;       
        unordered_map <int, int> n;
        
        for(int i = 0; i < nums.size(); ++i) n[nums[i]] = i;
        
        for(int i = 0; i < nums.size(); ++i){
            int val = target - nums[i];
            
            if (n.find(val) != n.end() && n[val] != i) {
                idx.push_back(i);
                idx.push_back(n[val]);
                break;
            }            
        }
        
        return idx;        
    }
};