
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
    
    func swapPairs(_ head: ListNode?) -> ListNode? {
        if head == nil || head?.next == nil {
            return head
        }
        
        var prev = ListNode(-1)
        var one = head, two = head!.next
        let list = two
       
        while two != nil {
            prev.next = two
            one!.next = two!.next
            two!.next = one
            prev = one!
            
            one = one!.next
            two = one?.next
        }
        return list
    }
    
    
    //递归
    func swapPairs2(_ head: ListNode?) -> ListNode? {
        if head == nil || head?.next == nil {
            return head
        }
        
        let one = head, two = head!.next
        
        one!.next = swapPairs2(two!.next)
        two!.next = one
        return two
    }
    
}

let s = Solution()

var l1 = ListNode(8)
var l2 = ListNode(4)
l2.next = l1
var l3 = ListNode(2)
l3.next = l2
var l4 = ListNode(0)
l4.next = l3

var l = s.swapPairs2(l4)
l?.dump()
