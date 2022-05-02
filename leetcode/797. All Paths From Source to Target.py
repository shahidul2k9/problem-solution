import collections
from typing import List


class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        rg = collections.defaultdict(list)
        for u, v_list in enumerate(graph):
            for v in v_list:
                rg[v].append(u)

        def find_path(v) -> List[List[int]]:
            if v == 0:
                return [[0]]
            else:
                all_paths = []
                for u in rg[v]:
                    path_list = find_path(u)
                    for path in path_list:
                        path.append(v)
                        all_paths.append(path)
                return all_paths

        return find_path(len(graph) - 1)


