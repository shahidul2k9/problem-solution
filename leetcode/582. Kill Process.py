import collections
from typing import List


class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        g = collections.defaultdict(set)
        for u, v in zip(ppid, pid):
            g[u].add(v)

        killed_process = []

        def kill_process(u, killed):
            killed.append(u)
            for v in g[u]:
                kill_process(v, killed)

        kill_process(kill, killed_process)
        return killed_process
