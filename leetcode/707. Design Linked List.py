class Node:
    def __init__(self, val: int, prev=None, next=None):
        self.val = val
        self.prev = prev
        self.next = next

    def to_string(self) -> str:
        seq = []
        node = self
        while node != None:
            seq.append(str(node.val))
            node = node.next
        return '->'.join(seq)


class MyLinkedList:
    def __init__(self):
        self.head = Node(-1)
        self.tail = Node(-1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, index: int) -> int:
        # print(self.head.to_string())
        i = 0
        target = self.head
        while i <= index and target != self.tail:
            target = target.next
            i += 1
        if target != self.tail:
            return target.val
        else:
            return -1

    def addAtHead(self, val: int) -> None:
        node = Node(val, self.head, self.head.next)
        self.head.next.prev, self.head.next = node, node
        # print(self.head.to_string())

    def addAtTail(self, val: int) -> None:
        node = Node(val, self.tail.prev, self.tail)
        self.tail.prev.next, self.tail.prev = node, node
        # print(self.head.to_string())

    def addAtIndex(self, index: int, val: int) -> None:
        i = 0
        target = self.head
        while i <= index and target != self.tail:
            target = target.next
            i += 1
        if i == index + 1:
            if target == self.tail:
                self.addAtTail(val)
            else:
                node = Node(val, target.prev, target)
                target.prev.next, target.prev = node, node
        # print(self.head.to_string())

    def deleteAtIndex(self, index: int) -> None:
        i = 0
        target = self.head
        while i < index + 1 and target != self.tail:
            target = target.next
            i += 1
        if target != self.tail:
            target.prev.next, target.next.prev = target.next, target.prev
        # print(self.head.to_string())

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)