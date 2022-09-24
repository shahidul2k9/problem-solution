from typing import List


class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        rating_orders = []
        candies = [0] * n
        for index, rating in enumerate(ratings):
            rating_orders.append([index, rating])
        rating_orders.sort(key=lambda x: (x[1], x[0]))
        for index, rating in rating_orders:
            target_candies = 1
            if index - 1 >= 0 and ratings[index - 1] < ratings[index]:
                target_candies = max(target_candies, candies[index - 1] + 1)
            if index + 1 < n and ratings[index + 1] < ratings[index]:
                target_candies = max(target_candies, candies[index + 1] + 1)
            candies[index] = target_candies
        return sum(candies)
