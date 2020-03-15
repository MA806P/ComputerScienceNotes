
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
    func deleteDuplicates(_ head: ListNode?) -> ListNode? {
        var temp = head
        while temp != nil && temp!.next != nil {
            if temp!.val == temp!.next!.val {
                let node = temp!.next
                temp!.next = node?.next
                node!.next = nil
            } else {
                temp = temp!.next
            }
        }
        return head
    }
}


let s = Solution()

var l0 = ListNode(3)
var l1 = ListNode(3)
l1.next = l0
var l2 = ListNode(2)
l2.next = l1
var l3 = ListNode(2)
l3.next = l2
var l4 = ListNode(1)
l4.next = l3

l4.dump()
print("-----")
var r = s.deleteDuplicates(l4)
r!.dump()
