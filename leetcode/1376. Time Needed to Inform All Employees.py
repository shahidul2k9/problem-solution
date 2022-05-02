from typing import List


class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        receive_time = [None] * n
        receive_time[headID] = 0

        def receive_information(u):
            if receive_time[u] == None:
                v = manager[u]
                receive_time[u] = receive_information(v) + informTime[v]
            return receive_time[u]

        max_time = 0
        for u in range(n):
            max_time = max(max_time, receive_information(u))
        return max_time

