
class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var result: ListNode = ListNode(0)
        let tmpResult = result
        var flag = 0, sum = 0, tmpl1 = l1, tmpl2 = l2;
        while (tmpl1 != nil) || (tmpl2 != nil) {
            let node = ListNode(0)
            sum = (tmpl1?.val ?? 0) + (tmpl2?.val ?? 0) + flag
            if (sum > 9) {
                sum = sum%10
                flag = 1
            } else {
                flag = 0
            }
            node.val = sum
            node.next = nil
            
            result.next = node
            result = (result.next)!
            
            tmpl1 = tmpl1?.next
            tmpl2 = tmpl2?.next
        }
        
        if flag == 1 {
            result.next = ListNode(1)
        }
        
        return tmpResult.next
    }
}

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

let s = Solution()
var a1 = ListNode(5)
var a2 = ListNode(5)
var r = s.addTwoNumbers(a1, a2)
print("\(r?.val ?? -1) \(r?.next?.val ?? -1) ") // 0 1
