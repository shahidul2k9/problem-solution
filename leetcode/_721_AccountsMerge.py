import collections
from typing import List


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        g = collections.defaultdict(set)
        for email_list in accounts:
            u = email_list[1]
            for vi in range(2, len(email_list)):
                v = email_list[vi]
                g[u].add(v)
                g[v].add(u)
        color = collections.defaultdict(bool)

        def dfs(u, path_seq):
            path_seq.append(u)
            color[u] = True
            for v in g[u]:
                if v not in color:
                    dfs(v, path_seq)

        merged_account = []
        for email_list in accounts:
            name = email_list[0]
            u = email_list[1]
            if u not in color:
                path = []
                dfs(u, path)
                path.sort()
                path.insert(0, name)
                merged_account.append(path)
        return merged_account
