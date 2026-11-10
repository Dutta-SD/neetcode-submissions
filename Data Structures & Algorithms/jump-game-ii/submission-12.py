class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return 0
        
        steps = 0
        i = 0
        n = len(nums)
        
        while i < n:
            if i + nums[i] >= n - 1:
                steps += 1
                break
            
            # --- SIMPLE LOOP REPLACEMENT START ---
            w_idx = i
            max_reach = -1
            
            # Look at every reachable index from our current position
            for j in range(i + 1, min(i + nums[i] + 1, n)):
                current_reach = j + nums[j]
                
                # Update if this spot reaches further, or ties but is a further index
                if current_reach >= max_reach:
                    max_reach = current_reach
                    w_idx = j
            # --- SIMPLE LOOP REPLACEMENT END ---
            
            if w_idx == i:
                break
                
            i = w_idx 
            steps += 1
            
        return steps
