class Solution:
    def frequencySort(self, s: str) -> str:
        fc = {}
        for ch in s:
            fc[ch] = fc.get(ch, 0) + 1
        cat_list = []
        for ch, n in sorted([(k, v) for k, v in fc.items()], key=lambda x: x[1], reverse=True):
            cat_list.append(''.ljust(n, ch))
        return ''.join(cat_list)
