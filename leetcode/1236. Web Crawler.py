# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
# class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """
import collections
from typing import List


class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        index = 7
        while index < len(startUrl) and startUrl[index] != '/':
            index += 1
        host = startUrl[:index]
        output = set()
        frontier = collections.deque([startUrl])
        while len(frontier):
            source = frontier.popleft()
            next_urls = htmlParser.getUrls(source)
            for url in next_urls:
                if url.startswith(host) and (url not in output and url + '/' not in output):
                    frontier.append(url)
            output.add(source)
        return list(output)
