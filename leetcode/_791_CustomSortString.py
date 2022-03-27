class Solution:
    def customSortString(self, order: str, s: str) -> str:
        order_index_map = {c: i for i, c in enumerate(order)}
        for i in range(ord('a'), ord('z') + 1):
            c = chr(i)
            if c not in order_index_map:
                order_index_map[c] = float('inf')
        s_seq = [c for c in s]
        s_seq.sort(key=lambda x: order_index_map[x])
        return ''.join(s_seq)
