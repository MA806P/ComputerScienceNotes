

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
    func isPalindrome(_ head: ListNode?) -> Bool {
        if head == nil || head!.next == nil { return true }
        
        var nodes = [Int]()
        var next = head
        while next != nil {
            nodes.append(next!.val)
            next = next!.next
        }
        
        var start = 0, end = nodes.count-1
        while start < end {
            if (nodes[start] != nodes[end]) {
                return false
            }
            start += 1; end -= 1;
        }
        
        return true
    }
}


var l1 = ListNode(1)
 var l2 = ListNode(2)
 l2.next = l1
 var l3 = ListNode(2)
 l3.next = l2
 var l4 = ListNode(3)
 l4.next = l3
l4.dump()
print("----")


let s = Solution()
print(s.isPalindrome(l4))

