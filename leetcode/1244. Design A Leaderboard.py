import collections


class Leaderboard:

    def __init__(self):
        self.id_map = {}
        self.score_map = collections.defaultdict(int)

    def addScore(self, playerId: int, score: int) -> None:
        if score > 0:
            id_map = self.id_map
            score_map = self.score_map
            old_score = 0
            if playerId in id_map:
                old_score = id_map[playerId]
                score_map[old_score] -= 1
            score_map[score + old_score] += 1
            id_map[playerId] = score + old_score

    def top(self, K: int) -> int:
        print(K, self.score_map)
        score_map = self.score_map
        total_score = 0
        for score in sorted(score_map.keys(), reverse=True):
            n = min(score_map[score], K)
            total_score += n * score
            K -= n
            if K == 0:
                return total_score
        return total_score

    def reset(self, playerId: int) -> None:
        if playerId in self.id_map:
            score = self.id_map[playerId]
            del self.id_map[playerId]
            self.score_map[score] -= 1

# Your Leaderboard object will be instantiated and called as such:
# obj = Leaderboard()
# obj.addScore(playerId,score)
# param_2 = obj.top(K)
# obj.reset(playerId)