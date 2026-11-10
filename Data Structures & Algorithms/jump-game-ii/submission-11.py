class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return 0
        
        steps = 0
        i = 0
        n = len(nums)
        
        while i < n:
            # If we can reach the end from here, take the final jump and finish
            if i + nums[i] >= n - 1:
                steps += 1
                break
            
            # Find the best next landing spot
            w_idx, _ = max(
                enumerate(nums[i + 1 : i + nums[i] + 1], start=i + 1),
                key=lambda v: (v[1] + v[0], v[0]),
                default=(i, 0),
            )
            
            # BUG FIX 1: If we can't move forward at all (hit a 0), break to avoid infinite loop
            if w_idx == i:
                break
                
            # BUG FIX 2: w_idx is already absolute. Don't add (i + 1) to it again!
            i = w_idx 
            steps += 1
            
        return steps
