from typing import List


class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        security_devices = [row.count('1') for row in bank]

        lager_count = 0
        for r1 in range(len(security_devices)):
            for r2 in range(r1 + 1, len(security_devices)):
                n1 = security_devices[r1]
                n2 = security_devices[r2]
                if n2 > 0:
                    lager_count += (n1 * n2)
                    break
        return lager_count

