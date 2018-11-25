# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

def getSumCar(x, y, car):
        add = x + y + car
        car = add // 10
        add %= 10
        return (add, car)
    
class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        car = 0
        res = None
        
        while l1 is not None and l2 is not None:
            add, car = getSumCar(l1.val, l2.val, car)
            tmp = ListNode(add)
            
            if res is None:
                res = tmp
                cur = res
            else:
                cur.next = tmp
                cur = cur.next
            
            l1 = l1.next
            l2 = l2.next
                
        while l1 is not None:
            add, car = getSumCar(l1.val, 0, car)
            tmp = ListNode(add)
            cur.next = tmp
            cur = cur.next
            
            l1 = l1.next
            
        while l2 is not None:
            add, car = getSumCar(0, l2.val, car)
            tmp = ListNode(add)
            cur.next = tmp
            cur = cur.next
            
            l2 = l2.next
            
        if car > 0:
            tmp = ListNode(car)
            cur.next = tmp
            cur = cur.next
        
        return res
        
