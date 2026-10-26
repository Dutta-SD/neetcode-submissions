class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        suffixes = {"" : True}
        word_set = set(wordDict)

        def act(t: str):
            if t in suffixes:
                return suffixes[t]

            for i in range(1, len(t) + 1):
                prefix = t[0:i]
                suffix = t[i:]

                if prefix in word_set:
                    value = act(suffix)
                    suffixes[suffix] = value
                    if value:
                        return True

            return False
        return act(s)
