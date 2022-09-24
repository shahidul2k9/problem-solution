from typing import List


class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ips = []
        n = len(s)
        def bracktrack(ip_octets : List[str], index : int, prev_digit : int, octet : str):
            if index == n:
                if index == n and len(ip_octets) == 3 and prev_digit != -1:
                    ip_octets.append(octet)
                    ips.append('.'.join(ip_octets))
                    ip_octets.pop()
            else:
                d = ord(s[index]) - ord('0')
                if prev_digit == -1:
                    bracktrack(ip_octets, index + 1, d, chr(d + 48))
                else:
                    ip_octets.append(octet)
                    bracktrack(ip_octets, index, -1, '')
                    ip_octets.pop()
                    if not (prev_digit == 0 and octet == '0') and int(octet + chr(d + 48)) <= 255:
                        bracktrack(ip_octets, index + 1, d, octet + chr(d + 48))
        bracktrack([], 0, -1, '')
        return ips