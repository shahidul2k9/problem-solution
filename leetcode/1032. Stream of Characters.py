from typing import List


class StreamChecker:

    def __init__(self, words: List[str]):
        self.trie = {}
        self.input = []
        for w in words:
            node = self.trie
            for ch in reversed(w):
                if ch not in node:
                    node[ch] = {}
                node = node[ch]
            node['$'] = ''

    def query(self, letter: str) -> bool:
        self.input.append(letter)
        node = self.trie
        for ch in reversed(self.input):
            if ch not in node:
                return False
            else:
                node = node[ch]
            if '$' in node:
                return True
        return False

# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)