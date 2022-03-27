import heapq


class Solution:
    def reorganizeString(self, s: str) -> str:
        fc = {}
        for ch in s:
            fc[ch] = fc.get(ch, 0) + 1
        st = []
        max_q = []
        for k, v in fc.items():
            heapq.heappush(max_q, (-v, k))

        pch = '$'
        while len(max_q) > 0:
            nc, k = heapq.heappop(max_q)

            if k != pch:
                st.append(k)
                pch = k
                if nc * -1 > 1:
                    heapq.heappush(max_q, (nc + 1, k))
            elif len(max_q) > 0:
                anc, ak = heapq.heappop(max_q)
                st.append(ak)
                pch = ak
                if anc * -1 > 1:
                    heapq.heappush(max_q, (anc + 1, ak))
                heapq.heappush(max_q, (nc, k))
            else:
                return ""
        return ''.join(st)
