from typing import List
from functools import cache

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        word_set = set(wordDict)
        # Optimization: only check lengths that actually exist in wordDict
        word_lengths = {len(w) for w in wordDict}
        n = len(s)

        @cache
        def can_construct(start: int) -> bool:
            if start == n:
                return True
            
            for length in word_lengths:
                end = start + length
                if end <= n and s[start:end] in word_set:
                    if can_construct(end):
                        return True
                        
            return False

        return can_construct(0)