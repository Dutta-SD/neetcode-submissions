class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0

        l, r, n = 0, 0, len(s)
        
        uniq_chars = [False] * 128
        uniq_chars[ord(s[l])] = 1
        max_len = 1

        while r < n and l <= r:
            r += 1
            if r < n:
                if uniq_chars[ord(s[r])]:
                    # exists, so shrink
                    while l <= r:
                        if s[l] == s[r]:
                            l += 1
                            break

                        uniq_chars[ord(s[l])] = False
                        l += 1
                else:
                    # new uniq char, keep it
                    uniq_chars[ord(s[r])] = True

                max_len = max(max_len, r - l + 1)

        return max_len
