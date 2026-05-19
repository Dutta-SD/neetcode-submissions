class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int last_pos[256];
        fill(last_pos, last_pos + 256, -1);
        
        int start = 0, end = 0, maxLen = 0;
        
        while(end < s.size()){
            char curr_char = s[end];
            if(last_pos[curr_char] == -1 || last_pos[curr_char] < start) 
                last_pos[curr_char] = end;
            else {
                start = last_pos[curr_char] + 1;
                last_pos[curr_char] = end;
            }
            maxLen = max(maxLen, end - start + 1);
            end++;
        }
        return maxLen;
    }
};