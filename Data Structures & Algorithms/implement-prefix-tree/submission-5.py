class TrieNode:
    children: list[TrieNode]
    hasEnding: bool

    def __init__(self):
        self.children = [None] * 26
        self.hasEnding = False


class PrefixTree:
    def __init__(self):
        self.root = TrieNode()

    def _ch(self, ch):
        return ord(ch) - ord("a")

    def insert(self, word: str) -> None:
        node = self.root

        for c in word:
            node.children[self._ch(c)] = node.children[self._ch(c)] or TrieNode()
            node = node.children[self._ch(c)]
        node.hasEnding = True

    def search(self, word: str) -> bool:
        node = self.root
        for c in word:
            node = node.children[self._ch(c)]
            if not node:
                return False
        return node.hasEnding

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for c in prefix:
            node = node.children[self._ch(c)]
            if not node:
                return False
        return True
