
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
        if head == nil { return nil }
        if head?.next == nil { return head }
        
        var node: ListNode? = head
        var prev: ListNode?
        var next: ListNode?
        while node != nil {
            next = node?.next
            node?.next = prev
            prev = node
            node = next
        }
        return prev
    }
    
    func reverseKGroup(_ head: ListNode?, _ k: Int) -> ListNode? {
        if head == nil { return nil }
        if head?.next == nil || k <= 1 { return head }
        
        let dummy = ListNode(-1)
        dummy.next = head;
        
        var prev: ListNode? = dummy, end: ListNode? = dummy
        while end != nil {
            for _ in 0 ..< k {
                if end == nil { break; }
                end = end!.next
            }
            if end == nil { break; }
            let start = prev?.next
            let next = end?.next
            end?.next = nil
            prev?.next = reverseList(start)
            start?.next = next
            prev = start
            end = prev
        }
        return dummy.next
    }
    
}

let s = Solution()

var l0 = ListNode(10)
var l1 = ListNode(8)
l1.next = l0
var l2 = ListNode(4)
l2.next = l1
var l3 = ListNode(2)
l3.next = l2
var l4 = ListNode(0)
l4.next = l3

l4.dump()
print("-----")
var r = s.reverseKGroup(l4, 3)
r!.dump()
