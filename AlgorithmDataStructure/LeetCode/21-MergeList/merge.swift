
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
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var tmpList = ListNode(0)
        let returnList = tmpList
        var node1 = l1, node2 = l2
        while node1 != nil || node2 != nil {
            if node1 != nil && node2 != nil {
                if node1!.val < node2!.val {
                    tmpList.next = node1
                    node1 = node1!.next
                } else {
                    tmpList.next = node2
                    node2 = node2!.next
                }
            } else if node1 == nil {
                tmpList.next = node2
                break
            } else {
                tmpList.next = node1
                break
            }
            tmpList = tmpList.next ?? ListNode(0)
        }
        return returnList.next
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


var r = s.mergeTwoLists(l4, l44)
r!.dump()

