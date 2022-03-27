import collections
from typing import List


class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        g = collections.defaultdict(list)
        d = collections.defaultdict(int)
        label = {ul: u for u, ul in enumerate(recipes)}
        n = len(label)

        for s in supplies:
            if s not in label:
                label[s] = n
                d[n] = 0
                n += 1

        for u, v_list in enumerate(ingredients):
            for vl in v_list:
                if vl in label:
                    v = label[vl]
                else:
                    v = n
                    n += 1
                    d[v] = 1
                g[v].append(u)
                d[u] += 1

        q = collections.deque()
        for k, dg in d.items():
            if dg == 0:
                q.append(k)
        while q:
            u = q.popleft()
            for v in g[u]:
                d[v] -= 1
                if d[v] == 0:
                    q.append(v)

        recipes_possible = []
        for u in range(len(recipes)):
            if d[u] == 0:
                recipes_possible.append(recipes[u])
        return recipes_possible


print(Solution().findAllRecipes(
    ["bread"],
    [["yeast", "flour"]],
    ["yeast", "flour", "corn"]
))
