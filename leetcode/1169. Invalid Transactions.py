import collections
from typing import List


class Transaction:
    def __init__(self, log: str):
        seq = log.split(',')
        self.name = seq[0]
        self.time = int(seq[1])
        self.amount = int(seq[2])
        self.city = seq[3]
        self.log = log


class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        transaction_logs = []
        for log in transactions:
            transaction_logs.append(Transaction(log))
        bucket = collections.defaultdict(dict)
        invalid_logs = []
        for log in transaction_logs:
            if log.name not in bucket[log.time]:
                bucket[log.time][log.name] = set([log.city])
            else:
                bucket[log.time][log.name].add(log.city)

        for log in transaction_logs:
            is_valid = True
            if log.amount > 1000:
                is_valid = False
            else:
                for clock in range(log.time - 60, log.time + 60 + 1):
                    if clock in bucket and log.name in bucket[clock] and (
                            len(bucket[clock][log.name]) > 1 or bucket[clock][log.name] != {log.city}):
                        is_valid = False
                        break

            if not is_valid:
                invalid_logs.append(log.log)

        return invalid_logs

