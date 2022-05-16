import collections


class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        def bfs(sc, dc) -> str:
            par = [-1] * 26
            move = ['$'] * 26
            s_i = ord(sc) - ord('a')
            d_i = ord(dc) - ord('a')
            q = collections.deque([s_i])
            move[s_i] = '!'
            while q:
                u = q.popleft()
                if u == d_i:
                    seq = ['!']
                    x = d_i
                    while par[x] != -1:
                        seq.append(move[x])
                        x = par[x]
                    return ''.join(seq)[::-1]
                else:
                    v_list = []
                    for (dr, dx) in [('U', -5), ('D', 5)]:
                        v = u + dx
                        if 0 <= v < 26:
                            v_list.append([dr, v])
                    if u % 5 != 0:
                        v_list.append(['L', u - 1])
                    if u != 25 and (u + 1) % 5 != 0:
                        v_list.append(('R', u + 1))
                    for [dr, v] in v_list:
                        if par[v] == -1 and v != s_i:
                            q.append(v)
                            par[v] = u
                            move[v] = dr
            return 'nai'

        cp = 'a'
        path_seq = []
        for i, tch in enumerate(target):
            p = bfs('a' if i == 0 else target[i - 1], tch)
            # print(p)
            path_seq.append(p)
        return ''.join(path_seq)

