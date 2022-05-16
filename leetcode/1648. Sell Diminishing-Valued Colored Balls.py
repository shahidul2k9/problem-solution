from typing import List
from heapq import heappush, heappop, heapify
class Solution:
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        inventory.sort()
        def is_possible_left_max_height(h)-> bool:
            coll = 0
            for c in inventory:
                if c > h:
                    coll += c - h
                if coll >= orders:
                    return True
            return coll >= orders
        low = 0
        high = inventory[-1]
        last_known = 0
        rem_ord = orders
        value = 0
        while low <= high:
            mid = (low + high)//2
            if is_possible_left_max_height(mid):
                last_known = mid
                low = mid + 1
            else:
                high = mid -1
        last_known += 1
        p = 0
        while p < 2:
            i = len(inventory) -1
            if p == 1:
                last_known -= 1
            while i >= 0 and rem_ord > 0 and inventory[i] > last_known:
                n = inventory[i]
                taken_n = min(rem_ord, n - last_known)
                rem_n = n - taken_n
                v = (((n * (n + 1)) - (rem_n * (rem_n + 1))) //2) % (10**9 + 7)
                #print(v)
                value = (value + v) % (10**9 + 7)
                rem_ord -= taken_n
                inventory[i] = rem_n
                i -= 1
                #print(p,last_known, inventory)

            p += 1
        #print('remaining..' + str(rem_ord))
        return value