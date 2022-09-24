class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        max_seq_len = 0
        for target in ['T', 'F']:
            used_k = 0
            left = right = 0
            seq_len = 0
            while right < len(answerKey):
                answer = answerKey[right]
                seq_len += 1
                if answer != target:
                    used_k += 1
                while used_k > k:
                    if answerKey[left] != target:
                        used_k -= 1
                    seq_len -= 1
                    left += 1
                max_seq_len = max(max_seq_len, seq_len)
                right += 1
        return max_seq_len






