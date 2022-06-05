class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        i = 0
        seq = list(dominoes)
        while i < n:
            if dominoes[i] == '.':
                start = i - 1
                i += 1
                while i < n and dominoes[i] == '.':
                    i += 1
                end = i
                ch = ''
                if start >= 0 and end < n:
                    if dominoes[start] == dominoes[end]:
                        ch = dominoes[start]
                    elif dominoes[start] == 'R' and dominoes[end] == 'L':
                        while end - start > 2:
                            start += 1
                            end -= 1
                            seq[start] = 'R'
                            seq[end] = 'L'
                elif start >= 0 and dominoes[start] == 'R':
                    ch = 'R'
                elif end < n and dominoes[end] == 'L':
                    ch = 'L'
                if ch != '':
                    while start + 1 < end:
                        start += 1
                        seq[start] = ch
            else:
                i += 1
        return ''.join(seq)
