class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        fc = {}
        for ch in s:
            fc[ch] = fc.get(ch, 0) + 1
        fc_list = list(fc.items())
        fc_list.sort(key=lambda x: x[0])

        seq = []
        while fc_list:
            ch, n = fc_list.pop()
            if n > repeatLimit:
                seq.append(''.ljust(repeatLimit, ch))
                if fc_list:
                    next_ch, next_n = fc_list.pop()
                    seq.append(next_ch)
                    if next_n > 1:
                        fc_list.append((next_ch, next_n - 1))
                else:
                    break
                fc_list.append((ch, n - repeatLimit))
            else:
                seq.append(''.ljust(n, ch))
        return ''.join(seq)
