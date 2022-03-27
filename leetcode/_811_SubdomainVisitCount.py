class Solution:
    def subdomainVisits(self, cpdomains):
        count_map = {}
        for cd in cpdomains:
            count, domain = cd.split(' ')
            count = int(count)
            count_map[domain] = count_map.get(domain, 0) + count
            for i in range(len(domain)):
                if domain[i] == '.':
                    key = domain[i+1:]
                    count_map[key] = count_map.get(key, 0) + count
        return [str(cn) + ' ' + sbd for sbd, cn in count_map.items()]
if __name__ == '__main__':
    print(Solution().subdomainVisits(["9001 discuss.leetcode.com"]))