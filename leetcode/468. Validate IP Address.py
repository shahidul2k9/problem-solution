class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        ip = queryIP
        dot_count = ip.count('.')
        colon_count = ip.count(':')
        if dot_count == 3 and colon_count == 0:
            for p in ip.split('.'):
                if p.isdigit():
                    val = int(p)
                    if len(str(val)) != len(p) or val > 255:
                        return "Neither"
                else:
                    return 'Neither'
            return "IPv4"
        elif dot_count == 0 and colon_count == 7:
            for p in ip.split(':'):
                if len(p) > 4 or len(p) == 0:
                    return 'Neither'
                for d in p:
                    if not (ord('0') <= ord(d) <= ord('9') or ord('a') <= ord(d) <= ord('f') or ord('A') <= ord(
                            d) <= ord('F')):
                        return 'Neither'
            return 'IPv6'
        else:
            return 'Neither'
