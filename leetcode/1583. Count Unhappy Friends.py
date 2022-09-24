class Solution:
    def unhappyFriends(self, n: int, preferences: List[List[int]], pairs: List[List[int]]) -> int:
        preference_map = [{} for _ in range(n)]
        for i, pref_seq in enumerate(preferences):
            for priority, person in enumerate(pref_seq):
                preference_map[i][person] = priority
        grumpies = set()

        for i in range(len(pairs)):
            for j in range(len(pairs)):
                if i != j:
                    for (x, y) in [pairs[i], pairs[i][::-1]]:
                        for (u, v) in [pairs[j], pairs[j][::-1]]:
                            if preference_map[x][u] < preference_map[x][y] and preference_map[u][x] < preference_map[u][
                                v]:
                                grumpies.add(x)
        return len(grumpies)