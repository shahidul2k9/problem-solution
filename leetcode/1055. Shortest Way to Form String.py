class Solution:
    def shortestWay(self, source: str, target: str) -> int:
        si = ti = ti_prev = 0
        sub_seq_count = 0
        while ti < len(target):
            si = 0
            ti_prev = ti
            while si < len(source) and ti < len(target):
                if source[si] == target[ti]:
                    si += 1
                    ti += 1
                else:
                    si += 1
            if ti_prev == ti:
                return -1
            else:
                sub_seq_count += 1
        return sub_seq_count


