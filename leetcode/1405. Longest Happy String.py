from heapq import heappush, heappop


class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        hp = []
        if a > 0:
            heappush(hp, [-a, 'a'])
        if b > 0:
            heappush(hp, [-b, 'b'])
        if c > 0:
            heappush(hp, [-c, 'c'])
        seq = []
        prev_n, prev_ch = 0, ''
        while hp:
            n, ch = heappop(hp)
            n = -n
            if prev_n > n:
                taken = 1
            else:
                taken = min(2, n)

            seq.append(ch * taken)
            if prev_n > 0:
                heappush(hp, [-prev_n, prev_ch])
            if n - taken > 0:
                prev_n, prev_ch = n - taken, ch
            else:
                prev_n, prev_ch = 0, ''
        #print(hp, seq, prev_n, prev_ch)
        return ''.join(seq)
