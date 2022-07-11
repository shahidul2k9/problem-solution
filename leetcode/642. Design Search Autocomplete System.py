import collections
from typing import List


class Trie:
    def __init__(self):
        self.children = collections.defaultdict(Trie)
        self.pq = set()


class AutocompleteSystem:

    def __init__(self, sentences: List[str], times: List[int]):
        self.root = Trie()
        self.search_node = self.root
        self.search_text = ''
        self.frequency_map = collections.defaultdict(int)
        for sc, fc in zip(sentences, times):
            self.add_sentence(sc, fc)

    def push_node(self, trie, word, fc):
        # heappush(trie.pq, HeapItem(word, fc))
        # if len(trie.pq) > 3:
        #     heappop(trie.pq)
        trie.pq.add(word)

    def add_sentence(self, sentence, frequency):
        self.frequency_map[sentence] += frequency
        cur = self.root
        self.push_node(cur, sentence, frequency)
        for ch in sentence:
            cur = cur.children[ch]
            self.push_node(cur, sentence, frequency)

    def input(self, c: str) -> List[str]:
        if c == '#':
            self.search_node = self.root
            self.add_sentence(self.search_text, 1)
            self.search_text = ''
            return []
        else:
            self.search_text += c
            if self.search_node and c in self.search_node.children:
                self.search_node = self.search_node.children[c]

                top_list = [sc for sc in self.search_node.pq]
                top_list.sort(key=lambda x: (-self.frequency_map[x], x))
                # print(top_list)
                if len(top_list) > 3:
                    del top_list[3:]
                return top_list
            else:
                self.search_node = None

# Your AutocompleteSystem object will be instantiated and called as such:
# obj = AutocompleteSystem(sentences, times)
# param_1 = obj.input(c)