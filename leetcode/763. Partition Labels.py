class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        occ = {ch : i for i, ch in enumerate(s)}
        parts = []
        i = left = 0
        while i < len(s):
            left = i
            right = occ[s[i]]
            while i <= right:
                right = max(right, occ[s[i]])
                i += 1
            parts.append(right - left + 1)
        return parts
