class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)

        def move_next(start_index, p1, p2, seq_count) -> bool:
            if start_index == n:
                return seq_count >= 3

            for i in range(start_index, min(start_index + 12, n)):
                if num[start_index] == '0' and (i - start_index) > 0:
                    continue
                p3 = int(num[start_index: i + 1])
                if (p1 == -1 or p2 == -1 or p1 + p2 == p3) and move_next(i + 1, p2, p3, seq_count + 1):
                    return True
            return False

        return move_next(0, -1, -1, 0)