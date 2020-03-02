
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
    func reverseList(_ head: ListNode?) -> ListNode? {
        if head == nil || head?.next == nil { return head }
        
        var tempHead = head
        var prev: ListNode?
        var next: ListNode?
        while tempHead != nil {
            next = tempHead!.next
            tempHead!.next = prev
            prev = tempHead
            tempHead = next
        }
        return prev
    }
    
}

var l1 = ListNode(8)
var l2 = ListNode(4)
l2.next = l1
var l3 = ListNode(2)
l3.next = l2
var l4 = ListNode(0)
l4.next = l3
l4.dump()
print("------")

let s = Solution()
var l = s.reverseList(l4)
while l != nil {
    print("\(l!.val)")
    l = l!.next
}
