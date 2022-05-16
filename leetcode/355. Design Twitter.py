import collections
from typing import List
from heapq import heappop, heappush


class Twitter:

    def __init__(self):
        self.followee = collections.defaultdict(set)
        self.tweets = collections.defaultdict(list)
        self.tweet_counter = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweets[userId].append([self.tweet_counter, tweetId])
        self.tweet_counter += 1

    def getNewsFeed(self, userId: int) -> List[int]:
        pq = []
        for followeeId in list(self.followee[userId]) + [userId]:
            for idx, tweetId in self.tweets[followeeId]:
                heappush(pq, [idx, tweetId])
                if len(pq) > 10:
                    heappop(pq)
        ordered_tweets = []
        while pq:
            ordered_tweets.append(heappop(pq)[1])
        return ordered_tweets[::-1]

    def follow(self, followerId: int, followeeId: int) -> None:
        self.followee[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.followee[followerId].discard(followeeId)

# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)