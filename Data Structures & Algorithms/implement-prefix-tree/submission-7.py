class TrieNode:
    children: list[TrieNode]
    hasEnding: bool

    def __init__(self):
        self.children = [None] * 26
        self.hasEnding = False


class PrefixTree:
    def __init__(self):
        self.root = TrieNode()

    @staticmethod
    def _ch(ch):
        return ord(ch) - ord("a")

    def insert(self, word: str) -> None:
        node = self.root

        for c in word:
            idx = self._ch(c)
            node.children[idx] = node.children[idx] or TrieNode()
            node = node.children[idx]
        node.hasEnding = True

    def search(self, word: str) -> bool:
        node = self.root
        for c in word:
            idx = self._ch(c)
            node = node.children[idx]
            if not node:
                return False
        return node.hasEnding

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for c in prefix:
            idx = self._ch(c)
            node = node.children[idx]
            if not node:
                return False
        return True
