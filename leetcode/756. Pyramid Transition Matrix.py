import collections
from typing import List


class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        triangle_pattern_map = collections.defaultdict(list)
        for pattern in allowed:
            triangle_pattern_map[pattern[:2]].append(pattern[2:])
        dp = {}

        def bracktrack(base, from_index, next_base_seq) -> bool:
            # print(base, from_index, next_base_seq)
            if len(base) == 1:
                return True
            if base in dp:
                return dp[base]
            for i in range(from_index, len(base) - 1):
                key = base[from_index:from_index + 2]
                if len(triangle_pattern_map[key]) == 0:
                    dp[base] = False
                    return False
                else:
                    for triangle_top in triangle_pattern_map[key]:
                        next_base_seq.append(triangle_top)
                        if i == len(base) - 2:
                            if bracktrack(''.join(next_base_seq), 0, []):
                                dp[base] = True
                                return True
                        else:
                            if bracktrack(base, from_index + 1, next_base_seq):
                                dp[base] = True
                                return True
                        next_base_seq.pop()
                    dp[base] = False
                    return False
            dp[base] = False
            return False

        return bracktrack(bottom, 0, [])
