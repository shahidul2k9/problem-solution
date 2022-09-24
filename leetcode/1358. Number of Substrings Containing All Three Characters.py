class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        ans = a = b = c = 0
        left = 0
        for i, ch in enumerate(s):
            match ch:
                case 'a':
                    a += 1
                case 'b':
                    b += 1
                case 'c':
                    c += 1
            while a >= 1 and b >= 1 and c >= 1:
                ans = ans + n - i
                match s[left]:
                    case 'a':
                        a -= 1
                    case 'b':
                        b -= 1
                    case 'c':
                        c -= 1
                left += 1
        return ans


