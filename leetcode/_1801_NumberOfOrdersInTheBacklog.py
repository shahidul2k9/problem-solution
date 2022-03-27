import heapq


class Solution(object):
    def getNumberOfBacklogOrders(self, orders):
        buy_max_q = []
        sell_min_q = []
        for p, q, t in orders:
            if t == 0:
                while q and sell_min_q and sell_min_q[0][0] <= p:
                    pi, qi = heapq.heappop(sell_min_q)
                    if qi <= q:
                        q = q - qi
                    else:
                        heapq.heappush(sell_min_q, (pi, qi - q))
                        q = 0
                if q > 0:
                    heapq.heappush(buy_max_q, (-p, q))

            else:
                while q and buy_max_q and -buy_max_q[0][0] >= p:
                    npi, qi = heapq.heappop(buy_max_q)
                    if qi <= q:
                        q = q - qi
                    else:
                        heapq.heappush(buy_max_q, (npi, qi - q))
                        q = 0
                if q > 0:
                    heapq.heappush(sell_min_q, (p, q))

        rm = 0
        for _, q in sell_min_q:
            rm = (rm + q) % 1000000007
        for _, q in buy_max_q:
            rm = (rm + q) % 1000000007
        return rm
