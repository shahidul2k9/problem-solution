from typing import List


class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        execution_time = [0] * n
        call_stack = []
        for log in logs:
            id, et, end_time = log.split(':')
            id, end_time = int(id), int(end_time)
            if et == 'start':
                call_stack.append((id, end_time))
            else:
                _, start_time = call_stack.pop()
                window = end_time - start_time + 1
                execution_time[int(id)] += window
                if call_stack:
                    execution_time[call_stack[-1][0]] -= window
        return execution_time
