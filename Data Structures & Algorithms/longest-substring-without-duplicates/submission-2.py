
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_seen = {}
        left = longest = 0

        for right, char in enumerate(s):
            prev = last_seen.get(char, -1)

            if prev >= left:
                left = prev + 1

            last_seen[char] = right
            longest = max(longest, right - left + 1)

        return longest
