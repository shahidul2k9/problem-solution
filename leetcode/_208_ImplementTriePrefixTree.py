class Trie:

    def __init__(self):
        self.root = {}

    def insert(self, word: str) -> None:
        st = self.root
        for i, ch in enumerate(word):
            if ch not in st:
                st[ch] = {}
            st = st[ch]
        st['$'] = True

    def search(self, word: str) -> bool:

        st = self.root
        for i, ch in enumerate(word):
            if ch in st:
                st = st[ch]
            else:
                return False
        return '$' in st


    def startsWith(self, prefix: str) -> bool:
        st = self.root
        for i, ch in enumerate(prefix):
            if ch in st:
                st = st[ch]
            else:
                return False
        return True
