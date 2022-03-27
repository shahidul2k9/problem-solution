class Solution:
    def rankTeams(self, votes: list[str]) -> str:
        ln = len(votes[0])
        vc = {}
        for v in votes:
            for i, c in enumerate(v):
                vc.setdefault(c, [0] * ln)
                vc[c][i] += 1

        return ''.join(sorted(vc.keys(), key=lambda x: (vc[x], -ord(x)), reverse=True))


print(Solution().rankTeams(["ABC", "ACB", "ABC", "ACB", "ACB"]))
