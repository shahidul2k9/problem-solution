# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """


class NestedInteger:
   def isInteger(self) -> bool:
       """
       @return True if this NestedInteger holds a single integer, rather than a nested list.
       """

   def getInteger(self) -> int:
       """
       @return the single integer that this NestedInteger holds, if it holds a single integer
       Return None if this NestedInteger holds a nested list
       """

   def getList(self) -> [NestedInteger]:
       """
       @return the nested list that this NestedInteger holds, if it holds a nested list
       Return None if this NestedInteger holds a single integer
       """
import sys
from collections import deque
class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.q = deque(nestedList)
        self.val = None

    def next(self) -> int:
        if self.hasNext():
            val = self.val
            self.val = None
            return val
        else:
            return sys.maxsize

    def hasNext(self) -> bool:
        if self.val is None:
            while self.q:
                ni = self.q.popleft()
                if ni.isInteger():
                    self.val = ni.getInteger()
                    break
                else:
                    for x in reversed(ni.getList()):
                        self.q.appendleft(x)
        return self.val is not None