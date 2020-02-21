
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
    func mergeTwoList(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        if l1 == nil { return l2 }
        if l2 == nil { return l1 }
        
        var head = ListNode(-1)
        let returnList = head
        
        var node1 = l1, node2 = l2
        
        while true {
            if node1 == nil {
                head.next = node2
                break
            } else if node2 == nil {
                head.next = node1
                break
            }
            
            if node1!.val < node2!.val {
                head.next = node1
                node1 = node1!.next
            } else {
                head.next = node2
                node2 = node2!.next
            }
            head = head.next ?? ListNode(-1)
        }
        return returnList.next
    }
    
    
    func mergeKLists(_ lists: [ListNode?]) -> ListNode? {
        var len = lists.count;
        if len == 0  { return nil }
        if len == 1 { return lists[0] }
        
        var tempLists = lists
        while len > 1 {
            for i in 0 ..< len/2 {
                tempLists[i] = mergeTwoList(tempLists[i], tempLists[len - 1 - i])
            }
            len = (len + 1)/2
        }
        return tempLists[0];
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


var l11 = ListNode(9)
var l22 = ListNode(6)
l22.next = l11
var l33 = ListNode(3)
l33.next = l22
var l44 = ListNode(1)
l44.next = l33


var r = s.mergeKLists([l4, l44])
r!.dump()


