"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""
import collections
from typing import List


class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        g = collections.defaultdict(set)
        for emp in employees:
            g[emp.id] = g[emp.id].union(emp.subordinates)

        importance = {emp.id: emp.importance for emp in employees}

        def dfs(u):
            aggregated_importance = importance[u]
            for v in g[u]:
                aggregated_importance += dfs(v)
            return aggregated_importance

        return dfs(id)
