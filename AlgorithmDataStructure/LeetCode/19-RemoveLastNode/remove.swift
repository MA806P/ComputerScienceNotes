
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
    func removeNthFromEnd(_ head: ListNode?, _ n: Int) -> ListNode? {
        guard head != nil && n > 0 else {
            return head
        }
        
        var fast = head
        var k = n
        while k > 1 && fast != nil {
            fast = fast?.next
            k -= 1
        }
        
        if fast == nil { return head }
        
        var prev: ListNode? = nil
        var next = head
        while fast?.next != nil {
            fast = fast?.next
            prev = next
            next = next?.next
        }
        
        if prev == nil {
            return head?.next
        } else {
            prev?.next = prev?.next?.next
            return head
        }
    }
}

let s = Solution()


var l1 = ListNode(1)
var l2 = ListNode(2)
l2.next = l1
var l3 = ListNode(3)
l3.next = l2
var l4 = ListNode(4)
l4.next = l3

var r = s.removeNthFromEnd(l4, 4)
r!.dump()
