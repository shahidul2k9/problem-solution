from heapq import heappush, heappop
from sys import stdin

if __name__ == '__main__':
    T = int(stdin.readline())
    for tc in range(1, T + 1, 1):
        N = int(stdin.readline())
        fun = [None]
        child = [None]
        ind = [0] * (N + 1)
        fun.extend(map(int, stdin.readline().split(' ')))
        child.extend(map(int, stdin.readline().split(' ')))
        for u in range(1, N + 1):
            v = child[u]
            ind[v] += 1
        ind_pq = []
        fun_map = dict()
        for u in range(1, N + 1):
            if ind[u] == 0:
                fun_map[u] = [fun[u]]
                heappush(ind_pq, (ind[u], u))

        optimal_fun = 0
        while ind_pq:
            _, u = heappop(ind_pq)
            if child[u] == 0:
                optimal_fun += sum(fun_map.get(u))
            else:
                v = child[u]
                u_pq = fun_map.get(u)
                fun_map.setdefault(v, [])
                v_pq = fun_map.get(v)
                v_pq.extend(u_pq)
                ind[v] -= 1
                if ind[v] == 0:
                    if len(v_pq) > 1:
                        min_candidate = min(v_pq)
                        for i in range(len(v_pq)):
                            if min_candidate == v_pq[i]:
                                v_pq[0],v_pq[i] = v_pq[i],v_pq[0]
                                break
                        while len(v_pq) > 1:
                            optimal_fun += v_pq.pop()

                    if v_pq[0] < fun[v]:
                        heappop(v_pq)
                        heappush(v_pq, fun[v])
                    heappush(ind_pq, (0, v))
        print('Case #' + str(tc) + ': ' + str(optimal_fun))
