

import Foundation


 public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
        
    }
    
    func dump() {
        var l: ListNode? = self
        while l != nil {
            print("\(l!.val)")
            l = l!.next
        }
    }
}


class Solution {
    func detectCycle(_ head: ListNode?) -> ListNode? {
        if head == nil { return nil }
        
        var visited = [ListNode]()
        var node = head
        while node != nil {
            if visited.contains(where: { (n) -> Bool in return n === node }) {
                return node
            }
            visited.append(node!)
            node = node!.next
        }
        return nil
    }
}




var l1 = ListNode(8)
 var l2 = ListNode(-9)
 l2.next = l1
 var l3 = ListNode(6)
 l3.next = l2
l1.next = l3

 var l4 = ListNode(0)
 l4.next = l3
//l4.dump()
print("----")


let s = Solution()
let ans = s.detectCycle(l4)
print(ans?.val as Any)
